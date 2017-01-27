import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keypad = Chroma.Keypad()

RED = (255, 0, 0)
GREEN = (0, 255, 0)

Keypad.setBreathing(1, RED, GREEN)  # sets the Keypad to Breathing with red and green
sleep(10)
Keypad.setBreathing(0, 0, 0)  # sets the Keypad to Breathing with random colors
sleep(10)
