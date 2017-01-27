import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep

Mouse = Chroma.Mouse()  # Initialize a new Mouse Instance

RED = (255, 0, 0)  # Initialize a new color by RGB (RED,GREEN,BLUE)
GREEN = (0, 255, 0)

for y in range(0, Mouse.MaxRow):  # Use Mouse.MaxRow as an iteration border in a for-loop
    Mouse.setbyGrid(3, y, RED)  # sets the whole fourth column to green

for x in range(0, Mouse.MaxColumn):  # Use Mouse.MaxColumn as iteration border in a for-loop
    Mouse.setbyGrid(x, 2, GREEN)  # sets the whole third row to green

Mouse.applyGrid()  # applies the Mouse-Grid to the connected Mouse
sleep(5)
