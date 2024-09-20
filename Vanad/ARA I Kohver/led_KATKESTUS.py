import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BOARD)
GPIO.setwarnings(False)
GPIO.setup(8, GPIO.OUT)
GPIO.setup(10, GPIO.OUT)
GPIO.setup(12, GPIO.OUT)

GPIO.setup(16, GPIO.OUT)
GPIO.setup(18, GPIO.OUT)

GPIO.setup(22, GPIO.OUT)
def sisse(x):
    GPIO.output(x, GPIO.HIGH)
def välja(x):
    GPIO.output(x, GPIO.LOW)
def vilgu(x):
    GPIO.output(x, GPIO.HIGH)
    time.sleep(0.3)
    GPIO.output(x, GPIO.LOW)
    time.sleep(0.3)
    GPIO.output(x, GPIO.HIGH)
    time.sleep(0.4)
    GPIO.output(x, GPIO.LOW)
    time.sleep(0.3)
    GPIO.output(x, GPIO.HIGH)
    time.sleep(0.3)
    GPIO.output(x, GPIO.LOW)
    time.sleep(0.4)

#nupu setup
GPIO.setup(40, GPIO.IN, pull_up_down=GPIO.PUD_DOWN)

def nupp():
    if GPIO.input(40) == GPIO.HIGH:
        return 1 #nupp on vajutatud
    elif GPIO.input(40) == GPIO.LOW:
        return 2 #nuppu pole vajutatud
    else:
        return "viga"
    



punaneA = 12
kollaneA = 10
rohelineA = 8
punaneJ = 18
rohelineJ = 16
sinine = 22
jalakäija = 0
käib = 0
välja(punaneA)
välja(kollaneA)
välja(rohelineA)
välja(punaneJ)
välja(rohelineJ)
välja(sinine)


def my_callback(x):
    global jalakäija
    sisse(sinine)
    jalakäija = 1
GPIO.add_event_detect(40, GPIO.RISING, callback=my_callback)

try:
    while True:
        
        if jalakäija == 1:
            välja(sinine)
            välja(punaneJ)
            sisse(rohelineJ)
            jalakäija = 0
            käib = 1
            pass
        else:
            sisse(punaneJ)
            pass

        print("Punane põleb 5 sec")
        sisse(punaneA)
        time.sleep(5)
        print("Kollane ja punane 1 sec")
        sisse(kollaneA)
        time.sleep(1)
        if käib == 1:
            välja(rohelineJ)
            sisse(punaneJ)
            käib = 0
            pass
        välja(punaneA)
        välja(kollaneA)
        print("Roheline käib 5 sec")
        sisse(rohelineA)
        time.sleep(5)
        välja(rohelineA)
        print("Kollane vilgub 3 korda kahe sekundi jooksul")
        vilgu(kollaneA)

except KeyboardInterrupt:
    print("Keyboard interrupt")
finally:
    GPIO.cleanup()
