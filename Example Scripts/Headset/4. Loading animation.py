import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Headset = Chroma.Headset()  # Initialize a new Headset Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for x in range(0, Headset.MaxLED):  # for-loop with Headset.MaxLED as iteration border
    Headset.setbyLED(x, RED)  # set the x-th led to red
    Headset.applyLED()  # applies the Headset-Grid to the connected Headset
    sleep(0.1)  # sleeps 100ms until next row will be filled
