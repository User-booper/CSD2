import pygame
import time

# init  mixer module
pygame.init()

# load the sample
sample = pygame.mixer.Sound('./plop.wav')

play_amount = int(input("How many times would you like to hear the sample ?: "))
# aantal keer dat de sample wordt afgespeeld.


#audio afspelen dmv een forloop
for x in range(0, play_amount):
    sample.play()
    # time.sleep(sample.get_length())
    time.sleep(0.5)

# play the sample and wait till sound is done playing / 0.5seconds before exiting

#audio afspelen dmv een while loop

playing = True
count = 0

while(playing):
    sample.play
    count =+ 1
    time.sleep(0.5)

    if count > play_amount:
        playing = False

    

