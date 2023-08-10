
from playsound import playsound
import time

CLEAR = "\033[2J"
CLEAR_AND_RETURN = "\033[H"
def alarm(seconds):
    time_elasped = 0

    while time_elasped < seconds:
        time.sleep(1)
        time_elasped += 1

        time_left = seconds - time_elasped
        minutes_left = time_left // 60
        seconds_left = time_left % 60

        print(f"{CLEAR_AND_RETURN}You have{minutes_left:02d}:{seconds_left:02d} before the alarm sounds.")

    playsound('alarmsound.mp3')
minutes = int(input('How many minutes do you want to set the timer to?'))
seconds = int(input('How many seconds do you want to set the timer to? '))
total_seconds = minutes *60 + seconds   #puts the minutes and seconds in calculation
alarm(total_seconds)
