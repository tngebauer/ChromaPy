import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keyboard = Chroma.Keyboard()

RED = (255, 0, 0)
GREEN = (0, 255, 0)

Keyboard.setBreathing(1, RED, GREEN)  # sets the Keyboard to Breathing with red and green
sleep(10)
Keyboard.setBreathing(0, 0, 0)  # sets the Keyboard to Breathing with random colors
sleep(10)
