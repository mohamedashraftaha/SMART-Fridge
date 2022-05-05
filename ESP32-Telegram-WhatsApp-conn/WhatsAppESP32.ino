#include <WiFi.h>
#include <ThingESP.h>

ThingESP32 thing("*************","*************", "*************");
#define LED  2

void setup() {
  // put your setup code here, to run once:
Serial.begin(115200);
pinMode(LED, OUTPUT);
thing.SetWiFi("*************","*************");
thing.initDevice();
}
String HandleResponse(String query)
{

  if (query == "led on") {
    digitalWrite(LED, HIGH);
    return "Done: LED Turned ON";
  }

  else if (query == "led off") {
    digitalWrite(LED, LOW);
    return "Done: LED Turned OFF";
  }

  else if (query == "led status")
    return digitalRead(LED) ? "LED is OFF" : "LED is ON";


  else return "Your query was invalid..";

}

void loop() {
  // put your main code here, to run repeatedly:
thing.Handle();
}
