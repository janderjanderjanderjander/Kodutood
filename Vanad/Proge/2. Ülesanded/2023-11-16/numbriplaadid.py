def failist_sõnastikku(failinimi):
    seosed = {}
    with open(failinimi, encoding="UTF-8") as fail:
        for rida in fail:
            rida = rida.split()
            if len(rida) == 3:
                seosed[rida[0]] = rida[1] + " " + rida[2]
            elif len(rida) == 4:
                seosed[rida[0]] = rida[1] + " " + rida[2] + " " + rida[3]
            elif len(rida) == 5:
                seosed[rida[0]] = rida[1] + " " + rida[2] + " " + rida[3] + " " + rida[4]
            else:
                seosed[rida[0]] = rida[1]
    return seosed
def koodid_nimedeks(failinimi, seosed):
    tagastus_list = []
    with open(failinimi, encoding="UTF-8") as fail:
        for rida in fail:
            rida = rida.strip("\n")
            if rida in seosed.keys():
                rida = seosed[rida]
            else:
                rida = "Tundmatu"
            tagastus_list.append(rida)
    return tagastus_list
#programm
sisestus_riigikoodid = input("Sisesta riigikoodide faili nimi: ")
sisestus_piiriületus = input("Sisesta piiriületuste faili nimi: ")
s = koodid_nimedeks(sisestus_piiriületus, failist_sõnastikku(sisestus_riigikoodid))
for i in s:
    print(i)