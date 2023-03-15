#pragma once

#include "SamplerI2S.h"

class SamplerMEMS : public SamplerI2S
{
private:
    i2s_pin_config_t m_i2sPins;
    bool m_fixSPH0645;

protected:
    void configureI2S();

public:
    SamplerMEMS(
        i2s_port_t i2s_port,
        i2s_pin_config_t &i2s_pins,
        i2s_config_t i2s_config,
        bool fixSPH0645 = true);
    virtual int read(int16_t *samples, int count);
};
