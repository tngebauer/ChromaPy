import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keyboard = Chroma.Keyboard()  # Initialize a new Keyboard Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)
GREEN = (0, 255, 0)

for y in range(0, Keyboard.MaxRow):  # Use Keyboard.MaxRow as an iteration border in a for-loop
    Keyboard.setbyGrid(3, y, RED)  # sets the whole fourth column to green

for x in range(0, Keyboard.MaxColumn):  # Use Keyboard.MaxColumn as iteration border in a for-loop
    Keyboard.setbyGrid(x, 2, GREEN)  # sets the whole third row to green

Keyboard.applyGrid()  # applies the Keyboard-Grid to the connected Keyboard
sleep(5)
