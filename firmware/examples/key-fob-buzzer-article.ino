// This #include statement was automatically added by the Particle IDE.
#include "Fob_Alarm/KeyFob.h"

// This #include statement was automatically added by the Particle IDE.
#include "Fob_Alarm/I2CBZ.h"

//Class Objects
I2CBZ buzzer;
KeyFob fob;

bool checkFob = false;
int alarmReceiveConfirm(String data);

void setup() {
    //Setup communication to KeyFob interface module
    attachInterrupt(A3, evalFob, CHANGE);
    Serial1.begin(9600);
    //Initialize buzzer
    if(!buzzer.initialize(0)){
        Serial.println("failed to initialize buzzer");
    }
    Particle.function("ConfirmAlarm", alarmReceiveConfirm);
}

void loop() {
    //If an interrupt has fired on A3 which is connected to the fob module then a button has been pressed or released so we need to determine what button was pressed or released.
    if(checkFob){
		checkFob = false;
		delay(10);
		fob.evalFob();
		String action;
		switch(fob.recentAction){
		case(fob.button1press):
			Serial.println("Button 1 pressed");
		    action = "Button1Press";
		break;
		case(fob.button2press):
			Serial.println("Button 2 pressed");
		    action = "Button2Press";
		break;
		case(fob.button3press):
			Serial.println("Button 3 pressed");
		    action = "Button3Press";
		break;
		case(fob.button4press):
			Serial.println("Button 4 pressed");
		    action = "Button4Press";
		break;
		case(fob.button5press):
			Serial.println("Button 5 pressed");
		    action = "Button5Press";
		break;
		case(fob.button6press):
			Serial.println("Button 6 pressed");
		    action = "Button6Press";
		break;
		case(fob.button7press):
			Serial.println("Button 7 pressed");
		    action = "Button7Press";
		break;
		case(fob.button8press):
			Serial.println("Button 8 pressed");
		    action = "Button8Press";
		break;
		case(fob.button1release):
			Serial.println("Button 1 released");
		    action = "Button1Release";
		break;
		case(fob.button2release):
			Serial.println("Button 2 released");
		    action = "Button2Release";
		break;
		case(fob.button3release):
			Serial.println("Button 3 released");
	    	action = "Button3Release";
		break;
		case(fob.button4release):
			Serial.println("Button 4 released");
		    action = "Button4Release";
		break;
		case(fob.button5release):
			Serial.println("Button 5 released");
		    action = "Button5Release";
		break;
		case(fob.button6release):
			Serial.println("Button 6 released");
		    action = "Button6Release";
		break;
		case(fob.button7release):
			Serial.println("Button 7 released");
		action = "Button7Release";
		break;
		case(fob.button8release):
			Serial.println("Button 8 released");
		    action = "Button8Release";
		break;
		}
		//Publish what happened to the Particle cloud and make sure the event publish to the cloud worked.  We are monitoring a 1 button key fob remote.
		//This button mounts as button 5 in software so we monitor Button5Press.
		if(action.equalsIgnoreCase("Button5Press")){
		    if(Particle.publish("eventAlarm","Alarm",60,PRIVATE)){
		        //Let the user know the alarm has been sent
		        buzzer.buzzer(1);
		        delay(300);
		        buzzer.buzzer(0);
		    }
		}
		

	}
}

void evalFob(){
	Serial.println("Fob button pressed");
	checkFob = true;
}

int alarmReceiveConfirm(String data){
    //Two pulses of the alarm let the user know the remote user received and acknowledged the alarm.
    buzzer.buzzer(1);
    delay(100);
    buzzer.buzzer(0);
    delay(200);
    buzzer.buzzer(1);
    delay(100);
    buzzer.buzzer(0);
    return 1;
}