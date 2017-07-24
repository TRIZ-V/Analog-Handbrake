#include <Joystick.h>

void setup()
{
  // 범위 설정
  Joystick.setThrottleRange(0, 255);
  Joystick.begin();
}

void loop()
{
  //가변저항 값 읽기
  int potValue = analogRead(A0);
  
  //가변저항 값 0~255의 값으로 변환
  int ThrottleValue = map(potValue,0,1023,0,255);
  
  //변환 값 출력
  Joystick.setThrottle(ThrottleValue);
}
