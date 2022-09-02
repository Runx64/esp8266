/*New blynk app project
   http://srituhobby.com
*/

//Include the library files
#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include "DHT.h"
#define DHTPIN D1
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

#define BLYNK_AUTH_TOKEN "YvG_1Tkj4UXQSaIDTegCU6-avwJzt0U7" //Enter your blynk auth token

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "KPN@WIFI";//Enter your WIFI name
char pass[] = "";//Enter your WIFI password


void setup() {
  //Initialize the Blynk library
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status\tHumidity ( % )\tTemperature (C)\t(F)");
  dht.begin();
}

void loop() {
  float h = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float t = dht.readTemperature();
  // Read temperature as Fahrenheit (isFahrenheit = true)
  float f = dht.readTemperature(true);

  // Check if any reads failed and exit early (to try again).
  if (isnan(h) || isnan(t) || isnan(f)) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  // Compute heat index in Fahrenheit (the default)
  float hif = dht.computeHeatIndex(f, h);
  // Compute heat index in Celsius (isFahreheit = false)
  float hic = dht.computeHeatIndex(t, h, false);

  Serial.print(F("Humidity: "));
  Serial.print(h);
  Serial.print(F(" % Temperature: "));
  Serial.print(t);
  Serial.print(F("°C "));
  Serial.print(f);
  Serial.print(F("°F Heat index: "));
  Serial.print(hic);
  Serial.print(F("°C "));
  Serial.print(hif);
  Serial.println(F("°F"));

  Blynk.run();
  Blynk.virtualWrite(V0, t); //แสดงอุณหภูมิบนแอพ Blynk
  Blynk.virtualWrite(V1, h); //แสดงความชื้นบนแอพ Blynk
  Blynk.virtualWrite(V2, f); //แสดงอุณหภูมิองศาฟาเรนไฮบนแอพ Blynk
  delay(1000);
}
