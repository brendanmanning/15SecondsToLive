import serial

ser = serial.Serial('/dev/cu.usbmodem1411', 9600);

transfer = "";

while True:
    transfer += ser.readline();
    print transfer;
