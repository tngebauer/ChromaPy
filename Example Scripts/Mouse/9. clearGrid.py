import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keypad.setbyGrid(1, 0, RED)  # sets the ESC-Key to RED. More information about the Grid are on the official website

Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad
sleep(5)

Keypad.clearGrid()  # clears the Grid
Keypad.applyGrid()  # applies the cleared Grid to the connected Keypad

sleep(5)

