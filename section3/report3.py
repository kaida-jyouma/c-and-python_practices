# basic
num = int(input("Enter an even prime number:")) # ask question
if n == 2: # if correct
    print("Correct")
else: # if wrong
    print("the answer is 2.")

# extra

# import modules
import random as rdm
from time import time

numl = [rdm.randint(1, 99) for c in range(10)] # make question
t_start = time() # start stopwatch
print("add these ten numbers and type sum.")
print("numbers:", ", ".join(numl)) # display question
ans = int(input("answer: ")) # receive answer from keyboard
t_end = time() # stop stopwatch
past = t_end - t_start # calculate time

if ans != sum(numl): # if wrong
    print("answer is wrong...\nplease try again.")
    
else: # if correct
    if past <= 6:
        print("your calculation speed is super fast!!!")
    elif past <= 8:
        print("your calculation speed is very fast!!")
    elif past <= 10:
        print("your calculation speed is fast.")
    elif past <= 25:
        print("your calculation speed is normal.")
    else:
        print("your calculation speed is slow.")