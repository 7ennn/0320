# 伺服馬達-02

這是一個使用 Arduino 的自動門系統專案，當水銀開關被觸發時，伺服馬達會轉動以模擬門的開啟和關閉。

## 硬體需求
- 伺服馬達
- 蜂鳴器
- 可調式電阻
- 四個 LED 燈
- 三個水銀開關
- Arduino Uno

## 連接方式
- 將伺服馬達的控制線連接到 Arduino 的 9 號引腳，電源線連接到 5V 和 GND。
- 將蜂鳴器的正極連接到 Arduino 的 8 號引腳，負極連接到 GND。
- 將三個水銀開關分別連接到 Arduino 的 2、3、4 號引腳，另一端連接到 GND。
- 將四個 LED 燈分別連接到 Arduino 的 5、6、7、10 號引腳，並通過電阻接到 GND。

## 程式碼
```cpp
#include <Servo.h>

// 專案名稱: 伺服馬達-02

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
```
