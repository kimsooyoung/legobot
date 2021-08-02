# http://blog.rareschool.com/2019/05/five-steps-to-connect-jetson-nano-and.html

import serial

with serial.Serial("/dev/ttyACM0", 38400, timeout=10) as ser:
    while True:
        throttle = input("type throttle : ")
        steering = input("type steering : ")
        send_msg = throttle + "," + steering + "," + "\n"
        ser.write(bytes(send_msg, "utf-8"))
