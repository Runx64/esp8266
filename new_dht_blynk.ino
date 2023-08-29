/library download https://www.mediafire.com/download/6qh8q1g0kmokl4g/DHT11.rar
#define BLYNK_PRINT Serial
//Template ID และ Token ได้มาจากเว็บ blynk
#define BLYNK_TEMPLATE_ID "TMPLIy6XyNcT"
#define BLYNK_DEVICE_NAME "NodemcuBlynk"
#define BLYNK_AUTH_TOKEN "OLtRS88nV-Aci8OM4O4-A_qPkRIJurw3"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// กรอกข้อมูล Wifi ของคุณ
char ssid[] = "KPN@WIFI"; //Enter Wifi name (ssid)
char pass[] = "";         //Enter Wifi password

#include "DHT.h"
DHT dht;
void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity (%)\tTemperature (C)\t(F)");
  dht.setup(2); // data pin 2
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop()
{
  delay(dht.getMinimumSamplingPeriod());
  float humidity = dht.getHumidity(); // ดึงค่าความชื้น
  float temperature = dht.getTemperature(); // ดึงค่าอุณหภูมิ
  Serial.print(dht.getStatusString());
  Serial.print("\t");
  Serial.print(humidity, 1);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  Serial.print("\t\t");
  Serial.println(dht.toFahrenheit(temperature), 1);
  
  Blynk.run();
  Blynk.virtualWrite(V0, temperature); //แสดงอุณหภูมิบนแอพ Blynk
  Blynk.virtualWrite(V1, humidity); //แสดงความชื้นบนแอพ Blynk
  delay(1000);
}
