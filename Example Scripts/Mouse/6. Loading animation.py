import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Mouse = Chroma.Mouse()  # Initialize a new Mouse Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)

for x in range(0, Mouse.MaxColumn):  # for-loop with Mouse.MaxColumn as iteration border
    Mouse.setbyCol(x, RED)  # set the x-th row to RED
    Mouse.applyGrid()  # applies the Mouse-Grid to the connected Mouse
    sleep(0.1)  # sleeps 100ms until next row will be filled
