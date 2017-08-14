// Analog Handbrake V1.1
// 아날로그 핸드브레이크 V1.1
//
// Arduino Leonardo or Arduino Micro.
//
// TRIZ
// 2017-08-14

#include <Joystick.h>

//static int potValueMin = 0;
//static int potValueMax = 1023;
static int potValueMin = 0;
static int potValueMax = 1023;

void setup()
{
  Joystick.begin();
  
  Serial.begin(9600);
}

void loop()
{
  //가변저항 값 읽기
  int potValue = analogRead(A0);
  
  //가변저항 값 0~255의 값으로 변환
  //int ThrottleValue = map(potValue,0,1023,0,255);
  int ThrottleValue = map(potValue,potValueMin,potValueMax,0,255);
  
  //변환 값 출력
  if (potValue < potValueMin) {
    Joystick.setThrottle(0);
  }
  else if (potValue > potValueMax) {
    Joystick.setThrottle(255);
  }
  else {
  Joystick.setThrottle(ThrottleValue);
  }

  Serial.println(potValue);
}
