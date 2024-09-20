fail = open("sõnastik.txt", "r")
fail = fail.readlines()
sõnastik = {}
for i in fail:
    i = i.split()
    sõnastik[i[0]] = i[2]
print(sõnastik)
sisestus = "Power"
#fail = open("sõnastik.txt", "w")
tähendus = input("Mida " + sisestus + " tähendab?: ")
sõnastik[sisestus] = tähendus

for i in sõnastik
