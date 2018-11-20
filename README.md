# iot-arduino-ioexpander-esp8266-controller-twi

- [browser page](#browser-page)
- [requirements](#requirements)
- [features](#features)
- [setup](#setup)
- [api ( esp8266 controller )](#api--esp8266-controller-)
- [api ( arduino nano slave )](#api--arduino-nano-slave-)
  
arduino nano as ioexpander controlled by esp8266 through TWI

## browser page

<img src="doc/home.gif" width=600/>

## requirements

- esp8266 nodemcu
- arduino nano V3

## setup

- [schematics](https://easyeda.com/editor#id=|676ad221579b4190a2b0e6b3f3755e87)

![img](doc/schematics.png)

## features

- imagemap of arduino nano ports
- index.htm, app.js, image.png served by esp8266 ( encoded into flash by [gen-h](esp8266-controller-twi/gen-h) )
- scalable TWI slave devices

## api ( esp8266 controller )

| **api** | **description** | **result example** |
|---|---|---|
| `/api/scan` | list of twi slave devices addresses (dec) | `[8,19]` |
| `/api/getportmode/addr` | retrieve port mode 0=input, 1=output, 2=input_pullup of slave at `addr` ports | `[{ "port": "D2", "mode": 0 },...,{ "port": "A3", "mode": 0 }]` |

## api ( arduino nano slave )
