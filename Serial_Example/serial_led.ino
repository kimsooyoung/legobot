void setup()
{
  // start serial port at 9600 bps:
  Serial.begin(9600);
  // initialize digital pin LED_BUILTIN as an output.
  pinMode(LED_BUILTIN, OUTPUT);
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
      digitalWrite(LED_BUILTIN, HIGH);
    }
    if (buffer[0] == 'N')
    {
      digitalWrite(LED_BUILTIN, LOW);
    }
  }
}
