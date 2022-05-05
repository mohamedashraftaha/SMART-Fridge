#include <WiFi.h>
#include <WiFiClientSecure.h>
#include <UniversalTelegramBot.h>
#include <ArduinoJson.h>
const char* ssid = "ashraf"; //replace with your SSID
const char* password = "m12345678"; //replace with your password

#define BOTtoken "5120278889:AAFdbTmIuG92lGxada088Uhx_Q7_ReiUdsk"  
#define CHAT_ID "5213002856"
#define ONBOARD_LED  2
WiFiClientSecure client;
UniversalTelegramBot bot(BOTtoken, client);

// Checks for new messages every 1 second.
int bot_delay = 1000;
unsigned long lastTimeBotRan;


// Handle what happens when you receive new messages
void handleNewMessages(int numNewMessages) 
{
  Serial.println("Handling New Message");
  Serial.println(String(numNewMessages));

  for (int i=0; i<numNewMessages; i++)
  {
    // Chat id of the requester
    String chat_id = String(bot.messages[i].chat_id);
    if (chat_id != CHAT_ID)
    {
      bot.sendMessage(chat_id, "Unauthorized user", "");
      continue;
    }
     // Print the received message
    String user_text = bot.messages[i].text;
    Serial.println(user_text);
    String your_name = bot.messages[i].from_name;

    if (user_text == "/start") 
    {
      String welcome = "Welcome, " + your_name + ".\n";
      welcome += "Send /led_on \n";
      welcome += "Send /led_oiff \n";


      bot.sendMessage(chat_id, welcome, "");
    }
    if(user_text =="/led_on")
    {
      bot.sendMessage(chat_id, "Turning LED ON", "");
      digitalWrite(ONBOARD_LED, HIGH);
     }
   if(user_text =="/led_off")
    {
      bot.sendMessage(chat_id, "Turning LED OFF", "");
      digitalWrite(ONBOARD_LED, LOW);
     }
  }
}


void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);

 // Attempt to connect to Wifi network:
  Serial.print("Connecting Wifi: ");
  Serial.println(ssid);

  WiFi.mode(WIFI_STA);
  WiFi.begin(ssid, password);
  client.setCACert(TELEGRAM_CERTIFICATE_ROOT); 

  while (WiFi.status() != WL_CONNECTED)
  {
    Serial.print(".");
    delay(500);
  }

  Serial.println("");
  Serial.println("WiFi connected");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
  pinMode(ONBOARD_LED,OUTPUT);
  bot.sendMessage(CHAT_ID, "Bot started up", "");
}

void loop()
{
  

  // put your main code here, to run repeatedly:
  if (millis() > lastTimeBotRan + bot_delay) 
  {
    int numNewMessages = bot.getUpdates(bot.last_message_received + 1);

    while(numNewMessages)
    {
      Serial.println("Got Response!");
      handleNewMessages(numNewMessages);
      numNewMessages = bot.getUpdates(bot.last_message_received + 1);
    }
    lastTimeBotRan = millis();
  }
}
