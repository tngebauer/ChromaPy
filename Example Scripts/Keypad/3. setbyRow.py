import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keypad.setbyRow(2, RED)  # sets the whole third row of the Keyboad-Grid to red

Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad
sleep(5)
