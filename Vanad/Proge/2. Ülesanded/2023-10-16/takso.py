failist = open("taksohinnad.txt").readlines()
l = float(input("Mitu km?: "))
vana = 0
for rida in failist:
    s = rida.split(",")
    arvutus = l * float(s[2]) + float(s[1])
    if arvutus < vana or vana == 0:
        vana = arvutus
        see = str(s[0])
print("Kõige odavam on", see)