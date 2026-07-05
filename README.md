# Automatic Dustbin Opening System using Arduino Uno

## Overview

The **Automatic Dustbin Opening System** is a simple contactless automation project built using an **Arduino Uno**, an **HC-SR04 Ultrasonic Sensor**, and an **SG90 Servo Motor**. The system detects the presence of a hand or object near the dustbin and automatically opens the lid. After a few seconds, the lid closes automatically, providing a hygienic and touch-free waste disposal experience.

This project is ideal for beginners learning Arduino programming, embedded systems, and sensor interfacing.

---

## Features

* Contactless dustbin operation
* Automatic lid opening and closing
* Real-time distance measurement
* Easy-to-build and low-cost design
* Beginner-friendly Arduino project

---

## Components Required

* Arduino Uno
* HC-SR04 Ultrasonic Sensor
* SG90 Servo Motor (or any compatible servo)
* Breadboard
* Jumper Wires
* USB Cable
* External 5V Power Supply (recommended for stable servo operation)

---

## Circuit Connections

### HC-SR04 Ultrasonic Sensor

| HC-SR04 Pin | Arduino Uno    |
| ----------- | -------------- |
| VCC         | 5V             |
| GND         | GND            |
| TRIG        | Digital Pin 9  |
| ECHO        | Digital Pin 10 |

### Servo Motor

| Servo Wire             | Arduino Uno                    |
| ---------------------- | ------------------------------ |
| Signal (Orange/Yellow) | Digital Pin 6                  |
| VCC (Red)              | 5V *(External 5V recommended)* |
| GND (Brown/Black)      | GND                            |

> **Important:** If using an external 5V supply for the servo, connect the external power supply ground to the Arduino GND (common ground).

---

## Working Principle

1. The HC-SR04 ultrasonic sensor continuously measures the distance to nearby objects.
2. When a hand or object is detected within **20 cm**, the Arduino commands the servo motor to rotate and open the dustbin lid.
3. The lid remains open for approximately **3 seconds**.
4. The servo then returns to its initial position, closing the lid automatically.
5. The measured distance is continuously displayed on the Serial Monitor.

---

## Arduino Code

```cpp
#include <Servo.h>

#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 6

Servo lidServo;

int threshold = 20;

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(SERVO_PIN);
  lidServo.write(0);
}

long getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  long distance = duration * 0.034 / 2;

  return distance;
}

void loop()
{
  long distance = getDistance();

  Serial.print("Distance: ");
  Serial.print(distance);
  Serial.println(" cm");

  if (distance > 0 && distance <= threshold)
  {
    lidServo.write(90);
    delay(3000);
  }
  else
  {
    lidServo.write(0);
  }

  delay(300);
}
```

---

## Applications

* Smart Homes
* Touch-Free Dustbins
* Hospitals and Clinics
* Offices
* Schools and Universities
* Public Hygiene Systems

---


---


```

---

## License

This project is licensed under the MIT License.

---

## Author

**Mehadi Hasan Bijoy**

Electrical & Electronic Engineering

Embedded Systems | Arduino | IoT Enthusiast
