int throttle = 0;
int steering = 0;

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
  getControlData(throttle, steering);
}

void getControlData(int &throttle, int &steering)
{
  char buffer[16];
  char *strokBufer;

  if (Serial.available() > 0)
  {
    int size = Serial.readBytesUntil('\n', buffer, sizeof(buffer) - 1);
    Serial.println(buffer);

    strokBufer = strtok(buffer, ",");
    throttle = atoi(strokBufer);
    Serial.print("Throttle : ");
    Serial.println(throttle);

    strokBufer = strtok(NULL, ",");
    steering = atoi(strokBufer);
    Serial.print("Steering : ");
    Serial.println(steering);
  }
}