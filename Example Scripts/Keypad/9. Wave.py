import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keypad = Chroma.Keypad()

Keypad.setWave(1)  # sets the Keypad to Wave from left to right
sleep(10)
Keypad.setWave(2)  # sets the Keypad to Wave from right to left
sleep(10)
