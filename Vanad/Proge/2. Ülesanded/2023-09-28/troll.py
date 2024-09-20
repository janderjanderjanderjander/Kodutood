troll = 100
kangelane = 100
import time
from random import randint

while troll > 0 and kangelane > 0:
    q = randint(1, 5)
    troll = troll - q
    s = randint(1, 5)
    kangelane = kangelane - s
    print("Trollil on", troll, "elu (-", q, "dmg)")
    print("Kangelasel on", kangelane, "elu (-", s, "dmg)")
    time.sleep(3)
    print()
if troll <= 0:
    print("Kangelane võitis!")
elif kangelane <= 0:
    print("Troll võitis!")
else:
    print("Mõlemad surnud")