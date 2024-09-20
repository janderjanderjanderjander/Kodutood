def linnud_sõnastikku(doc):
    fail = open(doc, "r")
    fail = fail.readlines()
    sõnastik = {}
    for i in fail:
        i = i.split(",")
        sõnastik[i[0]] = int(i[1].strip("\n"))
    return sõnastik
#Programm
doc = input("Sisesta faili nimi: ")
sõnastik = linnud_sõnastikku(doc)
arv = int(input("Sisesta arv: "))
mälu = 0
for i in sõnastik:
    if sõnastik[i] > arv:
        print(i + " " + "(" + str(sõnastik[i]) + ")")
        mälu += sõnastik[i]
    else:
        mälu += sõnastik[i]
print("Juku nägi väljas " + str(mälu) + " lindu.")
        