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
}

void getControlData(const int &throttle, const int &steering)
{
  char buffer[16];
  char *strokBufer;

  if (Serial.available() > 0)
  {
    int size = Serial.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
    Serial.println(buffer);

    strokBufer = strtok(buffer, ",");
    throttle = atoi(strokBufer);
    Serial.println(throttle);

    strokBufer = strtok(NULL, ",");
    steering = atoi(strokBufer);
    Serial.println(steering);

    // if (serial_input[0] == 'Y')
    // {
    //   digitalWrite(LED_BUILTIN, HIGH);
    // }
    // if (serial_input[0] == 'N')
    // {
    //   digitalWrite(LED_BUILTIN, LOW);
    // }
  }
}