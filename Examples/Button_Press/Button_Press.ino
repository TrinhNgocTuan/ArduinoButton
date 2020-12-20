#include "Button.h"
#define led  A0 
bool staLed=0;
const int BUTTON_PIN = 2;     
  
Button button(BUTTON_PIN);
void setup() {
  Serial.begin(9600);
  pinMode(led,OUTPUT);
}
void loop() {
  //phải gọi hàm này trước isPressed() và isReleased()
  button.handle();
  //kiểm tra click phím
  if(button.isClicked())
  {
    staLed=!staLed;
    digitalWrite(led,staLed);
    Serial.println("click");
  }
  //kiểm tra nhấn giữ
  if(button.isPressed())
  {
    Serial.println("press");
  }
  //kiểm tra nhả phím
  if(button.isReleased())
  {
    Serial.println("release");
  }
}