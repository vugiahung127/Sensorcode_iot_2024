
#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>
#define BLYNK_PRINT Serial

char auth[] = "";

char ssid[] = "";
char pass[] = "";

#define WATER_PUMP 27
boolean state = false;

void setup()
{
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
  pinMode(WATER_PUMP, OUTPUT);
}

void loop()
{
  Blynk.run()
}

BLYNK_WRITE(V1)
{
  if(state == false){
    state = true;
    Blynk.notify("Watered your plant.");
    digitalWrite(WATER_PUMP,HIGH);
    delay(3000);
  }
  else{
  state = false;
  digitalWrite(WATER_PUMP,LOW);
  }
}
