import serial
import time
from datetime import datetime
# uncomment line 5&6 if you do not have these 2 modules installed
# import subprocess
# subprocess.run(["pip", "install", "matplotlib"])
from matplotlib import pyplot

# creating communication with Arduino
arduino = serial.Serial("COM4", baudrate=9600)
time.sleep(2)

# asking user for option
choice = input("1 for requesting data / 2 for graphical display of data \n")

if choice == "1":
    # sending byte to Arduino
    arduino.write(choice.encode())

    # receiving data from Arduino
    data = arduino.readline().decode().strip()

    # data = data.split(",")
    now = datetime.now().strftime("%d/%m/%Y %H:%M")
    inData = now + "," + data + "\n"

    #creating and/or writing to file
    with open("data.txt", "a+") as file:
        file.write(inData)

if choice == "2":
    x = []
    y = []
    with open("data.txt", "r") as file:
        for line in file.readlines():
            myList = line.split(",")
            myList[0] = datetime.strptime(myList[0], "%d/%m/%Y %H:%M")
            for i in range(1, 6):
                myList[i] = float(myList[i])

            x.append(myList[0])
            y.append(sum(myList[1:6]) / 5)
        
        pyplot.plot(x, y, marker="o")
        pyplot.title("Average temperature when requested")
        pyplot.xlabel("Date & Time")
        pyplot.ylabel("Temperature in Celsius")
        pyplot.show()
