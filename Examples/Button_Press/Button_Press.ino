#include "Button.h"
Button button(2);
void setup() {
  Serial.begin(9600);
}

void loop() {
  button.handle();
  if(button.isPressed())
  {
    Serial.println("press ok");
  }
  if(button.isReleased())
  {
    Serial.println("release");
  }
  delay(100);
}