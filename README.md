# About

In this article we will setup a Particle Photon module to monitor temperature throught the SI7020-A20 temperature/humidity mini module sensor.  Based on readings from this sensor we will turn on a buzzer alarm to warn the user of a high or low temperature.

This Library is intended to be used in conjunction with the Control Anything article Temperature_Alarm.

The intention of this library is to make use of the SI7020-A20 Temperature/Humidity Sensor and PCA9536_I2CBZ I²C Mini Modules with Particle development web IDE as simple as possible for users.
###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit www.controlanything.com

###Requirements
- SI7020-A20 I²C Humidity and Temperature Sensor ±4%RH ±.4°C I²C Mini Module
- PCA9536 I²C Digital 3-Channel Input Output with Buzzer I²C Mini Module
- I²C Shield for Particle Photon
- Particle Core/Photon module
- Knowledge base for developing and programming with Particle Core/Photon modules.

### Version
1.0.0

### How to use this library

This is a fully implemented Library and is intended to be used as is.  Users may modify and use the library in any way they see fit.  The intended use is to search Community Libraries under Particle's WEB IDE for Temperature_Alarm.  Once found make sure the application tab is selected, then click Use This Example button on the left.  Then flash the firmware into your Particle Module.  For more information see [Particle's documentation] [sparkIncludeLibrary].

### What it does

This library does two things.  It monitors the temperature using the SI7020-A20 temperature sensor.  Secondly it turns a buzzer on to indicate an alarm situation.  The alarm can trip when a temperature gets too high or too low. 

The firmware publishes a function called AlarmLimit which takes a string argument.  This argument sets the alarm limit to turn the buzzer on.  The formwat for the alarm is for example: 
high;200.00
low;32.00
The first part of the argument indicates whether the alarm should trip when the temperature is above a limit or below a limit.  If high is passed as the first part the alarm will turn on when the temperature gets too high.  If low is passed as the first part the alarm will turn off when the temperature gets too low.
The second part of the argument is the temperature limit.  This should be a decimal formatted temperature such as 75.00
The first and second part of the arguments should always be seperated by a semi-colon as shown in the examples above.

This firmware also publishes the current temperature as a variable on Particle's server.

License
----

GNU
[sparkIncludeLibrary]:https://docs.particle.io/guide/getting-started/build/photon/
