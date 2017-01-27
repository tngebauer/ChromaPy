import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Mousepad = Chroma.Mousepad()

Mousepad.setWave(1)  # sets the Keypad to Wave from left to right
sleep(10)
Mousepad.setWave(2)  # sets the Keypad to Wave from right to left
sleep(10)
