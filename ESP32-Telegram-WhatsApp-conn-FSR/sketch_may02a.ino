#include <CayenneMQTTESP32.h>
#include <ThingESP.h>
#include <WiFi.h>

ThingESP32 thing("shenawy", "SmartFridge", "123456789");

#define RXD2 16    //port number on ESP32 (GPIO16)
#define TXD2 17   //port number on ESP32  (GPIO17)
#define RXD0 3    //port number on ESP32 (GPIO3)
#define TXD0 1   //port number on ESP32  (GPIO1)
#define Temp_VIRTUAL_CHANNEL 1

const char* ssid = "shenawy";
const char* wifipassword = "shenawy7";
float temp=0;
char username[] = "00d306b0-43ee-11ec-9f5b-45181495093e";
char password[] = "a2d0d87ab179b1c07887bf7df17a0a640d418f40";
char clientID[] = "73402040-cab0-11ec-8c44-371df593ba58";
unsigned long previousMillis=0;
const long INTERVAL=10000;
int Enable_pin = 4;
int fsrPin = 36;     // the FSR and 10K pulldown are connected to a0
int fsrReading;     // the analog reading from the FSR resistor divide

void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);      //Baud rate for UART2
  Serial2.begin(9600,SERIAL_8N1,RXD2,TXD2);
//ESP32 connects to your wifi -----------------------------------

thing.SetWiFi("shenawy", "shenawy7");
thing.initDevice();
Cayenne.begin(username, password, clientID,ssid,wifipassword);
 }

 String HandleResponse(String query)
{

   String welc=String("Please enter *temp* to display current temperature.\n\n") +
  "Please enter *ac1* to make A/C on 25%.\n\n"+"Please enter *ac2* to make A/C on 50%.\n\n"+
  "Please enter *ac3* to make A/C on 75%.\n\n"+"Please enter *ac4* to make A/C on 100%.\n\n";

  if (query == "temp") {
    return ("Temp is: "+String(temp));
  }
  else if(query=="ac1"){
    Serial2.print('1');
    delay(1000);
    return ("A/C is on 25%");
  }
   else if(query=="ac2"){
    Serial2.print('2');
    return ("A/C is on 50%");
  }
    else if(query=="ac3"){
    Serial2.print('3');
    return ("A/C is on 75%");
  }
    else if(query=="ac4"){
    Serial2.print('4');
    return ("A/C is on 100%");
  }
  else return welc;
 
    
  

}

void loop() {
  // put your main code here, to run repeatedly:
    Cayenne.loop();
    thing.Handle();

     fsrReading = analogRead(fsrPin);

    Serial.println("Analog reading = "+String(fsrReading));
    delay(1000);

    if(millis()-previousMillis>=INTERVAL){
      previousMillis=millis();

      String msg;
      
      if(temp>27)
      {
        msg="Temperature is critically high!!!: "+String(temp);
        thing.sendMsg("+201111244055", msg);
      }
      else if(temp<24)
      {
        msg="Temperature is critically low!!!: "+String(temp);
        thing.sendMsg("+201111244055", msg);
      }

    if(fsrReading<600)
    {
      msg="You need to restock!!! Call vendor!!!";
        thing.sendMsg("+201111244055", msg);
    }
      
    }

    
if(Serial2.available()) //while we're receiving data through the uart from the STM32 board microcontroller
  { 
    temp=Serial2.parseFloat(); //converts the received temp into float
    Serial.println(temp);   //print the final result of the temp
    Cayenne.virtualWrite(Temp_VIRTUAL_CHANNEL, temp, TYPE_TEMPERATURE, UNIT_CELSIUS);
  }  

  
}
