# command formatting
# signal generator:
#	s_[shape]_[frequency]_[amplitude]_[dutycycle]
#		shape:
#			0: sine

import serial

print "function generator"

amp = int(input("enter desired amplitude (0-3.3V): "))
freq = int(input("enter desired frequency (Hz): "))
port = raw_input("enter port (COMx): ")
delay = 8.8/freq
dut = .5
ser = serial.Serial()
ser.baudrate = 9600
ser.port = ("COM"+port)
ser.open()
ser.write("s"+"_"+"0"+"_"+freq+"_"+amp+"_"+dut)
ser.close()