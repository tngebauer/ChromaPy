import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mousepad = Chroma.Mousepad()  # Initialize a new Mousepad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Mousepad.setbyLED(1,
                  RED)  # sets the second led of the Mousepad to red. Find more information to the Chroma Grid on the official website

Mousepad.applyLED()  # applies the Mousepad-Grid to the connected Mousepad

sleep(5)
