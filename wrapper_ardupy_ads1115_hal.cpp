/**
 * The MIT License (MIT)
 *
 * Author: Junjie Chen (595355940@qq.com)
 *
 * Copyright (C) 2020  Seeed Technology Co.,Ltd.
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included in
 * all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE 
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */


#include "Seeed_Arduino_ADS1115/src/ADS1115.h"
extern "C"{
#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "shared-bindings/util.h"
}


#define  ads1115  (*(ADS1115<TwoWire>  *)self->module)
void * operator new(size_t, void *);

extern "C"{
    void common_hal_ads1115_construct(abstract_module_t * self,uint8_t addr){
#ifdef WIO_TERMINAL    
        self->module = new(m_new_obj(ADS1115<TwoWire>)) ADS1115<TwoWire>(Wire1);
#else
        self->module = new(m_new_obj(ADS1115<TwoWire>)) ADS1115<TwoWire>(Wire);
#endif
        ads1115.begin(addr);
    }
    void common_hal_ads1115_deinit(abstract_module_t * self){
        ads1115.~ADS1115<TwoWire>();
    }
    void common_hal_ads1115_setOperateMode(abstract_module_t * self , uint16_t operateMode){
        ads1115.setOperateMode(operateMode);
    }
    void common_hal_ads1115_setOperateStaus(abstract_module_t * self , uint16_t OperateStaus){
        ads1115.setOperateStaus(OperateStaus);
    }    
    void common_hal_ads1115_setPGAGain(abstract_module_t * self,uint16_t PGAGain){
        ads1115.setPGAGain(PGAGain);
    }
    void common_hal_ads1115_setSampleRate(abstract_module_t * self,uint16_t SampleRate){
        ads1115.setSampleRate(SampleRate);
    }    
    void common_hal_ads1115_setInputMux(abstract_module_t * self,uint16_t InputMux){
        ads1115.setInputMux(InputMux);
    }    
    int16_t common_hal_ads1115_getConversionResults(abstract_module_t * self,channel_t channel){
        return ads1115.getConversionResults(channel);
    }     
    void common_hal_ads1115_setCompaMode(abstract_module_t * self,uint16_t CompaMode){
        ads1115.setCompaMode(CompaMode);
    } 
    void common_hal_ads1115_setCompaPolarity(abstract_module_t * self,uint16_t CompaPolarity){
        ads1115.setCompaPolarity(CompaPolarity);
    }     
    void common_hal_ads1115_setCompaLatching(abstract_module_t * self,uint16_t CompaLatching){
        ads1115.setCompaLatching(CompaLatching);
    }       
    void common_hal_ads1115_setCompaQueue(abstract_module_t * self,uint16_t CompaQueue){
        ads1115.setCompaQueue(CompaQueue);
    }      
    void common_hal_ads1115_setLowThreshold(abstract_module_t * self,uint16_t threshold){
        ads1115.setLowThreshold(threshold);
    } 
    void common_hal_ads1115_setHighThreshold(abstract_module_t * self,uint16_t threshold){
        ads1115.setHighThreshold(threshold);
    } 
}