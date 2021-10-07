from pynput.keyboard import Key, Controller
import time

keyboard = Controller()

for a in range(10,0,-1):
    print(a)
    time.sleep(1)

print("Started")

while True:
    try:    
        keyboard.press(Key.f5)
        keyboard.release(Key.f5)
        time.sleep(5)
    except:
        print("Stopped")
        break
