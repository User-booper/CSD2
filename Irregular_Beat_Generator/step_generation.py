import math
import pygame as pg
import matplotlib.pyplot as plt

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

lcg_numbers = LCG(10, seed)
mu = LCG(23, seed + 15) #where a t is located between two set intervals

#print("lcg: ", lcg_numbers)
#print("mu: ", mu)
step_grid = []

#TO DO: function to compare the values within two generated lists
#One list contains the graph positions of some lcg generated numbers and the other one
#contains values to test them against. If the lcg number is higher th
def create_note_durs(value, chance_value):
    for (value_lcg, chance) in zip(value, chance_value): #compares the two lists to see if the value of lcg is higher than the chance
        if value_lcg >= chance:
            step_grid.append(0.25)
        else:
            step_grid.append(0)
    return step_grid


print(create_note_durs(lcg_numbers, mu))


#def create_note_dur(grid):
#   note_durs = []

#   for x in range(len(grid)):
#        if x == True:
#           note_durs.append(0.25)
#        else:
#           note_durs.append(0)
#   return note_durs

#print(create_note_dur(step_grid))
   
