import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Keyboard = Chroma.Keyboard()  # Initialize a new Keyboard Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Keyboard.setbyGrid(1, 0,
                   RED)  # sets the ESC-Key to RED. Find more information to the Chroma Grid on the official website

Keyboard.applyGrid()  # applies the Keyboard-Grid to the connected Keyboard
sleep(5)
