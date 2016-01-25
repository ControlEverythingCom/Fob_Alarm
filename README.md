# About

This Library serves as supporting firmware for our Article Fob Alarm in which we monitor a Key Fob interface module connected to the Particle Photon.  We use the Key Fob interface module to monitor the button on a single button remote.  When this button is pressed we submit an event to the Particle Cloud, upon success of this event submission to Particle's cloud we pulse the buzzer once letting the KeyFob user know that the alarm has been submitted successfully.  IFTTT monitors this event and sends a notification to the Alarm monitor's phone letting them know a user has pushed the button at the remote site.  The alarm monitor can then press an IFTTT do button to acknoledge this alarm by pulsing the buzzer twice on the fob interface end, this lets the KeyFob user know that the remote user has been informed of the alarm.
###Developer information
NCD has been designing and manufacturing computer control products since 1995.  We have specialized in hardware design and manufacturing of Relay controllers for 20 years.  We pride ourselves as being the industry leader of computer control relay products.  Our products are proven reliable and we are very excited to support Particle.  For more information on NCD please visit www.controlanything.com

###Requirements
- [Key Fob Receiver Overlay Shield for Particle Photon and Particle Electron] [fobInterface]
- [1 Button Key Fob Remote][1ButtonFobRemote]
- [PCA9536 I²C Digital 3-Channel Input Output with Buzzer I²C Mini Module] [buzzerMiniModule]
- [I²C Shield for Particle Photon] [i2CShieldPhoton]
- [Particle Photon module][photonModule](Application is also compatible with Spark Core modules)
- Knowledge base for developing and programming with Particle Core/Photon modules.

### Version
1.0.0

### How to use this library

This is a fully implemented Library and is intended to be used as is.  Users may modify and use the library in any way they see fit.  The intended use is to search Community Libraries under Particle's WEB IDE for Fob_Alarm.  Once found make sure the key-fob-buzzer-article.ino tab is selected, then click Use This Example button on the left.  Then flash the firmware into your Particle Module.  For more information see [Particle's documentation] [sparkIncludeLibrary].

### What it does

This application monitors Key Fob remote button presses through the Key Fob interface module connected to the Particle Photon module.  If it detects that button 5 was pressed(this physically is the only button on the single button key fob remote) it publishes an Event named eventAlarm to the Particle Cloude with the data Alarm.  Once this event is successfully published to the Particle cloud it will pulse the buzzer letting the user who pressed the Key Fob button know that the alarm was sent successfully.  The intention of this application is that another user who monitors this alarm will use IFTTT to trigger a notification on their smart phone to let them know there is an alarm.  They would then use the IFTTT Do button app to call a function on the controller which serves to acknoledge reception of the alarm message by pulsing the on board buzzer twice letting the user who pressed the Key Fob button know that the remote user monitoring the alarm has acknowledged the alarm.

License
----

GNU
[sparkIncludeLibrary]:https://docs.particle.io/guide/getting-started/build/photon/
[fobInterface]:https://www.controleverything.com/content/Key-Fob?sku=PKFR
[1ButtonFobRemote]:https://www.controleverything.com/content/Key-Fobs?sku=OTX-418-HH-KF1-MS
[buzzerMiniModule]:https://www.controleverything.com/content/Digital-IO?sku=PCA9536_I2CBZ
[i2CShieldPhoton]:https://www.controleverything.com/content/I2C-Master?sku=SPARKI2C
[photonModule]:https://www.controleverything.com/content/Particle-Dev-Kit?sku=particle_photon
