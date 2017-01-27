import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keypad.setbyGrid(0, 1,RED)  # sets the second led in the first row to RED. Find more information to the Chroma Grid on the official website

Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad
sleep(5)
