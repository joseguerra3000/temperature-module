Temperature Module
==================
Temperature module of small dimensions (approximately 45x25mm), compatible with arduino and digilent cerebot.
Useful for data acquisition systems based on microcontrollers (arduino, pic, etc.) and as a thermoresistor calibrator.
Able to use three temperature sensors at the same time:
  - LM35
  - AD22103
  - thermoresistor

![alt text](https://github.com/joseguerra3000/temperature-module/blob/master/KiCad%20Project/images/Modulo%20de%20Temperatura_3D_big.jpg)


How to use it
-------------
It only needs to be powered with +5V and +3.3V to measure temperatures greater thad 0°C with LM35 and AD22103 sensors. 
Optionally it can also be supplied with -5V to measure temperatures below 0°C with the LM35 sensor.
J3 is used as power switch for thermo-resistor, this allows it to be used with systems which reference is +5V or +3.3V
It offers three independent analog outputs, one for each sensor.

In addition, a library is included for use with arduino.
