import ChromaPy32 as Chroma  # mport the Chroma Module
from time import sleep

Keypad = Chroma.Keypad()  # Initialize a new Keypad Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keypad.setbyCol(3, RED)  # sets the whole fourth column of the Keypad-Grid to red

Keypad.applyGrid()  # applies the Keypad-Grid to the connected Keypad
sleep(5)
