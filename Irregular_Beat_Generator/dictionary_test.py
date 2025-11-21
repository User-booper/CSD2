"""
File to test dictionary handling.
TODO
Add list as an argument to a dictionary, so timestamps
and sample name can be read together by as an event

"""

import pygame as pg
import time
#
lcg_timestamps = [1, 5, 10, 15, 20, 25, 30, 35]
mu_timestamps = [0.30, 0.70, 1.0, 1.125, 1.375, 1.75]


pg.mixer.init()
hihat_sample = pg.mixer.Sound("/Users/laurabreukhoven/Desktop/HKU/jaar2/CSD2/Irregular_Beat_Generator/hihat.wav")
snare_sample = pg.mixer.Sound("/Users/laurabreukhoven/Desktop/HKU/jaar2/CSD2/Irregular_Beat_Generator/snare.wav")
kick_sample = pg.mixer.Sound("/Users/laurabreukhoven/Desktop/HKU/jaar2/CSD2/Irregular_Beat_Generator/kick.wav")

snare = snare_sample
kick = kick_sample
"""
make_event_dict is a function that takes in the name of a sample and 
a list of timestamps, and updates a dictionary named event with those 
values as values and "sample" and"timestamps" as keys
"""
def make_event_dict(sampleName, timestamps):
    event = {}
    event.update({"sample": sampleName})
    event.update({"timestamps": timestamps})
    return event

snare_events = make_event_dict(snare, lcg_timestamps)
kick_events = make_event_dict(kick, mu_timestamps)

print(snare_events)

"""
TODO make a handle_note_event function that 

"""
def handle_note_event(sample):
    sample.set_volume(1)
    sample.play

start_time = time.time()
time_now = time.time() - start_time 


for timestamp in snare_events["timestamps"]:
   if start_time > timestamp:
       handle_note_event(snare)
       print("snare, ", "timestamp: ", timestamp)
   time.sleep(0.5)

   
"""
time.sleep(0.5)
snare.set_volume(1)
snare.play

"""