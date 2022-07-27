// Summer School 2022
// ESP32 test code for MQTT protocol using
// a free MQTT broker by emqx
// Gerardo Marx
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi configuration
const char *ssid = "sedeam"; // WiFi name
const char *password = "Sede@m2025";  // WiFi password
WiFiClient espClient;

void setup(){
  //serial communication
  Serial.begin(115200);
  WiFi.begin(ssid, password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print("Connecting to ");
    Serial.println(ssid); 
  }
  Serial.println("Connection done.");
}

void loop(){
  
}
