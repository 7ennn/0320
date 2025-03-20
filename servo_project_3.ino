#include <Servo.h>

Servo myservo;
const int switchPin = 2;

void setup() {
  myservo.attach(9);
  pinMode(switchPin, INPUT);
}

void loop() {
  if (digitalRead(switchPin) == HIGH) {
    myservo.write(90); // 轉動伺服馬達
    delay(1000); // 等待 1 秒
    myservo.write(0); // 恢復伺服馬達位置
  }
}
