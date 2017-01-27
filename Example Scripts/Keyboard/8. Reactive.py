import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keyboard = Chroma.Keyboard()

RED = (255, 0, 0)


Keyboard.setReactive(1, RED)  # sets the Keyboard to Reactive with short duration
sleep(10)
Keyboard.setReactive(2, RED)  # sets the Keyboard to Reactive with medium duration
sleep(10)
Keyboard.setReactive(3, RED)  # sets the Keyboard to Reactive with long duration
sleep(10)
