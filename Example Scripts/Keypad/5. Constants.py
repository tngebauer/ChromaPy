import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)
GREEN = (0, 255, 0)

for y in range(0, Keypad.MaxRow):  # Use Keypad.MaxRow as an iteration border in a for-loop
    Keypad.setbyGrid(y, 3, RED)  # sets the whole fourth column to green

for x in range(0, Keypad.MaxColumn):  # Use Keypad.MaxColumn as iteration border in a for-loop
    Keypad.setbyGrid(x, 2, GREEN)  # sets the whole third row to green

Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad
sleep(5)
