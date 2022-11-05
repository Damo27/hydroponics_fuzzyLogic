#include <ESP8266WiFi.h>
#include <ThingSpeak.h>

WiFiClient client;
// Network SSID
char ssid[] = "SupaSquishy";
char password[] = "PASSsam001";
const char * APIwrite = "BVKYYSKOVU91N1UQ";
unsigned long channelNumber = 1913576;

void setup() {
  Serial.begin(9600);
  
  // Connect WiFi
  WiFi.hostname("Arduino");
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED)
  { 
    Serial.print("."); 
    delay(500); 
  }
  Serial.println("connected: "); 
  Serial.println(WiFi.localIP()); 
  ThingSpeak.begin(client);
}

void loop() {
  delay(5000);
  ThingSpeak.setField(1, getAirTemp());
  ThingSpeak.setField(2, getHumidity());
  ThingSpeak.setField(3, getPH());
  ThingSpeak.setField(4, getEC());
  ThingSpeak.writeFields(channelNumber, APIwrite);    
}

int getAirTemp(){
  return random(45);
}

int getHumidity(){
  return random(100);
}

float getPH(){
  return random(100, 1400) / 100.0;
}

float getEC(){
  return random(100, 500) / 100.0;
}