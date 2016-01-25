/*
 * KeyFob.h
 *
 *  Created on: Aug 17, 2015
 *      Author: Travis Elliott
 */
#include "spark_wiring.h"
#include "spark_wiring_interrupts.h"
#include "spark_wiring_usbserial.h"
#include "spark_wiring_usartserial.h"

class KeyFob{
public:
	//Constructor
	KeyFob(void);
	void evalFob();

	int recentFobID = 0;
	int recentButton = 0;
	int recentAction = 0;

	static const int button1press = 0;
	static const int button1release = 1;
	static const int button2press = 2;
	static const int button2release = 3;
	static const int button3press = 4;
	static const int button3release = 5;
	static const int button4press = 6;
	static const int button4release = 7;
	static const int button5press = 8;
	static const int button5release = 9;
	static const int button6press = 10;
	static const int button6release = 11;
	static const int button7press = 12;
	static const int button7release = 13;
	static const int button8press = 14;
	static const int button8release = 15;



private:
	int previousStatus = 0;
};
