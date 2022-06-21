//Example By ArduinoAll

#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLX6y2L1X7"
#define BLYNK_DEVICE_NAME "RobotCar"
#define BLYNK_AUTH_TOKEN "aN-9UyxpIXRgg_rV8EPamEqjBC6xMnVX"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "TP-Link_8B6A";
char pass[] = "78574588";

int MotorL = D1;
int MotorR = D2;
int MotorPWM = D3;
int Motor2L = D5;
int Motor2R = D6;
int Motor2PWM = D7;
void setup() {
  pinMode(MotorL, OUTPUT);
  pinMode(MotorR, OUTPUT);
  pinMode(MotorPWM, OUTPUT);
  pinMode(Motor2L, OUTPUT);
  pinMode(Motor2R, OUTPUT);
  pinMode(Motor2PWM, OUTPUT);
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);

}
void loop() {
  Blynk.run();
}

BLYNK_WRITE(V0)
{
  if (param.asInt()) {
    fd1();
  }
  else {
    stop1();
  }
}


BLYNK_WRITE(V1)
{
  if (param.asInt()) {
    bk1();
  }
  else {
    stop1();
  }
}


BLYNK_WRITE(V2)
{
  if (param.asInt()) {
    tl1();
  }
  else {
    stop1();
  }
}


BLYNK_WRITE(V3)
{
  if (param.asInt()) {
    tr1();
  }
  else {
    stop1();
  }
}
void fd1() {
  // เดินหน้า
  digitalWrite(MotorL, 1);
  digitalWrite(MotorR, 0);
  digitalWrite(Motor2L, 1);
  digitalWrite(Motor2R, 0);
  // ปรับความเร็วมอเตอร์ 0-1023
  analogWrite(MotorPWM, 1000); // ปรับความเร็วมอเตอร์เป็นระดับ 255
  analogWrite(Motor2PWM, 1000);
  Serial.println("speed 1000");
}

void bk1() {

  // ถอยหลัง
  digitalWrite(MotorL, 0);
  digitalWrite(MotorR, 1);
  digitalWrite(Motor2L, 0);
  digitalWrite(Motor2R, 1);
  // ปรับความเร็วมอเตอร์ 0-1023
  analogWrite(MotorPWM, 1000); // ปรับความเร็วมอเตอร์เป็นระดับ 255
  analogWrite(Motor2PWM, 1000);
  Serial.println("speed 1000");
}

void tl1() {
  // เลี้ยวซ้าย
  digitalWrite(MotorL, 1);
  digitalWrite(MotorR, 0);
  digitalWrite(Motor2L, 0);
  digitalWrite(Motor2R, 1);
  // ปรับความเร็วมอเตอร์ 0-1023
  analogWrite(MotorPWM, 1000); // ปรับความเร็วมอเตอร์เป็นระดับ 255
  analogWrite(Motor2PWM, 1000);
  Serial.println("speed 1000");
}

void tr1() {
  // เลี้ยวขวา
  digitalWrite(MotorL, 0);
  digitalWrite(MotorR, 1);
  digitalWrite(Motor2L, 1);
  digitalWrite(Motor2R, 0);
  // ปรับความเร็วมอเตอร์ 0-1023
  analogWrite(MotorPWM, 1000); // ปรับความเร็วมอเตอร์เป็นระดับ 255
  analogWrite(Motor2PWM, 1000);
  Serial.println("speed 1000");
}

void stop1() {
  analogWrite(MotorPWM, 0);
  analogWrite(Motor2PWM, 0);
  Serial.println("stop");
}
