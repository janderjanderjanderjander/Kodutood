fail = open("sünnid.txt")
paar = 1
sünd = []
l = []
for rida in fail:
    if paar == 1:
        rida = rida.strip("\n")
        l.append(rida)
        paar = 2
    elif paar == 2:
        rida = rida.strip("\n")
        l.append(rida)
        sünd.append(l)
        l = []
        paar = 1
fail = open("surmad.txt")
surm = []
for rida in fail:
    if paar == 1:
        rida = rida.strip("\n")
        l.append(rida)
        paar = 2
    elif paar == 2:
        rida = rida.strip("\n")
        l.append(rida)
        surm.append(l)
        l = []
        paar = 1
kõik = []
kõik.append(sünd)
kõik.append(surm)
arvutus = 0
print("Positiivse iibega kuud olid:")
for i in range(0, len(sünd)):
    arvutus += int(sünd[i][1])
    arvutus -= int(surm[i][1])
    if int(sünd[i][1]) > int(surm[i][1]):
        print(str(sünd[i][0]) + " " + str(int(sünd[i][1]) - int(surm[i][1])))
print("Kogu ajavahemiku loomulik iive oli " + str(arvutus) + ".")
    