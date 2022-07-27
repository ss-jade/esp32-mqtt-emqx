// Summer School 2022
// ESP32 test code for MQTT protocol using
// a free MQTT broker by emqx
// Gerardo Marx
#include <WiFi.h>
#include <PubSubClient.h>

// WiFi configuration
const char *ssid = "Haus2.4G"; // WiFi name
const char *password = "7476Haus#CB2040$";  // WiFi password
WiFiClient espClient;

// mqtt brocker:
const char *mqttBrocker = "broker.emqx.io";
const char *topic = "esp32/test";
const char *mqttUsername = "emqx";
const char *mqttPassword = "public";
const int mqttPort = 1883;
PubSubClient client(espClient);


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
  //connecting to a mqtt brocker:
  client.setServer(mqttBrocker, mqttPort);
  client.setCallback(callback);
  while(!client.connected()){
    String clientID = "esp32-gmarx-";
    clientID += String(WiFi.macAddress());
    Serial.printf("The %s tries to connect to mqtt borcker...\n",clientID.c_str());
    if(client.connect(clientID.c_str(), mqttUsername, mqttPassword)){
      Serial.println("mqtt brocker connected");
    }
    else {
      Serial.print("mqtt connection failed");
      Serial.println(client.state());
      delay(2000);
    }
  }
  //once connected publish and suscribe:
  client.publish(topic, "Hi EMQX broker I'm a ESP32 :)");
  client.subscribe(topic);
}

void loop(){
  client.loop();
}

void callback(char *topic, byte *payload, unsigned int length){
  Serial.print("Message recived in topic: ");
  Serial.println(topic);
  Serial.print("The message is: ");
  for(int i=0;i<length; i++){
    Serial.print((char) payload[i]);
  }
  Serial.println();
  Serial.println("-+-+-+End+-+-+-+");
}
