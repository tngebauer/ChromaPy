import ChromaPy
from time import sleep

Keyboard = ChromaPy.Keyboard()
Mouse = ChromaPy.Mouse()
Mousepad = ChromaPy.Mousepad()
Bulb = ChromaPy.SmartHome("192.168.0.64")

Bulb.power("on")

RED = (255,0,0)
BLUE = (0,0,255)
GREEN = (0,255,0)




while True:

    Keyboard.setColor(BLUE)
    Keyboard.applyGrid()
    Mouse.setColor(BLUE)
    Mouse.applyGrid()
    Mousepad.setColor(BLUE)
    Mousepad.applyLED()
    Bulb.setColor(BLUE)
    sleep(2)
    Keyboard.setColor(RED)
    Keyboard.applyGrid()
    Mouse.setColor(RED)
    Mouse.applyGrid()
    Mousepad.setColor(RED)
    Mousepad.applyLED()
    Bulb.setColor(RED)
    sleep(2)
    Keyboard.setColor(GREEN)
    Keyboard.applyGrid()
    Mouse.setColor(GREEN)
    Mouse.applyGrid()
    Mousepad.setColor(GREEN)
    Mousepad.applyLED()
    Bulb.setColor(GREEN)
    sleep(2)
