import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mousepad = Chroma.Mousepad()  # Initialize a new Mousepad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Mousepad.setColor(RED)  # sets the whole Mousepad-Grid to RED

Mousepad.applyLED()  # applies the Mousepad-Grid to the connected Mousepad

sleep(5)
