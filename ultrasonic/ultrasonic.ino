#include <Config.h>
#include <Firebase.h>
#include <Firebase_Arduino_WiFi101.h>
#include <WCS.h>

#include <UnoWiFiDevEd.h>
#define FIREBASE_HOST ""
#define FIREBASE_AUTH ""

#define WIFI_SSID "#"
#define WIFI_PASSWORD "#"
#define echoPin D1
#define trigPin D0

int maximumRange = 200;
int minimumRange = 00;
long duration, distance ;

void setup(){
  Serial.begin(115200);
  delay(500);
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
  Serial.print("Menghubungkan ke ");
  Serial.print(WIFI_SSID);
  while(WiFi.status()!= WL_CONNECTED){
    Serial.print(".");
    delay(500);
    }
    Serial.println();
    Serial.print("MEnyambungkan ke");
    Serial.println(WIFI_SSID);
    Serial.print("IP ADDRESS IS : ");
    Serial.println(WiFi.localIP());
    Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
    pinMode(trigPin, OUTPUT);
    pinMode(echoPin, INPUT);
    
    
  }

void loop(){
  digitalWrite(trigPin, LOW); delayMicroseconds(2);
  digitalWrite(trigPin, HIGH); delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);

  distance = duration/58.2;


  if(distance >= maximumRange || distance <= minimumRange)
  {
    Serial.println("-1");  
  }
  else{
    Serial.println(distance);
    String Jarak = String (distance);
 Firebase.pushString("/Ultrasonic/Jarak", Jarak);
  }
  if (Firebase.failed()){
    Serial.print("pushing/logs failed: ");
    Serial.println(Firebase.error());
    return;
    }
  }
