# 伺服馬達-03

這是一個使用 Arduino 的簡單專案，當水銀開關被觸發時，伺服馬達會轉動。

## 硬體需求
- 伺服馬達
- 水銀開關
- Arduino Uno

## 連接方式
- 將伺服馬達的控制線連接到 Arduino 的 9 號引腳，電源線連接到 5V 和 GND。
- 將水銀開關連接到 Arduino 的 2 號引腳，另一端連接到 GND。

## 程式碼
```cpp
#include <Servo.h>

// 專案名稱: 伺服馬達-03

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
```
