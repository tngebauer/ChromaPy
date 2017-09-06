import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Headset = Chroma.Headset()  # Initialize a new Headset Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Headset.setColor(RED)  # sets the whole Headset-Grid to RED

Headset.applyLED()  # applies the Headset-Grid to the connected Headset

sleep(5)
