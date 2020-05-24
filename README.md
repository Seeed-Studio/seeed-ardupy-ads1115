# Seeed-ArduPy-ads1115 [![Build Status](https://travis-ci.com/Seeed-Studio/seeed-ardupy-ads1115.svg?branch=master)](https://travis-ci.com/Seeed-Studio/seeed-ardupy-ads1115)

## Introduction

An ArduPy library for ADS1115 Ultra-Small, Low-Power, I2C-Compatible, 860-SPS, 16-Bit ADCs.ADC data can be obtained using IIC interface.

## How to binding with ArduPy

- Install [AIP](https://github.com/Seeed-Studio/ardupy-aip)
```shell
pip3 install aip
```
- Build firmware with Seeed ArduPy ads1115
```shell
aip install https://github.com/Seeed-Studio/seeed-ardupy-ads1115
aip build
```
- Flash new firmware to you ArduPy board
```shell
aip flash [Ardupy Bin PATH]
```
For more examples of using AIP, please refer to [AIP](https://github.com/Seeed-Studio/ardupy-aip).

## Usage

```python
from arduino import grove_ads1115
import time

ads = grove_ads1115()

while True:
    print ("The channel0 value is :", ads.channel0)
    print ("The channel1 value is :", ads.channel1)
    print ("The channel2 value is :", ads.channel2)
    print ("The channel3 value is :", ads.channel3)
    time.sleep(1)

```

## API Reference

- grove_ads1115(addr):void Instantiate an object

```python
ads = grove_ads1115(0x48)
# ads = grove_ads1115(0x49)
# ads = grove_ads1115(0x4A)
# ads = grove_ads1115(0x4B)
```

- setOperateMode(operateMode):void Set operate Mode

```python
ads.setOperateMode(0x0000) # Continuous conversion mode
# ads.setOperateMode(0x0100) # Power-down single-shot mode (default)
```

- setOperateStaus(operateStaus):void Set operate staus

```python
ads.setOperateStaus(0x0000)
# ads.setOperateStaus(0x8000) # conversion finish
```

- setPGAGain(PGAGain) :void Set PGA gain

```python
ads.setPGAGain(0x0000) # 2/3x gain  +/- 0.256V  1 bit =  0.0078125mV
# ads.setPGAGain(0x0200) # 1x gain   +/- 4.096V  1 bit =  0.125mV
# ads.setPGAGain(0x0400) # 2x gain   +/- 2.048V  1 bit =  0.0625mV
# ads.setPGAGain(0x0600) # 4x gain   +/- 1.024V  1 bit =  0.03125mV
# ads.setPGAGain(0x0800) # 8x gain   +/- 0.512V  1 bit =  0.015625mV
# ads.setPGAGain(0x0E00) # 16x gain  +/- 0.256V  1 bit =  0.0078125mV
```

- setInputMux(InputMux):void Set Input Multiplexer

```python
ads.setInputMux(0x0000) # P = AIN0, N = AIN1(default)
# ads.setSampleRate(0x1000) # P = AIN0, N = AIN3
# ads.setSampleRate(0x2000) # P = AIN1, N = AIN3
# ads.setSampleRate(0x3000) # P = AIN2, N = AIN3
# ads.setSampleRate(0x4000) # P = AIN0, N = GND
# ads.setSampleRate(0x5000) # P = AIN0, N = GND
# ads.setSampleRate(0x6000) # P = AIN0, N = GND
# ads.setSampleRate(0x7000) # P = AIN0, N = GND
```

- setSampleRate(SampleRate):void Set sample rate

```python
ads.setSampleRate(0x0000)  # 8 SPS
ads.setSampleRate(0x0020)  # 16 SPS
ads.setSampleRate(0x0040)  # 32 SPS
ads.setSampleRate(0x0060)  # 64 SPS
ads.setSampleRate(0x0080)  # 128 SPS
ads.setSampleRate(0x00A0)  # 250 SPS
ads.setSampleRate(0x00C0)  # 475 SPS
ads.setSampleRate(0x00E0)  # 860 SPS
```

- channel0 : int  get channel0 data

```python 
value = ads.channel0
```

- channel1 : int  get channel1 data

```python 
value = ads.channel1
```

- channel2 : int  get channel2 data

```python 
value = ads.channel2
```

- channel3 : int  get channel3 data

```python 
value = ads.channel3
```

- channel01 : int  get channel01 data

```python 
value = ads.channel01
```

- channel03 : int  get channel03 data

```python 
value = ads.channel03
```

- channel13 : int  get channel13 data

```python 
value = ads.channel13
```

- channel23 : int  get channel23 data

```python 
value = ads.channel23
```


This software is written by seeed studio<br>
and is licensed under [The MIT License](http://opensource.org/licenses/mit-license.php). Check License.txt for more information.<br>

Contributing to this software is warmly welcomed. You can do this basically by<br>
[forking](https://help.github.com/articles/fork-a-repo), committing modifications and then [pulling requests](https://help.github.com/articles/using-pull-requests) (follow the links above<br>
for operating guide). Adding change log and your contact into file header is encouraged.<br>
Thanks for your contribution.

Seeed Studio is an open hardware facilitation company based in Shenzhen, China. <br>
Benefiting from local manufacture power and convenient global logistic system, <br>
we integrate resources to serve new era of innovation. Seeed also works with <br>
global distributors and partners to push open hardware movement.<br>
