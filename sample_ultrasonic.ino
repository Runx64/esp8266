#define trig D1 //กำหนด Trig pin เป็น D1
#define echo D2 //กำหนด Echo pin เป็น D2

void setup() {
  Serial.begin(9600);
}

void loop() {
  int cm = checkDistance(); //เรียกใช้ฟังก์ชัน checkDistance
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  delay(200);
}

//ฟังก์ชันสำหรับคำนวณระยะทางจาก Ultrasonic
long checkDistance() {
  int duration, cm;
  pinMode(trig, OUTPUT);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig, HIGH);
  delayMicroseconds(5);
  digitalWrite(trig, LOW);
  pinMode(echo, INPUT);
  duration = pulseIn(echo, HIGH);
  cm = duration / 29 / 2;
  return cm; //ส่งค่าระยะทางจากการคำนวณกลับไปฟังก์ชันหลัก
}
