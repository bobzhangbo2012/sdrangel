
///////////////////////////////////////////////////////////////////////////////////
// Copyright (C) 2018 Edouard Griffiths, F4EXB                                   //
//                                                                               //
// This program is free software; you can redistribute it and/or modify          //
// it under the terms of the GNU General Public License as published by          //
// the Free Software Foundation as version 3 of the License, or                  //
// (at your option) any later version.                                           //
//                                                                               //
// This program is distributed in the hope that it will be useful,               //
// but WITHOUT ANY WARRANTY; without even the implied warranty of                //
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the                  //
// GNU General Public License V3 for more details.                               //
//                                                                               //
// You should have received a copy of the GNU General Public License             //
// along with this program. If not, see <http://www.gnu.org/licenses/>.          //
///////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <errno.h>

#include "dsp/samplesinkfifo.h"
#include "airspyhfworker.h"

AirspyHFWorker *AirspyHFWorker::m_this = 0;

AirspyHFWorker::AirspyHFWorker(airspyhf_device_t* dev, SampleSinkFifo* sampleFifo, QObject* parent) :
	QObject(parent),
	m_running(false),
	m_dev(dev),
	m_convertBuffer(AIRSPYHF_BLOCKSIZE),
	m_sampleFifo(sampleFifo),
	m_samplerate(10),
	m_log2Decim(0),
    m_iqOrder(true)
{
    memset((char*) m_buf, 0, 2*AIRSPYHF_BLOCKSIZE*sizeof(qint16));
	m_this = this;
}

AirspyHFWorker::~AirspyHFWorker()
{
	stopWork();
	m_this = 0;
}

bool AirspyHFWorker::startWork()
{
    qDebug("AirspyThread::startWork");
	airspyhf_error rc = (airspyhf_error) airspyhf_start(m_dev, rx_callback, 0);

	if (rc == AIRSPYHF_SUCCESS)
	{
        m_running = (airspyhf_is_streaming(m_dev) != 0);
	}
	else
	{
		qCritical("AirspyHFFThread::run: failed to start Airspy HF Rx");
        m_running = false;
	}

    return m_running;
}

void AirspyHFWorker::stopWork()
{
	qDebug("AirspyThread::stopWork");
	airspyhf_error rc = (airspyhf_error) airspyhf_stop(m_dev);

	if (rc == AIRSPYHF_SUCCESS) {
		qDebug("AirspyHFFThread::run: stopped Airspy HF Rx");
	} else {
		qDebug("AirspyHFFThread::run: failed to stop Airspy HF Rx");
	}

	m_running = false;}

void AirspyHFWorker::setSamplerate(uint32_t samplerate)
{
	m_samplerate = samplerate;
}

void AirspyHFWorker::setLog2Decimation(unsigned int log2_decim)
{
	m_log2Decim = log2_decim;
}

//  Decimate according to specified log2 (ex: log2=4 => decim=16)
void AirspyHFWorker::callbackIQ(const float* buf, qint32 len)
{
	SampleVector::iterator it = m_convertBuffer.begin();

    switch (m_log2Decim)
    {
    case 0:
        m_decimatorsIQ.decimate1(&it, buf, len);
        break;
    case 1:
        m_decimatorsIQ.decimate2_cen(&it, buf, len);
        break;
    case 2:
        m_decimatorsIQ.decimate4_cen(&it, buf, len);
        break;
    case 3:
        m_decimatorsIQ.decimate8_cen(&it, buf, len);
        break;
    case 4:
        m_decimatorsIQ.decimate16_cen(&it, buf, len);
        break;
    case 5:
        m_decimatorsIQ.decimate32_cen(&it, buf, len);
        break;
    case 6:
        m_decimatorsIQ.decimate64_cen(&it, buf, len);
        break;
    default:
        break;
    }

	m_sampleFifo->write(m_convertBuffer.begin(), it);
}

void AirspyHFWorker::callbackQI(const float* buf, qint32 len)
{
	SampleVector::iterator it = m_convertBuffer.begin();

    switch (m_log2Decim)
    {
    case 0:
        m_decimatorsQI.decimate1(&it, buf, len);
        break;
    case 1:
        m_decimatorsQI.decimate2_cen(&it, buf, len);
        break;
    case 2:
        m_decimatorsQI.decimate4_cen(&it, buf, len);
        break;
    case 3:
        m_decimatorsQI.decimate8_cen(&it, buf, len);
        break;
    case 4:
        m_decimatorsQI.decimate16_cen(&it, buf, len);
        break;
    case 5:
        m_decimatorsQI.decimate32_cen(&it, buf, len);
        break;
    case 6:
        m_decimatorsQI.decimate64_cen(&it, buf, len);
        break;
    default:
        break;
    }

	m_sampleFifo->write(m_convertBuffer.begin(), it);
}

int AirspyHFWorker::rx_callback(airspyhf_transfer_t* transfer)
{
	qint32 nbIAndQ = transfer->sample_count * 2;

    if (m_this->m_iqOrder) {
    	m_this->callbackIQ((float *) transfer->samples, nbIAndQ);
    } else {
        m_this->callbackQI((float *) transfer->samples, nbIAndQ);
    }

    return 0;
}
