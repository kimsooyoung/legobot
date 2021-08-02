# legobot

## Examples

1. Serial Communication btw Jetson <=> Arduino

* Insert USB Cable from Arduino to Jetson
* Search USB Cable name at Jetson terminal 
```
$ cd /dev
$ ls | grep ttyACM 
or 
$ ls | grep ttyUSB
```

in my case, it was `ttyACM1`

* Upload `Serial_Example/serial_led.ino` into Arduino

* Execute command send client from Jetson.
```
$ pip install pyserial

# On Jetson
$ python Serial_Example/serial_led.py
Do you want the LED on? y
Do you want the LED on? n
Do you want the LED on? n
Do you want the LED on? y
...
```

| You can control Arduino LED from Jetson side.

