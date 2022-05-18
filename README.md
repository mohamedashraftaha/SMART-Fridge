# System Description


![image](https://user-images.githubusercontent.com/75078872/169043997-96f10a74-8637-4ba5-828a-3c53a6c2aac6.png)

The goal of our project is to implement a SMART Fridge. With our Embedded system, it is much easier for shop owners to **keep track of the capacity** of the products. This is done by contacting the vendors and asking for product supply in case the shop/user has run out of enough stock. Our system also facilitates the maintenance procedures of the fridges, since it provides a sensor that makes sure that the temperature of the fridge is maintained to a certain acceptable value that will preserve the quality of the products stored inside it. We are also using a ~~telegram~~ WhatsApp bot by which we can keep track of the system conditions. Moreover, we are using cayenne which is an IoT analytics platform service that allows you to aggregate, visualize, and analyze live data streams in the cloud, to maintain our system and provide support in case of malfunctions.

# Team Members
* Mohamed Ashraf Taha
* Mohamed El-shenawy
* Omar ElMahdy



# Source Code & implementaion:
[GitHub Repo](https://github.com/mohamedashraftaha/SMART-Fridge.git)

# Hardware Requirements
* 1 ESP32
* 1 STM32L432KC
* 1 LM35DZ (Temperature Sensor)
* 1 LEDs
* 1 Force Sensitive Resistor (FSR)
* 3 10KΩ Resistors
* 3 800Ω Resistors
* Breadboard
* Jumper wires

# Software Requirements
* STM32CubeMX
* Keil uVision
* TeraTerm
* Arduino IDE
* Twilio Sandbox for WhatsApp


# System Design

![image](https://user-images.githubusercontent.com/75078872/169044547-e466cb5d-cf71-4ddc-9061-9715836a58df.png)

# First Prototype

Progress:

In this milestone, we were able to interface with our temperature sensor (as shown in the prototype demo). We also were able to configure the ESP32 wifi module to connect to cayenne, which is an IoT analytics platform service.

Next Steps:
- We are currently trying a more suitable pressure sensor for our project
- we will send the temperature values produced by the temperature sensor to ESP32 to be sent to cayenne to analyze the results
- we will start working on the GPS as a final step in our project.
- We are currently working on connecting to WhatsApp Bot
- we are working on the logic of the PWM that will mimic the AC

[Prototype1 Demo](https://drive.google.com/file/d/1nfIpaBxZxsNidFfPM9dbTh3mpdhAGIvq/view?usp=sharing)


# Second Prototype

Progress:

In this milestone, we were able to set up the communication between STM32 and ESP32 (which acts as a WiFi module) through UART. We sent the temperature readings, that we achieved from prototype 1 to ESP32. We then configured ESP32 to send these commands to cayenne as well as a WhatsApp Bot. We also completed the logic of mimicking an AC; this is done through the WhatsApp bot continuously sending the temperature readings to the user and if the temperature is below a certain value, we can send a command through WhatsApp to increase the power of the AC. We have 4 options: ac1, ac2, ac3, and ac4. The first one represents 25% of the AC power, the second is 50%, and the last two are 75% and 100%.

Next Steps:
* We are currently left with:
     *  interfacing with the pressure sensor to get the count of stock
     *  interfacing with the GPS module to extract the location of the fridge


[Prototype2 Demo](https://drive.google.com/file/d/1jwTtuIyOp-E0GkUlaRnirRBDJSuKwNcy/view?usp=sharing)

# Final Prototype

## STM32CubeMx Pin Configurations
![image](https://user-images.githubusercontent.com/75078872/169050970-e8ecce5b-96a2-4ccf-823d-f7633cbab042.png)
![image](https://user-images.githubusercontent.com/75078872/169051106-6afce586-c03b-408e-9f66-605039878ae8.png)
![image](https://user-images.githubusercontent.com/75078872/169051167-a3d70fce-b2b7-41cb-affa-3de3c33d3485.png)


## Physical Connections: Circuitry and Setup
![image](https://user-images.githubusercontent.com/75078872/169065455-9bd09faa-bfea-479f-a878-0cf0e03b4688.png)
---
![image](https://user-images.githubusercontent.com/75078872/169065518-c2fcd81a-1d00-4373-acbd-8134ae502933.png)
---
![image](https://user-images.githubusercontent.com/75078872/169083699-6cb2ffaa-cddc-4bbc-94e2-1dc155c9a9e8.png)

## Final Demo
[Final Demo](https://drive.google.com/file/d/1YnNAmWvNDu8-RO3L5acA4BO7gkvv5Gyx/view?usp=sharing)
------
# Challenges
1. We first started by using the pressure sensor MS5540C, but unfortunately this sensor wasn't fit for our project purposes. So we decided to use an FSR (force-sensitive resistor) and we were able to successfully interface with this sensor.
2. Having to use ESP32 and configuring it as a WiFi module, and connecting to WhatsApp Bot using Twilio API, since we had to learn how to deal with Twilio and the WhatsApp bot as well as ESPThing, which is a library that utilizes the use of the WhatsApp bot.
3.  Configuring the FSR on Arduino since we had trouble configuring multiple ADC channels to get values from Temperature and FSR sensors

# Limitations
1. Having to use ESP32 as a WiFi module, thus increasing the size and complexity of our circuitry.
2. Using a LED to mimic the AC.
3. Having to add extra layers beneath the fridge so that we can concentrate the force applied by the fridge on the FSR, since the FSR area is small.
4. Configuring the FSR on Arduino since we had trouble configuring multiple ADC channels to get values from Temperature and FSR sensors

# Future Work
1. Using a GPS module to track the location of the Fridge to make it easier for our vendors to know which fridge is out of stock.
2. Configuring WhatsApp to automatically call the vendors instead of just sending reminders to the fridge owner.
3. Using a board with more than one ADC or using an external ADC.

# References
1. [ESP32 Telegram](https://randomnerdtutorials.com/telegram-control-esp32-esp8266-nodemcu-outputs/)
2. [ESP32 WhatsApp ](https://www.youtube.com/watch?v=in3W1d_BpXw)
3. [ThingESP Platform](https://github.com/SiddheshNan/ThingESP-Arduino-Library)
4. [LM35DZ Datasheet](https://www.ti.com/lit/ds/symlink/lm35.pdf)
5. [Twilio Sandbox for whatsapp](https://www.twilio.com/docs/whatsapp/sandbox)
6. [FSR](https://learn.adafruit.com/force-sensitive-resistor-fsr)
