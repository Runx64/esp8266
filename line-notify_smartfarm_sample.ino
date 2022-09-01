int analogPin = A0;
int val = 0;
#include <TridentTD_LineNotify.h>
#define SSID        "KPN@WIFI"   // ชื่อ Wifi
#define PASSWORD    ""   // รหัส Wifi
#define LINE_TOKEN  "QVW2LxIVw7I9LlszmxmNdbATCKrbTDGYdy09KeMYHWf"   // TOKEN

void setup() {
  Serial.begin(9600);
  Serial.println(LINE.getVersion());
  WiFi.begin(SSID, PASSWORD);
  Serial.printf("WiFi connecting ",  SSID);
  while (WiFi.status() != WL_CONNECTED) {
    Serial.print(".");
    delay(500);
  }
  Serial.printf("\nWiFi connected\nIP : ");
  Serial.println(WiFi.localIP());
}

void loop() {
  val = analogRead(analogPin);
  Serial.print("val = "); // พิมพ์ข้อมความส่งเข้าคอมพิวเตอร์ "val = "
  Serial.println(val); // พิมพ์ค่าของตัวแปร val
  LINE.setToken(LINE_TOKEN);
  delay(100);
  if(val>500){
    LINE.notify("รดน้ำแล้ว , ค่าความชื้น =" + String(val));
  }
}
