import ChromaPy32 as Chroma  # Import the Chroma Module
from time import sleep  # Import the sleep-function

Keypad = Chroma.Keypad()

RED = (255, 0, 0)


Keypad.setReactive(1, RED)  # sets the Keypad to Reactive with short duration
sleep(10)
Keypad.setReactive(2, RED)  # sets the Keypad to Reactive with medium duration
sleep(10)
Keypad.setReactive(3, RED)  # sets the Keypad to Reactive with long duration
sleep(10)
