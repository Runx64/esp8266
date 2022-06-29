#include <Servo.h> //เรียกใช้ library Servo
Servo myservo;

void setup() {
  myservo.attach(D4); //กำหนด pin servo เป็น D4
}

void loop() {
  myservo.write(0);
  delay(2000);
  myservo.write(180);
  delay(2000);
}
