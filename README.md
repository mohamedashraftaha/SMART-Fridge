# System Description


![image](https://user-images.githubusercontent.com/75078872/166977531-cfe680f6-426d-48f2-8a11-178a2daf2e73.png)



The goal of our project is to implement a SMART Fridge. With our Embedded system, it is much easier for shop owners to **keep track of the capacity** of the products. This is done by contacting the vendors and asking for product supply in case the shop/user has run out of enough stock. Our system also facilitates the maintenance procedures of the fridges, since it provides a sensor that makes sure that the temperature of the fridge is maintained to a certain acceptable value that will preserve the quality of the products stored inside it. We are also using a telegram bot by which we can keep track of the system conditions. Moreover, we are using cayenne which is an IoT analytics platform service that allows you to aggregate, visualize, and analyze live data streams in the cloud, to maintain our system and provide support in case of malfunctions.

# Team Members
* Mohamed Ashraf Taha
* Mohamed El-shenawy
* Omar ElMahdy

# Hardware Requirements
* 1 ESP32
* 1 STM32L432KC
* 1 LM35DZ (Temperature Sensor)
* 1 LEDs
* 1 MS5540C (Pressure Sensor)
* 1 HMC5883L (GPS module)
* 1 RKI3141        IR Infrared Obstacle Avoidance Sensor
* 3 10KΩ Resistors
* 3 800Ω Resistors
* Breadboard
* Jumper wires

# Software Requirements
* STM32CubeMX
* Keil uVision
* TeraTerm
* Arduino IDE
* FreeRTOS
* CMSIS_V2

# System Design

![image](https://user-images.githubusercontent.com/75078872/166977931-3fdaec72-9a9d-4ae8-9d69-183ac9be83a4.png)

# Physical Connections
**In Progress**

# First Prototype

Progress:

In this milestone, we were able to interface with our temperature sensor (as shown in the prototype demo). We also were able to configure the ESP32 wifi module to connect to cayenne, which is an IoT analytics platform service.

Next Steps:
- We are currently trying a more suitable pressure sensor for our project
- we will send the temperature values produced by the temperature sensor to ESP32 to be sent to cayenne to analyze the results
- we will start working on the GPS as a final step in our project.
- We are currently working on connecting to telegram bot and WhatsApp Bot
- we are working on the logic of the pwm that will mimic the AC

Prototype Demo: https://drive.google.com/file/d/1nfIpaBxZxsNidFfPM9dbTh3mpdhAGIvq/view?usp=sharing


# Second Prototype
**In Progress**
# Final Prototype
 **In Progress**

# Limitations
**In Progress**

# References
1. [ESP32 Telegram](https://randomnerdtutorials.com/telegram-control-esp32-esp8266-nodemcu-outputs/)
2. [ESP32 WhatsApp ](https://www.youtube.com/watch?v=in3W1d_BpXw)
3. [ThingESP Platform](https://github.com/SiddheshNan/ThingESP-Arduino-Library)
4. [LM35DZ Datasheet](https://www.ti.com/lit/ds/symlink/lm35.pdf)
