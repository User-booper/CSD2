import math
import pygame as pg
import time
import matplotlib.pyplot as plt
import step_generation as sg

seed = 15 #int(input("Enter a number: "))

lcg_numbers = sg.LCG(16, seed)
mu = sg.LCG(16, seed + 15)

note_steps = sg.create_note_steps(lcg_numbers, mu)
print("steps: ", note_steps)

time_stamps = sg.create_time_stamps(note_steps)
print("time_stamps: ", time_stamps)


pg.mixer.init()
hihat_sample = pg.mixer.Sound("/Users/laurabreukhoven/Desktop/HKU/jaar2/CSD2/Irregular_Beat_Generator/hihat.wav")
snare_sample = pg.mixer.Sound("/Users/laurabreukhoven/Desktop/HKU/jaar2/CSD2/Irregular_Beat_Generator/snare.wav")
kick_sample = pg.mixer.Sound("/Users/laurabreukhoven/Desktop/HKU/jaar2/CSD2/Irregular_Beat_Generator/kick.wav")

"""
#TO DO event handling
snare_event = {
    "timestamp": time_stamps, # msec w.r.t start of program
    "sample_name": "snare", # name of instrument in text
    "sample": snare_sample, # reference to sound file
    "velocity": 82, # numeric MIDI-based, 0-127
    "duration_msec": 1000 # msec
}

kick_event = {
    "timestamp": 2000, 
    "sample_name": "kick",
    "sample": kick_sample,
    "velocity": 71,
    "duration_msec": 1000,
}

def handle_note_event(event):
    #handles note events by playing the referenced sample
    print("Handling note event, sample name:", event["sample_name"])
    sample = event["sample"]
    sample.set_volume(event["velocity"] / 127.0)
    sample.play()

""" 
# call the note handler for each event
# NOTE: ignoring timestamp in this example, simply wait 1 sec. in between
""" TO DO """
"""
1. Make dictionaries for events: low, mid, high
    dictionaries include: {
"time_stamps": 
ts, duration: "note_dur", 
"sample": sample
"velocity": velocity / 127 (to go from midi value to amplitude)
}

2. Handle note events, play notes by comparing the time passed to timestamps
in dictionary sorted


"""
"""
function to make note_events, takes in sample and the timestamps 

"""
def make_note_event(samplelayer, timestamp_list): #add duration later
    event = {
        "sample": samplelayer,
        "timestamps": 0
    }
    for ts in timestamp_list:
        event.update({"timestamps": ts})
    return event


snare_event = make_note_event(snare_sample, lcg_numbers)
print(snare_event)

#add durations later
def handle_note_event(sample, velocity):
    sample.set_volume(velocity / 127)
    sample.play


"""
start_time = time.time()
time_now = time.time() - start_time 


for i in range(len(snare_event["timestamp"])):
   handle_note_event(snare_event["timestamp"[i]])
   time.sleep(0.1)

""" 



'''
handle_note_event(snare_event)
time.sleep(1)

handle_note_event(kick_event)
time.sleep(0.5)
'''


'''

#PLOTTING
set_intervals = [0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15] 
time = set_intervals
chance = lcg_numbers

plt.plot(time, chance, mu)

plt.xlabel('Time')
plt.ylabel("Chance")
plt.title("Plot")
plt.show()

'''