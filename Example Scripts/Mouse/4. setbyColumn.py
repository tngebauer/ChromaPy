import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mouse = Chroma.Mouse()  # Initialize a new Mouse Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Mouse.setbyCol(0, RED)  # sets the whole first column of the Mouse-Grid to red

Mouse.applyGrid()  # applies the Mouse-Grid to the connected Mouse
sleep(5)
