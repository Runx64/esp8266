#define BLYNK_PRINT Serial
//Template ID และ Token ได้มาจากเว็บ blynk
#define BLYNK_TEMPLATE_ID "TMPL8XSMv5hr"
#define BLYNK_DEVICE_NAME "RelayMotor"
#define BLYNK_AUTH_TOKEN "AAaWOObNQe8dyc9LgrCxN7DoxXXw3pjM"

#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = BLYNK_AUTH_TOKEN;

// กรอกข้อมูล Wifi ของคุณ
char ssid[] = "KPN@WIFI"; //Enter Wifi name (ssid)
char pass[] = "";         //Enter Wifi password

void setup()
{
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
        Serial.println("RELAY ON");
        digitalWrite(D1,LOW);
      }
      else{
        Serial.println("RELAY OFF");
        digitalWrite(D1,HIGH);
      }
    }
