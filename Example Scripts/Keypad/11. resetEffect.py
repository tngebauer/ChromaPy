import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keypad = Chroma.Keypad()

Keypad.setWave(0)  # sets the Keypad to Wave from left to right
sleep(5)

Keypad.resetEffect()  # resets the current Chroma Effect

sleep(5)

Keypad.setColor((255, 0, 0))  # sets new color the the Keypad
Keypad.applyGrid()
sleep(5)
