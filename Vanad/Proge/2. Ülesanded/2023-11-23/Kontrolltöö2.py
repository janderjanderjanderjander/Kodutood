def loe_andmed(failinimi):
    with open(failinimi, "r", encoding = "UTF-8") as fail:
        tagastus = {}
        for rida in fail:
            rida = rida.strip("\n").split(",")
            mitmes = 0
            uusrida = []
            for i in rida:
                if mitmes == 0:
                    nimi = i
                    mitmes += 1
                    continue
                i = i.split(":")
                i = int(float(i[0]) * 60 + float(i[1]))
                uusrida.append(i)
            tagastus[nimi] = uusrida
    return tagastus

def pikkused(sõnastik):
    tagastus = set()
    for i in sõnastik.keys():
        summa = 0
        for j in sõnastik[i]:
            summa += j
        tagastus.add((i, summa))
    return tagastus
    
#PROGRAMM
failinimi = input("Sisesta faili nimi: ")
l = loe_andmed(failinimi)
pikkused = pikkused(l)
sõidu_pikkus = int(input("Sisesta autosõidu pikkus minutites: "))
parim = None
parim_nimi = None
puudu = []
mitmes = -1
mälu = 0
for i in pikkused:
    mitmes += 1
    vahe = (sõidu_pikkus * 60) - i[1]
    vahe = -vahe
    if vahe < 0:
        puudu.append(1)
        vahe = -vahe
    else:
        puudu.append(0)
    if parim == None:
        parim = vahe
        mälu = mitmes
        parim_nimi = i[0]
    elif vahe < parim:
        mälu = mitmes
        parim = vahe
        parim_nimi = i[0]
print("Kõige sobivama pikkusega esitusloend on " + str(parim_nimi))
if puudu[mälu] == 0:
    print("Esitusloendis jääb üle " + str(parim) + " sekundit laule.")
else:
    print("Esitusloendis jääb puudu " + str(parim) + " sekundit laule.")
    