import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for x in range(0, Keypad.MaxColumn):  # for-loop with Keypad.MaxColumn as iteration border
    Keypad.setbyCol(x, RED)  # set the x-th row to RED
    Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad
    sleep(0.1)  # sleeps 100ms until next row will be filled
