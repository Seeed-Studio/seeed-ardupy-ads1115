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

#include "py/mphal.h"
#include "py/nlr.h"
#include "py/objtype.h"
#include "py/runtime.h"
#include "py/obj.h"
#include "shared-bindings/util.h"
#include "wrapper_ardupy_ads1115_hal.h"

extern const mp_obj_type_t grove_ads1115_type;

m_generic_make(ads1115) {
    abstract_module_t * self = new_abstruct_module(type);
    mp_arg_check_num(n_args, n_kw, 0, 1, false);
    uint8_t addr = ADS1115_GND_ADDRESS;
    if (n_args == 1)
    {
        addr = mp_obj_get_int(args[0]);
        if ( (addr | 0x4A) != addr )
        {
            mp_raise_ValueError("only 0x48,0x49,0x4A,0x4B support!");
        }
    }    
    common_hal_ads1115_construct(self,addr);
    return self;
}

mp_obj_t ads1115_setOperateMode(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t operateMode = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setOperateMode(self,operateMode);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setOperateMode_obj , 1 , ads1115_setOperateMode);

mp_obj_t ads1115_setPGAGain(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t PGAGain = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setPGAGain(self,PGAGain);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setPGAGain_obj , 1 , ads1115_setPGAGain);

mp_obj_t ads1115_setOperateStaus(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t OperateStaus = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setOperateStaus(self,OperateStaus);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setOperateStaus_obj , 1 , ads1115_setOperateStaus);


mp_obj_t ads1115_setSampleRate(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t SampleRate = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setSampleRate(self,SampleRate);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setSampleRate_obj , 1 , ads1115_setSampleRate);

mp_obj_t ads1115_setInputMux(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t InputMux = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setInputMux(self,InputMux);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setInputMux_obj , 1 , ads1115_setInputMux);

mp_obj_t ads1115_setCompaMode(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t CompaMode = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setCompaMode(self,CompaMode);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setCompaMode_obj , 1 , ads1115_setCompaMode);

mp_obj_t ads1115_setCompaPolarity(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t CompaPolarity = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setCompaPolarity(self,CompaPolarity);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setCompaPolarity_obj , 1 , ads1115_setCompaPolarity);

mp_obj_t ads1115_setCompaLatching(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t CompaLatching = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setCompaLatching(self,CompaLatching);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setCompaLatching_obj , 1 , ads1115_setCompaLatching);

mp_obj_t ads1115_setCompaQueue(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t CompaQueue = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setCompaQueue(self,CompaQueue);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setCompaQueue_obj , 1 , ads1115_setCompaQueue);

mp_obj_t ads1115_setLowThreshold(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t threshold = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setLowThreshold(self,threshold);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setLowThreshold_obj , 1 , ads1115_setLowThreshold);

mp_obj_t ads1115_setHighThreshold(size_t n_args, const mp_obj_t *pos_args, mp_map_t *kw_args){
    abstract_module_t *self = (abstract_module_t *)pos_args[0];
    uint16_t threshold = mp_obj_get_int(pos_args[1]);
    common_hal_ads1115_setHighThreshold(self,threshold);
    return mp_const_none;
}
MP_DEFINE_CONST_FUN_OBJ_KW(ads1115_setHighThreshold_obj , 1 , ads1115_setHighThreshold);

void ads1115_obj_attr(mp_obj_t self_in, qstr attr, mp_obj_t *dest){
    abstract_module_t * self = (abstract_module_t *)self_in;
    int value;
    if (dest[0] == MP_OBJ_NULL){
        if(attr == MP_QSTR_channel0){
            value = common_hal_ads1115_getConversionResults(self,channel0);
        }
        else if(attr == MP_QSTR_channel1){
            value = common_hal_ads1115_getConversionResults(self,channel1);
        }
        else if(attr == MP_QSTR_channel2){
            value = common_hal_ads1115_getConversionResults(self,channel2);
        }
        else if(attr == MP_QSTR_channel3){
            value = common_hal_ads1115_getConversionResults(self,channel3);
        }
        else if(attr == MP_QSTR_channel01){
            value = common_hal_ads1115_getConversionResults(self,channel01);
        }
        else if(attr == MP_QSTR_channel03){
            value = common_hal_ads1115_getConversionResults(self,channel03);
        }
        else if(attr == MP_QSTR_channel13){
            value = common_hal_ads1115_getConversionResults(self,channel13);
        }
        else if(attr == MP_QSTR_channel23){
            value = common_hal_ads1115_getConversionResults(self,channel23);
        }
        dest[0] = mp_obj_new_float(value);
    }
    generic_method_lookup(self_in, attr, dest);
}   

const mp_rom_map_elem_t ads1115_locals_dict_table[] = {
    // instance methods
    { MP_ROM_QSTR(MP_QSTR_deinit),    MP_ROM_PTR(&ads1115_deinit_obj) },
    { MP_ROM_QSTR(MP_QSTR___enter__), MP_ROM_PTR(&default___enter___obj) },
    { MP_ROM_QSTR(MP_QSTR___exit__),  MP_ROM_PTR(&ads1115_obj___exit___obj) },
    { MP_ROM_QSTR(MP_QSTR_setOperateMode), MP_ROM_PTR(&ads1115_setOperateMode_obj) },
    { MP_ROM_QSTR(MP_QSTR_setOperateStaus), MP_ROM_PTR(&ads1115_setOperateStaus_obj) },
    { MP_ROM_QSTR(MP_QSTR_setPGAGain), MP_ROM_PTR(&ads1115_setPGAGain_obj) },
    { MP_ROM_QSTR(MP_QSTR_setSampleRate), MP_ROM_PTR(&ads1115_setSampleRate_obj)},
    { MP_ROM_QSTR(MP_QSTR_setInputMux), MP_ROM_PTR(&ads1115_setInputMux_obj)},
    { MP_ROM_QSTR(MP_QSTR_setCompaMode), MP_ROM_PTR(&ads1115_setCompaMode_obj)},
    { MP_ROM_QSTR(MP_QSTR_setCompaPolarity), MP_ROM_PTR(&ads1115_setCompaPolarity_obj)},
    { MP_ROM_QSTR(MP_QSTR_setCompaLatching), MP_ROM_PTR(&ads1115_setCompaLatching_obj)},
    { MP_ROM_QSTR(MP_QSTR_setCompaQueue), MP_ROM_PTR(&ads1115_setCompaQueue_obj)},
    { MP_ROM_QSTR(MP_QSTR_setLowThreshold), MP_ROM_PTR(&ads1115_setLowThreshold_obj)},
    { MP_ROM_QSTR(MP_QSTR_setHighThreshold), MP_ROM_PTR(&ads1115_setHighThreshold_obj)}
};

MP_DEFINE_CONST_DICT(ads1115_locals_dict, ads1115_locals_dict_table);

const mp_obj_type_t grove_ads1115_type = {
    {&mp_type_type},
    .name = MP_QSTR_grove_ads1115,
    .make_new = ads1115_make_new,
    .locals_dict = (mp_obj_t)&ads1115_locals_dict,
    .attr = ads1115_obj_attr,
};
