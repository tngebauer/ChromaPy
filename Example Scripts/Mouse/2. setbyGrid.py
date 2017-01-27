import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mouse = Chroma.Mouse()  # Initialize a new Mouse Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Mouse.setbyGrid(0, 1, RED)  # sets the second led on the left side to RED. Find more information to the Chroma Grid on the official website

Mouse.applyGrid()  # applies the Mouse-Grid to the connected Mouse
sleep(5)
