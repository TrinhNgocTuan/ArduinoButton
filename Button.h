/*
Library Button
Author: Ngoc Tuan
Version:1.0.0
Date:15/12/2020
*/
#ifndef _BUTTON_H
#define _BUTTON_H
#include "Arduino.h"
class Button
{
	public:
		Button(unsigned char pin);
		bool isClicked();
		bool isPressed();
		bool isReleased();
		void handle();
	private:
		unsigned char _pin;      
		const int DEBOUNCE_DELAY = 20;  
		bool preState;  // bien luu trang thai truoc day    
		bool lastAfterFilterNoiseState = LOW; // bien khu nhieu
		bool currentState;  //bien trang thai hien tai             
		unsigned long lastDebounceTime;
		unsigned char state;
};
#endif