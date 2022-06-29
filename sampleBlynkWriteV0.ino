#define BLYNK_PRINT Serial
#define BLYNK_TEMPLATE_ID "TMPLjfyHpJB2"
#define BLYNK_DEVICE_NAME "swDevice"
#define BLYNK_AUTH_TOKEN "ZxCRZvkQ1bZvWSrKiE6gQ_JbkZ9WcDnG"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// Your WiFi credentials.
// Set password to "" for open networks.
char ssid[] = "KPN@WIFI"; //Enter Wifi name (ssid)
char pass[] = "";         //Enter Wifi password

void setup()
{
  // Debug console
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
  pinMode(D1,OUTPUT);
}

void loop()
{
  Blynk.run();
}

BLYNK_WRITE(V0)
    {
      if(param.asInt()) {
        Serial.println("LED ON");
        digitalWrite(D1,HIGH);
      }
      else{
        Serial.println("LED OFF");
        digitalWrite(D1,LOW);
      }
    }
