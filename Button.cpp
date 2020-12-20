/*
Library Button
Author: Ngoc Tuan
Version:1.0.0
Date:15/12/2020
*/
#include "Button.h"
Button::Button(unsigned char pin)
{
	_pin=pin;
	pinMode(_pin,INPUT_PULLUP);
	preState = HIGH; 
	lastAfterFilterNoiseState = LOW;
}
bool Button::isClicked()
{
	if(state==1)	return true;
	return false;
}
bool Button::isPressed()
{
	if(state==2)	return true;
	return false;
}
bool Button::isReleased()
{
	if(state==3)	return true;
	return false;	
}
void Button::handle()
{
	state=0;//reset trang thai
	//đọc trạng thái nút nhấn
  currentState = digitalRead(_pin);
  //khi có nhiễu thì đoạn code này sẽ chạy liên tục
  if (currentState != lastAfterFilterNoiseState)
  {
    lastDebounceTime = millis();
    lastAfterFilterNoiseState = currentState;
  }
  //het thoi gian nhieu thi moi thuc hien code duoi 
  if ((millis() - lastDebounceTime)>DEBOUNCE_DELAY)
  {
	  if(preState == HIGH && currentState == LOW)
	  {
		  //Serial.println("click");
		  state=1;
	  }
	  if(preState == LOW && currentState ==HIGH)
	  {
		 // Serial.println("release");
		  state=3;
	  }
	  else if(preState == LOW)state=2;//press
	  preState = currentState;
  }

}