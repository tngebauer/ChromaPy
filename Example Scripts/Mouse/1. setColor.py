import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mouse = Chroma.Mouse()  # Initialize a new Mouse Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Mouse.setColor(RED)  # sets the whole Mouse-Grid to RED

Mouse.applyGrid()  # applies the Mouse-Grid to the connected Mouse

sleep(5)
