# command formatting
# separate values by :

# first value: command type (2 chars)
# sw: generate sine wave
#       second value: amplitude (4 chars - 10 bits used, 16 bits total)
#           0000: 0 volts
#           1023: 3.3 volts
#       third value:  frequency


# example command:
# 00:3ff:

import serial


# amp = int(input("enter desired amplitude (0-3.3V): "))
# freq = int(input("enter desired frequency (Hz): "))
# port = raw_input("enter port (COMx): ")
# delay = 8.8/freq
# dut = .5

port = 4
amp = 3.3
type = 0

ser = serial.Serial()
ser.baudrate = 9600
ser.port = ("/dev/cu.usbmodem1411")
ser.open()
ser.flushInput()
ser.flushOutput()

ser.write("sw1023")

while 1:
    print ser.readline()

ser.close()

