/**
 * SDRangel
 * This is the web REST/JSON API of SDRangel SDR software. SDRangel is an Open Source Qt5/OpenGL 3.0+ (4.3+ in Windows) GUI and server Software Defined Radio and signal analyzer in software. It supports Airspy, BladeRF, HackRF, LimeSDR, PlutoSDR, RTL-SDR, SDRplay RSP1 and FunCube    ---   Limitations and specifcities:    * In SDRangel GUI the first Rx device set cannot be deleted. Conversely the server starts with no device sets and its number of device sets can be reduced to zero by as many calls as necessary to /sdrangel/deviceset with DELETE method.   * Preset import and export from/to file is a server only feature.   * Device set focus is a GUI only feature.   * The following channels are not implemented (status 501 is returned): ATV and DATV demodulators, Channel Analyzer NG, LoRa demodulator   * The device settings and report structures contains only the sub-structure corresponding to the device type. The DeviceSettings and DeviceReport structures documented here shows all of them but only one will be or should be present at a time   * The channel settings and report structures contains only the sub-structure corresponding to the channel type. The ChannelSettings and ChannelReport structures documented here shows all of them but only one will be or should be present at a time    --- 
 *
 * OpenAPI spec version: 4.14.0
 * Contact: f4exb06@gmail.com
 *
 * NOTE: This class is auto generated by the swagger code generator program.
 * https://github.com/swagger-api/swagger-codegen.git
 * Do not edit the class manually.
 */

/*
 * SWGATVDemodSettings.h
 *
 * ATVDemod
 */

#ifndef SWGATVDemodSettings_H_
#define SWGATVDemodSettings_H_

#include <QJsonObject>


#include <QString>

#include "SWGObject.h"
#include "export.h"

namespace SWGSDRangel {

class SWG_API SWGATVDemodSettings: public SWGObject {
public:
    SWGATVDemodSettings();
    SWGATVDemodSettings(QString* json);
    virtual ~SWGATVDemodSettings();
    void init();
    void cleanup();

    virtual QString asJson () override;
    virtual QJsonObject* asJsonObject() override;
    virtual void fromJsonObject(QJsonObject &json) override;
    virtual SWGATVDemodSettings* fromJson(QString &jsonString) override;

    qint32 getLineTimeFactor();
    void setLineTimeFactor(qint32 line_time_factor);

    qint32 getTopTimeFactor();
    void setTopTimeFactor(qint32 top_time_factor);

    qint32 getFpsIndex();
    void setFpsIndex(qint32 fps_index);

    qint32 getHalfImage();
    void setHalfImage(qint32 half_image);

    qint32 getRfBandwidthFactor();
    void setRfBandwidthFactor(qint32 rf_bandwidth_factor);

    qint32 getOppBandwidthFactor();
    void setOppBandwidthFactor(qint32 opp_bandwidth_factor);

    qint32 getNbLinesIndex();
    void setNbLinesIndex(qint32 nb_lines_index);

    qint32 getIntFrequencyOffset();
    void setIntFrequencyOffset(qint32 int_frequency_offset);

    qint32 getEnmModulation();
    void setEnmModulation(qint32 enm_modulation);

    float getFltRfBandwidth();
    void setFltRfBandwidth(float flt_rf_bandwidth);

    float getFltRfOppBandwidth();
    void setFltRfOppBandwidth(float flt_rf_opp_bandwidth);

    qint32 getBlnFftFiltering();
    void setBlnFftFiltering(qint32 bln_fft_filtering);

    qint32 getBlndecimatorEnable();
    void setBlndecimatorEnable(qint32 blndecimator_enable);

    float getFltBfoFrequency();
    void setFltBfoFrequency(float flt_bfo_frequency);

    float getFmDeviation();
    void setFmDeviation(float fm_deviation);

    qint32 getAmScalingFactor();
    void setAmScalingFactor(qint32 am_scaling_factor);

    qint32 getAmOffsetFactor();
    void setAmOffsetFactor(qint32 am_offset_factor);

    qint32 getIntSampleRate();
    void setIntSampleRate(qint32 int_sample_rate);

    qint32 getEnmAtvStandard();
    void setEnmAtvStandard(qint32 enm_atv_standard);

    qint32 getIntNumberOfLines();
    void setIntNumberOfLines(qint32 int_number_of_lines);

    float getFltLineDuration();
    void setFltLineDuration(float flt_line_duration);

    float getFltTopDuration();
    void setFltTopDuration(float flt_top_duration);

