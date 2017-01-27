import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mouse = Chroma.Mouse()  # Initialize a new Mouse Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

Mouse.setbyRow(2, RED)  # sets the whole third row of the Keyboad-Grid to red

Mouse.applyGrid()  # applies the Mouse-Grid to the connected Mouse
sleep(5)
