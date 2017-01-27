import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keyboard = Chroma.Keyboard()  # Initialize a new Keyboard Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keyboard.setbyCol(3, RED)  # sets the whole fourth column of the Keyboard-Grid to red

Keyboard.applyGrid()  # applies the Keyboard-Grid to the connected Keyboard
sleep(5)
