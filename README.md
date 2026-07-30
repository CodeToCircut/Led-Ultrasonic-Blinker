# Led-Ultrasonic-Blinker
# Arduino Proximity LED Blinker 🚀

This project uses an Arduino Uno and an HC-SR04 ultrasonic sensor to control the blink rate of an LED. As an object moves closer to the sensor, the LED blinks faster. As it moves away, the blink rate slows down.

## 🛠️ Components Needed
*   Arduino Uno R3
*   HC-SR04 Ultrasonic Sensor
*   1x Standard LED (Any color)
*   Jumper wires

## 🔌 Wiring Diagram

| HC-SR04 Pin | Arduino Pin |
| :--- | :--- |
| VCC | 5V |
| GND | GND |
| Trig | Pin 9 |
| Echo | Pin 10 |

**LED:** 
Plug the long leg (Anode) directly into **Pin 13**, and the short leg (Cathode) into the **GND** pin right next to it. 
*(Note: For long-term use, it is highly recommended to wire the LED to a breadboard with a 220Ω current-limiting resistor to protect the LED and the Arduino).*

## 🧠 How the Code Works
Instead of using the standard `delay()` function (which pauses the entire Arduino and makes sensor readings laggy), this project uses `millis()` for non-blocking timing. 

1. The sensor sends out an ultrasonic ping and calculates the return time.
2. The time is converted into distance (centimeters).
3. The Arduino's `map()` function translates the distance (2cm - 50cm) into a blink interval (50ms - 1000ms).
4. The LED updates its blink rate instantly without stopping the sensor from taking new readings.

## 🚀 Installation
1. Clone this repository or download the `.ino` file.
2. Open the file in the [Arduino IDE](https://www.arduino.cc/en/software).
3. Connect your Arduino Uno via USB.
4. Select your board and port under `Tools > Board` and `Tools > Port`.
5. Click **Upload** and test it out!
