#ifndef ARDUPY_ADS1115_H
#define ARDUPY_ADS1115_H
/**************************************************************************
    I2C ADDRESS/BITS
**************************************************************************/
#define ADS1115_GND_ADDRESS (0x48) 
typedef enum
{
    channel0 = 0,
    channel1 ,
    channel2 ,
    channel3 ,
    channel01 ,
    channel03 ,
    channel13 ,
    channel23
} channel_t;
#ifdef __cplusplus
extern "C"
{
#endif
#include "py/objtype.h"
#include "shared-bindings/util.h"
    void common_hal_ads1115_construct(abstract_module_t * self,uint8_t addr);
    void common_hal_ads1115_deinit(abstract_module_t * self);
    void common_hal_ads1115_setOperateMode(abstract_module_t * self , uint16_t operateMode);
    void common_hal_ads1115_setOperateStaus(abstract_module_t * self , uint16_t OperateStaus);
    void common_hal_ads1115_setPGAGain(abstract_module_t * self,uint16_t PGAGain);
    void common_hal_ads1115_setSampleRate(abstract_module_t * self,uint16_t SampleRate);
    void common_hal_ads1115_setInputMux(abstract_module_t * self,uint16_t InputMux);
    int16_t common_hal_ads1115_getConversionResults(abstract_module_t * self,channel_t channel);
    void common_hal_ads1115_setCompaMode(abstract_module_t * self,uint16_t CompaMode);
    void common_hal_ads1115_setCompaPolarity(abstract_module_t * self,uint16_t CompaPolarity);
    void common_hal_ads1115_setCompaLatching(abstract_module_t * self,uint16_t CompaLatching);
    void common_hal_ads1115_setCompaQueue(abstract_module_t * self,uint16_t CompaQueue);
    void common_hal_ads1115_setLowThreshold(abstract_module_t * self,uint16_t threshold);
    void common_hal_ads1115_setHighThreshold(abstract_module_t * self,uint16_t threshold);
#ifdef __cplusplus
}
#endif

#endif