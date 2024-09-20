mälu2 = []
failinimi = "tulemused.txt"
def loe_failist(failinimi):
    sõnastik = {}
    with open(failinimi, encoding="UTF-8") as fail:
        for rida in fail:
            uus = []
            rida = rida.strip().split(";")
            s = list(rida[1] +  rida[2] + rida[3] + rida[4])
            for i in s:
                uus.append(int(i))
            sõnastik[rida[0]] = uus
        return sõnastik
def leia_keskmine(sõnastik):
    global mälu2
    mälu = []
    mitu = 0
    for punktid in sõnastik.values():
        mälu.append(punktid)
    kõik = 0
    for i in mälu:
        voor = 0
        for j in i:
            mitu += 1
            voor += int(j)
            kõik += int(j)
        voor = round(voor / len(i), 1)
        mälu2.append(voor)
    kõik = round(kõik / mitu, 1)
    return kõik

#failinimi = input("Sisesta failinimi: ")
s = leia_keskmine(loe_failist(failinimi))
print("Voorude keskmised tulemused on:")
for i in mälu2:
    print(i)
print("Kõikide voorude keskmine tulemus on: " + str(s))