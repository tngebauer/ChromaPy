import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Mousepad = Chroma.Mousepad()

RED = (255, 0, 0)
GREEN = (0, 255, 0)

Mousepad.setBreathing(1, RED, GREEN)  # sets the Mousepad to Breathing with red and green
sleep(10)
Mousepad.setBreathing(0, 0, 0)  # sets the Mousepad to Breathing with random colors
sleep(10)
