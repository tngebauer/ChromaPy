import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keyboard = Chroma.Keyboard()  # Initialize a new Keyboard Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for x in range(0, Keyboard.MaxColumn):  # for-loop with Keyboard.MaxColumn as iteration border
    Keyboard.setbyCol(x, RED)  # set the x-th row to RED
    Keyboard.applyGrid()  # applies the Keyboard-Grid to the connected Keyboard
    sleep(0.1)  # sleeps 100ms until next row will be filled
