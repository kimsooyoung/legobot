/*
 Lego Powerfunctions car model controlled over bluetooth
 Arduino Uno controls motors and servo
 Remote controlled with android app developed with MIT App Inventor 2

 Circuit:
 * Serial communication   (uses Uno pin 0,1)    Bluetooth-module is attached (has to be detached when loading program
 over USB)
 * L293D with motor       (uses Uno digital pins 2,5,9)
 * L293D with servo       (uses Uno digital pins 6,8,3)
*/

// Used libraries:
#include <SPI.h>  // Serial Peripheral Interface Library
#include <Servo.h>
// #include <String.h>                          // contains function strtok: split string into tokens

Servo myservo;  // create servo object to control a servo, twelve servo objects can be created on most boards

// Motor control digital output pins defined as global constants (4 wheel drive with 2 Lego motors):
const int8_t controlPin1A = 2;         // L293D driver input 1A on pin no 2  http://www.ti.com/lit/ds/symlink/l293.pdf
                                       // connected to Arduino digital output pin 2
const int8_t controlPin2A = 5;         // L293D driver input 2A on pin no 7 connected to Arduino digital output pin 5
const int8_t throttleControlPin = 11;  // L293D ENable(1,2) input on pin no 1 connected to Arduino digital output pin 9

// Servo PWM control Pinout
const int8_t servoControlPin = 9;

// Motor control global variables:
int8_t motorSpeed = 0;  // Motor speed 0..255
int8_t servoAngle = 0;  // variable to store the servo position

int8_t motorDirection = 1;  // Forward (1) or reverse (0)

void setup()
{
  Serial.begin(9600);       // initialize serial communication
  Serial.setTimeout(1000);  // 1000 ms time out

  myservo.attach(servoControlPin);  // attaches the servo on pin 9 to the servo object
  myservo.write(0);
  // Declare digital output pins:
  pinMode(controlPin1A, OUTPUT);          // 1A
  pinMode(controlPin2A, OUTPUT);          // 2A
  pinMode(throttleControlPin, OUTPUT);    // EN1,2
  digitalWrite(throttleControlPin, LOW);  // motor off
}

void loop()
{
  auto speed = getThrottle();
  auto angle = getSteering();
  SetMotorControl(speed, angle);  // adjust motor direction and speed
}

/*
L293 logic:    EN1,2   1A    2A
               H       H     L    Motor turns left  (Forward; motorDirection == 1)
               H       L     H    Motor turns right (Reverse; motorDirection == 0)

Motor speed:   PWM signal on EN1,2 (490 Hz; digital output value 0..255 for motorSpeed)
*/
void SetMotorControl(const int &speed, const int &angle)
{
  //  String print_str = "Motor Speed" + speed;
  Serial.print("Set Motor Throttle : ");
  Serial.println(speed);
  if (motorDirection == 1)  // Forward
  {
    digitalWrite(controlPin1A, HIGH);
    digitalWrite(controlPin2A, LOW);
  }
  else  // Reverse
  {
    digitalWrite(controlPin1A, LOW);
    digitalWrite(controlPin2A, HIGH);
  }
  analogWrite(throttleControlPin, speed);  // Speed

  Serial.print("Set Motor Steeiring : ");
  Serial.println(angle);
  myservo.write(angle);  // tell servo to go to position in variable 'pos'
}

int getThrottle()
{
  Serial.println(" ** Type Throttle  ** ");
  while (Serial.available() == 0)
  {
  }
  auto return_val = Serial.parseInt();

  return return_val;
}

int getSteering()
{
  Serial.println(" ** Type Angle ** ");
  while (Serial.available() == 0)
  {
  }
  auto return_val = Serial.parseInt();

  return return_val;
}
