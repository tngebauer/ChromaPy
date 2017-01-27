import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mousepad = Chroma.Mousepad()  # Initialize a new Mousepad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for led in range(0, Mousepad.MaxLED):  # Use Mousepad.MaxRow as an iteration border in a for-loop
    Mousepad.setbyLED(led, RED)  # sets all LED to red

Mousepad.applyLED()  # applies the Mousepad-Grid to the connected Mousepad

sleep(5)
