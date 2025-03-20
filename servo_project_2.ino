#include <Servo.h>

Servo myservo;
const int buzzer = 8;
const int ledPins[] = {5, 6, 7, 10};
const int switchPins[] = {2, 3, 4};

void setup() {
  myservo.attach(9);
  pinMode(buzzer, OUTPUT);
  for (int i = 0; i < 4; i++) {
    pinMode(ledPins[i], OUTPUT);
  }
  for (int i = 0; i < 3; i++) {
    pinMode(switchPins[i], INPUT);
  }
}

void loop() {
  for (int i = 0; i < 3; i++) {
    if (digitalRead(switchPins[i]) == HIGH) {
      myservo.write(90); // 轉動伺服馬達以開啟門
      digitalWrite(buzzer, HIGH); // 開啟蜂鳴器
      for (int j = 0; j < 4; j++) {
        digitalWrite(ledPins[j], HIGH); // 開啟所有 LED 燈
      }
      delay(2000); // 等待 2 秒
      myservo.write(0); // 轉動伺服馬達以關閉門
      digitalWrite(buzzer, LOW); // 關閉蜂鳴器
      for (int j = 0; j < 4; j++) {
        digitalWrite(ledPins[j], LOW); // 關閉所有 LED 燈
      }
    }
  }
}
