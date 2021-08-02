const int ledPin = 13;

void setup()
{
  // start serial port at 38400 bps:
  Serial.begin(38400);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(ledPin, OUTPUT);
  while (!Serial)
  {
    ;  // wait for serial port to connect.
  }
}

void loop()
{
  // if we get a command, turn the LED on or off:
  char buffer[16];

  if (Serial.available() > 0)
  {
    int size = Serial.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
    Serial.println(buffer);

    if (buffer[0] == 'Y')
    {
      digitalWrite(ledPin, HIGH);
    }
    if (buffer[0] == 'N')
    {
      digitalWrite(ledPin, LOW);
    }
  }
}
