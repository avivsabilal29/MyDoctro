/* Jangan lupa Subscribe Channel youtube.com/idrusproject */

#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>

// Dapetin tokennya di email kamu
char auth[] = "-MiYgnNvY4dksRf4dEpFfZdlLl77FqRT";

// id dan password internet kamu
char ssid[] = "avivsabilal29";
char pass[] = "Mujtahid29";

void setup(){
  Serial.begin(9600);
  Blynk.begin(auth, ssid, pass);
}

void loop(){
  Blynk.run();
}
