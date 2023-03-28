#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>

#define FIREBASE_HOST "https://unisi-iot-d39b8-default-rtdb.firebaseio.com/"
#define FIREBASE_AUTH "e00vSf2tla9xRy59SwOyrkpqKYu4IYIGlESBw415"

#define WIFI_SSID "KONTRAKAN ALUMNI"
#define WIFI_PASSWORD "TMUA1443H"

FirebaseData firebaseData;
int button;

void setup() {
Serial.begin(115200);
Serial.println("Serial communication started\n\n");

WiFi.begin(WIFI_SSID, WIFI_PASSWORD);
Serial.print("Connecting to ");
Serial.print(WIFI_SSID);

while (WiFi.status() != WL_CONNECTED) {
Serial.print(".");
delay(500);
}

Serial.println();
Serial.print("Connected to ");
Serial.println(WIFI_SSID);
Serial.print("IP Address is : ");
Serial.println(WiFi.localIP());
Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);

Firebase.reconnectWiFi(true);
delay(1000);
}

void loop() {
// Read integer value from Firebase
if (Firebase.getInt(firebaseData, "/UASC_EV/UNISI_Kaliurang/Power/power", &button)) {
Serial.print("Power Value: ");
Serial.println(button);
delay(1000);
} else {
Serial.println(firebaseData.errorReason());
}
}
