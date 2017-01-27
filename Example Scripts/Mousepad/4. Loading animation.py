import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Mousepad = Chroma.Mousepad()  # Initialize a new Mousepad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for x in range(0, Mousepad.MaxLED):  # for-loop with Mousepad.MaxLED as iteration border
    Mousepad.setbyLED(x, RED)  # set the x-th led to red
    Mousepad.applyLED()  # applies the Mousepad-Grid to the connected Mousepad
    sleep(0.1)  # sleeps 100ms until next row will be filled
