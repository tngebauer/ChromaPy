import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keyboard = Chroma.Keyboard()

Keyboard.setWave(1)  # sets the Keyboard to Wave from left to right
sleep(10)
Keyboard.setWave(2)  # sets the Keyboard to Wave from right to left
sleep(10)
