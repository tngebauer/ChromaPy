import ChromaPy32 as Chroma  # Headset the Chroma Module
from time import sleep

Headset = Chroma.Headset()  # Initialize a new Headset Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for led in range(0, Headset.MaxLED):  # Use Headset.MaxLED as an iteration border in a for-loop
    Headset.setbyLED(led, RED)  # sets all LED to red

Headset.applyLED()  # applies the Headset-Grid to the connected Headset

sleep(5)
