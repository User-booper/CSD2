import math
import pygame as pg
import time
import matplotlib.pyplot as plt




bpm = 120
quarter_note_dur = 60 / bpm
sixteenth_note_dur = quarter_note_dur / 4
seed = 1298


def LCG(amount_of_numbers, start_int):
  a = 1664525
  b = 10013904223
  m = 2**31 - 1 
  lcg_generated_numbers = []
  
  for number in range(amount_of_numbers):
    generated_number = (a * start_int + b) % m #calculates number[0] and ads it to the end of a list.
    rounded_number = round(generated_number / m, 2) #scale the number between 0 -1, round to two decimals.
    lcg_generated_numbers.append(rounded_number) # add rounded number to list.

    start_int = generated_number #the generated number is used as the start_int for the next iteration.

  return lcg_generated_numbers 

lcg_numbers = LCG(16, seed)
mu = LCG(16, seed + 15) #where a t is located between two set intervals

print("lcg: ", lcg_numbers)
print("mu: ", mu)


#TO DO: function to compare the values within two generated lists
#One list contains the graph positions of some lcg generated numbers and the other one
#contains values to test them against. If the lcg number is higher than the chance it outputs the steps that
# are to be played.
def create_note_steps(value, chance_value):
    step_grid = []
    sum = 1
    for (value_lcg, chance) in zip(value, chance_value): #compares the two lists to see if the value of lcg is higher than the chance
        if value_lcg >= chance: #if value is higher the step is added to a new list
            step_grid.append(sum)
            sum += 1
        else:
           sum += 1
            #step_grid.append(0)
          
    return step_grid

note_steps = create_note_steps(lcg_numbers, mu)
print("steps: ", note_steps)

#TO DO;
#Transform note_durs to time_stamps
# Find a way to incorporate different, note_durations (rn its just playing or not playing)

def create_time_stamps(stepList):
   timestamps = []
   for step in stepList:
      timestamps.append(step * sixteenth_note_dur)
   return timestamps

time_stamps = create_time_stamps(note_steps)
print("time_stamps: ", time_stamps)

#TO DO: Play sounds with dictionary 

