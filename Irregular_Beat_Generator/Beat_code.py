#Irregular_Beat_Generator
import math
import pygame as pg
import matplotlib.pyplot as plt

pg.init()
#Math library to caculate interpolation functions
#Pygame library for playing sound

BPM = int(input("Enter a BPM: "))
#time_signature = ("Enter a time signature: ")

measure_length = (60 / BPM) * 4 # 60 / bpm = beats per second * 4 amount of seconds for a measure
print(measure_length)
# TO DO: PRNG: LCG

# LCG functie; takes in amount of numbers that need to be generated and a seed.
seed = int(input( "Enter a random number: "))

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
mu = LCG(9, seed + 10) #where a t is located between two set intervals
print(lcg_numbers)

#TO DO: coupling the generated numbers to values at set intervals (time + value pairs).

set_intervals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]

# Dictionary with computed data
generated_graph_data = {
  "intervals": set_intervals,
  "values": lcg_numbers,
  "mu": mu
}


#print(generated_graph_data)
"""
TO DO: Lineaire Interpolatie between set intervals on grid.
#Linear Interpolation
"""
def linearInterpolate(y1, y2, mu):
  return (y2 - y1) * mu + y1


#TO DO: Rounding of linear function
#Cosine Step Interpolation
def cosineInterpolate(y1, y2, mu):
  angle = mu * math.pi 
  mu2 = (1.0 - math.cos(angle)) * 0.5 # get new x-value based on cosine function
  return linearInterpolate(y1, y2, mu2)


#TO DO: Generate list of steps that are played based on chance
step_grid = []

for i in range(lcg_numbers):
  if lcg_numbers[i] >= mu[i]:
    step_grid.append(True)
  else:
    step_grid.append(False)

print(step_grid)


#TO DO: Think of way to add value to gtid
#Plot generated graph
time = set_intervals
chance = lcg_numbers

plt.plot(time, chance, mu)

plt.xlabel('Time')
plt.ylabel("Chance")
plt.title("Plot")

plt.show()