    float getFltFramePerS();
    void setFltFramePerS(float flt_frame_per_s);

    float getFltRatioOfRowsToDisplay();
    void setFltRatioOfRowsToDisplay(float flt_ratio_of_rows_to_display);

    float getFltVoltLevelSynchroTop();
    void setFltVoltLevelSynchroTop(float flt_volt_level_synchro_top);

    float getFltVoltLevelSynchroBlack();
    void setFltVoltLevelSynchroBlack(float flt_volt_level_synchro_black);

    qint32 getBlnHSync();
    void setBlnHSync(qint32 bln_h_sync);

    qint32 getBlnVSync();
    void setBlnVSync(qint32 bln_v_sync);

    qint32 getBlnInvertVideo();
    void setBlnInvertVideo(qint32 bln_invert_video);

    qint32 getIntVideoTabIndex();
    void setIntVideoTabIndex(qint32 int_video_tab_index);

    qint32 getIntTvSampleRate();
    void setIntTvSampleRate(qint32 int_tv_sample_rate);

    qint32 getIntNumberSamplePerLine();
    void setIntNumberSamplePerLine(qint32 int_number_sample_per_line);

    qint32 getRgbColor();
    void setRgbColor(qint32 rgb_color);

    QString* getTitle();
    void setTitle(QString* title);

    QString* getUdpAddress();
    void setUdpAddress(QString* udp_address);

    qint32 getUdpPort();
    void setUdpPort(qint32 udp_port);


    virtual bool isSet() override;

private:
    qint32 line_time_factor;
    bool m_line_time_factor_isSet;

    qint32 top_time_factor;
    bool m_top_time_factor_isSet;

    qint32 fps_index;
    bool m_fps_index_isSet;

    qint32 half_image;
    bool m_half_image_isSet;

    qint32 rf_bandwidth_factor;
    bool m_rf_bandwidth_factor_isSet;

    qint32 opp_bandwidth_factor;
    bool m_opp_bandwidth_factor_isSet;

    qint32 nb_lines_index;
    bool m_nb_lines_index_isSet;

    qint32 int_frequency_offset;
    bool m_int_frequency_offset_isSet;

    qint32 enm_modulation;
    bool m_enm_modulation_isSet;

    float flt_rf_bandwidth;
    bool m_flt_rf_bandwidth_isSet;

    float flt_rf_opp_bandwidth;
    bool m_flt_rf_opp_bandwidth_isSet;

    qint32 bln_fft_filtering;
    bool m_bln_fft_filtering_isSet;

    qint32 blndecimator_enable;
    bool m_blndecimator_enable_isSet;

    float flt_bfo_frequency;
    bool m_flt_bfo_frequency_isSet;

    float fm_deviation;
    bool m_fm_deviation_isSet;

    qint32 am_scaling_factor;
    bool m_am_scaling_factor_isSet;

    qint32 am_offset_factor;
    bool m_am_offset_factor_isSet;

    qint32 int_sample_rate;
    bool m_int_sample_rate_isSet;

    qint32 enm_atv_standard;
    bool m_enm_atv_standard_isSet;

    qint32 int_number_of_lines;
    bool m_int_number_of_lines_isSet;

    float flt_line_duration;
    bool m_flt_line_duration_isSet;

    float flt_top_duration;
    bool m_flt_top_duration_isSet;

    float flt_frame_per_s;
    bool m_flt_frame_per_s_isSet;

    float flt_ratio_of_rows_to_display;
    bool m_flt_ratio_of_rows_to_display_isSet;

    float flt_volt_level_synchro_top;
    bool m_flt_volt_level_synchro_top_isSet;

    float flt_volt_level_synchro_black;
    bool m_flt_volt_level_synchro_black_isSet;

    qint32 bln_h_sync;
    bool m_bln_h_sync_isSet;

    qint32 bln_v_sync;
    bool m_bln_v_sync_isSet;

    qint32 bln_invert_video;
    bool m_bln_invert_video_isSet;

    qint32 int_video_tab_index;
    bool m_int_video_tab_index_isSet;

    qint32 int_tv_sample_rate;
    bool m_int_tv_sample_rate_isSet;

    qint32 int_number_sample_per_line;
    bool m_int_number_sample_per_line_isSet;

    qint32 rgb_color;
    bool m_rgb_color_isSet;

    QString* title;
    bool m_title_isSet;

    QString* udp_address;
    bool m_udp_address_isSet;

    qint32 udp_port;
    bool m_udp_port_isSet;

};

}

#endif /* SWGATVDemodSettings_H_ */
