import serial
import time

arduino = serial.Serial(
    port="/dev/ttyACM1",
    baudrate=115200,
    bytesize=serial.EIGHTBITS,
    parity=serial.PARITY_NONE,
    stopbits=serial.STOPBITS_ONE,
    timeout=5,
    xonxoff=False,
    rtscts=False,
    dsrdtr=False,
    write_timeout=2,
)

while True:
    try:
        arduino.write("Command from Jetson|".encode())
        data = arduino.readline()
        if data:
            print(data)
    except Exception as e:
        print(e)
        arduino.close()
