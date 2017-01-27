import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Headset = Chroma.Headset()  # Initialize a new Headset Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Headset.setbyLED(1,
                 RED)  # sets the second led of the Headset to red. Find more information to the Chroma Grid on the official website

Headset.applyLED()  # applies the Headset-Grid to the connected Headset

sleep(5)
