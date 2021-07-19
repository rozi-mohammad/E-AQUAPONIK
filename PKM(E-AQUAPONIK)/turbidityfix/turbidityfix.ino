/*Modified by
 * Technical Team,REES52
 */

#include <ESP8266WiFi.h>
#include <Wire.h> 



int pos = 0;
//#include "SSD1306.h" 
//SSD1306  display(0x3c, D1, D2);
// replace with your channel's thingspeak API key, 
String apiKey = "1JZSEBEBEBLAWVUR";
const char* ssid = "LAB_MULTIMEDIA";
const char* password = "markazlughoh2020";
 
const char* server = "api.thingspeak.com";
 
WiFiClient client;
void setup() {     
  Serial.begin(115200);
  pinMode(A0,INPUT);
//  display.init();
  //display.flipScreenVertically();
//  display.setFont(ArialMT_Plain_10);
  
  delay(10);
  WiFi.begin(ssid, password);
   
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("");
  Serial.println("WiFi connected");

 
  
}
 
 
void loop() {
  //display.clear(); 
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5 / 24.0); // Convert the analog reading (which goes from 0 - 1023) to a voltage (0 - 5V):
  Serial.println(voltage); // print out the value you read:
  delay(500);
  if (client.connect(server,80)) {  //   "184.106.153.149" or api.thingspeak.com
    String postStr = apiKey;
           postStr +="&field1=";
           postStr += String(sensorValue);
           postStr += "\r\n\r\n";
 
     client.print("POST /update HTTP/1.1\n"); 
     client.print("Host: api.thingspeak.com\n"); 
     client.print("Connection: close\n"); 
     client.print("X-THINGSPEAKAPIKEY: "+apiKey+"\n"); 
     client.print("Content-Type: application/x-www-form-urlencoded\n"); 
     client.print("Content-Length: "); 
     client.print(postStr.length()); 
     client.print("\n\n"); 
     client.print(postStr);
           
 
     Serial.print("Turbidity Sensor Value: ");
     Serial.print(sensorValue);
//     display.drawString(0, 20,"Moisture: ");
//     display.drawString(0, 30,String(temp));
     Serial.println(" send to Thingspeak");
//     display.drawString(0, 10, "Send to Thingspeak");   
//     display.display(); 
  }
  client.stop();
   

   Serial.println("Waiting...");    
  // thingspeak needs minimum 15 sec delay between updates
  // Here I set upload every 60 seconds
  for(unsigned int i = 0; i < 20; i++)
  {
    delay(100);                         
  } 

  
}

                        
