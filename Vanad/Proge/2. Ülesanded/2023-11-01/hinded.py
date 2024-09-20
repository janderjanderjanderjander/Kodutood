def failist_järjendisse(nimi):
    fail = open(nimi)
    #fail = fail.split()
    s = []
    for rida in fail:
        m = []
        rida = rida.split(",")
        for i in rida:
            if rida.index(i) == 0:
                m.append(i)
            else:
                i = i.strip("\n")
                m.append(int(i))
        s.append(m)
    return s

def keskmised(tabel):
    s = []
    for j in tabel:
        l = []
        mälu = []
        for i in j:
            if isinstance(i, str) == True:
                l.append(i)
            else:
                mälu.append(i)
        summa = 0
        mitu = 0
        for i in mälu:
            summa += i
            mitu += 1
        keskmine = summa / mitu
        l.append(round(keskmine, 1))
        s.append(l)
    return s

failinimi = input("Sisesta faili nimi: ")
print(keskmised(failist_järjendisse(failinimi)))