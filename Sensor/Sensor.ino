#include <SPI.h>
#include <WiFi101.h>

String READY_MSG = "Arduino is ready!";
bool isConnected = false;

void setup() {
   Serial.begin(9600);
   while(!Serial){
       // Do nothing... Wait for serial connection
       isConnected  = false;
   }
   // If we were not connected, it means we need to greet with READY_MSG
   if(!isConnected ){
       isConnected = true;
       Serial.print(READY_MSG);
   }
   // We can safely communicate now!
   
   
   
   // attempt to connect using WPA2 encryption:
  Serial.println("Attempting to connect to WPA network...");
  int status = WiFi.begin("sunset_home", "Lucy@1226");

  // if you're not connected, stop here:
  if ( status != WL_CONNECTED) { 
    Serial.println("Couldn't get a wifi connection");
    while(true);
  } 
  // if you are connected, print out info about the connection:
  else {
    Serial.println("Connected to network");
  }
}

void loop(){
   Serial.print(".");
   delay(1000);
}
