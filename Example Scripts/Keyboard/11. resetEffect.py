import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keyboard = Chroma.Keyboard()

Keyboard.setWave(0)  # sets the Keyboard to Wave from left to right
sleep(5)

Keyboard.resetEffect()  # resets the current Chroma Effect

sleep(5)

Keyboard.setColor((255, 0, 0))  # sets new color the the keyboard
Keyboard.applyGrid()
sleep(5)