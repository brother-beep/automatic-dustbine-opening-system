#include <Servo.h>

// Pin definitions
#define TRIG_PIN 9
#define ECHO_PIN 10
#define SERVO_PIN 6

Servo lidServo;

// Distance threshold in cm
int threshold = 10;

void setup()
{
  Serial.begin(9600);

  pinMode(TRIG_PIN, OUTPUT);
  pinMode(ECHO_PIN, INPUT);

  lidServo.attach(SERVO_PIN);
  lidServo.write(0); // initial position (lid closed)
}

long getDistance()
{
  digitalWrite(TRIG_PIN, LOW);
  delayMicroseconds(2);

  digitalWrite(TRIG_PIN, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG_PIN, LOW);

  long duration = pulseIn(ECHO_PIN, HIGH);

  long distance = duration * 0.034 / 2; // convert to cm

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
    Serial.println("Object detected → Opening lid");

    lidServo.write(90);   // open lid
    delay(3000);          // keep open for 3 seconds
  }
  else
  {
    Serial.println("No object → Closing lid");

    lidServo.write(0);    // close lid
  }

  delay(300);
}