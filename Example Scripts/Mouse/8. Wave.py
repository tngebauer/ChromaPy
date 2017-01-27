import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Mouse = Chroma.Mouse()

Mouse.setWave(1)  # sets the Keypad to Wave from top to bottom
sleep(10)
Mouse.setWave(2)  # sets the Keypad to Wave from bottom to top
sleep(10)
