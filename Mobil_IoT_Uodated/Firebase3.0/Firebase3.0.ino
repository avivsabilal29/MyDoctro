#include <ESP8266WiFi.h>
#include <FirebaseESP8266.h>
                          
#define FIREBASE_HOST "https://unisi-iot-d39b8-default-rtdb.firebaseio.com/" //Your Firebase Project URL goes here without "http:" , "\" and "/"
#define FIREBASE_AUTH "e00vSf2tla9xRy59SwOyrkpqKYu4IYIGlESBw415" //Your Firebase Database Secret goes here

#define WIFI_SSID "KONTRAKAN ALUMNI"                                               //WiFi SSID to which you want NodeMCU to connect
#define WIFI_PASSWORD "TMUA1443H"                                      //Password of your wifi network 
 
  

// Declare the Firebase Data object in the global scope
FirebaseData firebaseData;

// Declare global variable to store value
int val=0;
int temp=0;
int hum=0;
float longitude=-7.69358928344;
float latitude=110.416759391;



void setup() {

  Serial.begin(115200);                                   // Select the same baud rate if you want to see the datas on Serial Monitor

  Serial.println("Serial communication started\n\n");  
           
  WiFi.begin(WIFI_SSID, WIFI_PASSWORD);                                     //try to connect with wifi
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
  Serial.println(WiFi.localIP());                                            //print local IP address
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);   // connect to firebase

  Firebase.reconnectWiFi(true);
  delay(1000);
}



void loop() { 
 
  if (Firebase.setInt(firebaseData, "/UASC_EV/UNISI_Kaliurang/Voltage", val + random(0,1000000)) &&
      Firebase.setInt(firebaseData, "/UASC_EV/UNISI_Kaliurang/Suhu", temp + random(0,1000000)) &&
      Firebase.setInt(firebaseData, "/UASC_EV/UNISI_Kaliurang/Humadity", hum + random(0,1000000)) &&
      Firebase.setFloat(firebaseData, "/UASC_EV/UNISI_Kaliurang/Latitude", latitude) &&
      Firebase.setFloat(firebaseData, "/UASC_EV/UNISI_Kaliurang/Longitude", longitude) 
      ) {
    
    // On successful Write operation, function returns 1
    Serial.println("Value Uploaded Successfully");
    Serial.println("\n");
    delay(1000);
  } else {        
    Serial.println(firebaseData.errorReason());
  }
}
