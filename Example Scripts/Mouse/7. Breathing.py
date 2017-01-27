import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Mouse = Chroma.Mouse()

RED = (255, 0, 0)
GREEN = (0, 255, 0)

Mouse.setBreathing(1, RED, GREEN)  # sets the Keypad to Breathing with red
sleep(10)
Mouse.setBreathing(0, 0, 0)  # sets the Keypad to Breathing with random colors
sleep(10)