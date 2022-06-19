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
char ssid[] = "Orange_2.4G";
char pass[] = "0829887580";

void setup()
{
  // Debug console
  Serial.begin(9600);

  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);
}

void loop()
{
  Blynk.run();
}
