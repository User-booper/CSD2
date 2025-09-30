#function that prints the data type of the argument

def print_Type(argument):
    print("The type is: ",type(argument))

number = 10
print_Type(number)

#function that returns timestamps based on a calculation using the bpm and note durations
# note_duration is het aantal beats (halve noot = 2 beats etc)
#time_stamp is het 60000 / bpm (hoeveel ms een beat duur), vermenigvuldigd met de note_durations

bpm = 120
note_durations = [2, 1, 0.5, 2]

def time_stamps(bpm, note_duration):
    time_in_milliseconds = []
    for i in range(len(note_duration)):
        note_dur = (60000 / bpm) * note_duration[i]
        time_in_milliseconds.append(note_dur)

    return time_in_milliseconds
    
print(time_stamps(bpm, note_durations))

#function sample pack lets user choose one of a few sample packs
# and returns the index of that sample pack in a list

def choose_sample_pack():
    sample_pack = ["Rock", "Jazz", "Soul", "Electronic"]
    choosen_sample_pack = input("Choose a sample pack (Rock, Jazz, Soul or Electronic): ")
    if choosen_sample_pack in sample_pack:
        return sample_pack.index(choosen_sample_pack)
    else:
        return("Sample pack does not exist. Choose one of the following: Rock, Jazz, Soul or Electronic ")
    
print(choose_sample_pack())


