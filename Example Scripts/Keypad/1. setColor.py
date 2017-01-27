import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keypad.setColor(RED)  # sets the whole Keypad-Grid to RED

Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad

sleep(5)
