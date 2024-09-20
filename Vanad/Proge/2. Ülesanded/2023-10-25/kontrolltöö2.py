import math
def leia_hind(omahind, soodushind):
    if omahind < 10:
        return soodushind
    else:
        return math.floor(soodushind - 1) + 0.99
def kuu_kasum(omahind, uus_hind, keskmine):
    return (keskmine * uus_hind) - (keskmine * omahind)
omahind = float(input("Sisesta toote omahind: "))
konkurents = float(input("Konkureeriv soodushind: "))
keskmine = float(input("Toodete arv: "))
uus_hind = leia_hind(omahind, konkurents)
kasum = kuu_kasum(omahind, uus_hind, keskmine)
if kasum >= 0:
    print("Toote uus hind on " + str(uus_hind) + " eurot ja prognoositav kasum on " + str(kasum) + " eurot.")
else:
    print("Toote uus hind on " + str(uus_hind) + " eurot ja prognoositav kahjum on " + str(-kasum) + " eurot.")
if kasum > -15000:
    print("Tootele pannakse uus hind.")
else:
    print("Tootele jääb vana hind.")