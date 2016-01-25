/*
 * KeyFob.cpp
 *
 *  Created on: Aug 17, 2015
 *      Author: Travis Elliott
 */
#include "KeyFob.h"

//KeyFob Buttons
int kfb1 = A0;
int kfb2 = A1;
int kfb3 = D2;
int kfb4 = D3;
int kfb5 = D4;
int kfb6 = D5;
int kfb7 = D6;
int kfb8 = D7;

//RSSI
int rssiPin = A2;
//KeyFob Interrupt function

KeyFob::KeyFob(){
}

void KeyFob::evalFob(){
	recentFobID = Serial1.read();

	int newStatus = 0;

	if(digitalRead(kfb1) == 1)	{
		newStatus = newStatus | 1;
	}else{
		newStatus = newStatus & ~1;
	}
	if(digitalRead(kfb2) == 1)	{
		newStatus = newStatus | 2;
	}else{
		newStatus = newStatus & ~2;
	}
	if(digitalRead(kfb3) == 1)	{
		newStatus = newStatus | 4;
	}else{
		newStatus = newStatus & ~4;
	}
	if(digitalRead(kfb4) == 1)	{
		newStatus = newStatus | 8;
	}else{
		newStatus = newStatus & ~8;
	}
	if(digitalRead(kfb5) == 1)	{
		newStatus = newStatus | 16;
	}else{
		newStatus = newStatus & ~16;
	}
	if(digitalRead(kfb6) == 1)	{
		newStatus = newStatus | 32;
	}else{
		newStatus = newStatus & ~32;
	}
	if(digitalRead(kfb7) == 1)	{
		newStatus = newStatus | 64;
	}else{
		newStatus = newStatus & ~64;
	}
	if(digitalRead(kfb8) == 1)	{
		newStatus = newStatus | 128;
	}else{
		newStatus = newStatus & ~128;
	}

	//off
	if(newStatus < previousStatus){
		int statusChange = previousStatus - newStatus;
		if((statusChange & 1) == 1){
			recentAction = button1release;
		}
		if((statusChange & 2) == 2){
			recentAction = button2release;
		}
		if((statusChange & 4) == 4){
			recentAction = button3release;
		}
		if((statusChange & 8) == 8){
			recentAction = button4release;
		}
		if((statusChange & 16) == 16){
			recentAction = button5release;
		}
		if((statusChange & 32) == 32){
			recentAction = button6release;
		}
		if((statusChange & 64) == 64){
			recentAction = button7release;
		}
		if((statusChange & 128) == 128){
			recentAction = button8release;
		}

	}
	if(previousStatus < newStatus){
		int statusChange = newStatus - previousStatus;
		if((statusChange & 1) == 1){
			recentAction = button1press;
		}
		if((statusChange & 2) == 2){
			recentAction = button2press;
		}
		if((statusChange & 4) == 4){
			recentAction = button3press;
		}
		if((statusChange & 8) == 8){
			recentAction = button4press;
		}
		if((statusChange & 16) == 16){
			recentAction = button5press;
		}
		if((statusChange & 32) == 32){
			recentAction = button6press;
		}
		if((statusChange & 64) == 64){
			recentAction = button7press;
		}
		if((statusChange & 128) == 128){
			recentAction = button8press;
		}
	}
	previousStatus = newStatus;
}



