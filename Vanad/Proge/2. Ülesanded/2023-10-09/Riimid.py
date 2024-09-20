alg = input("Sisesta algsõna: ")
riimilisus = 0
meeles = 0
nummerdus = 0
while True:
    riim = input("Sisesta riimuv sõna: ")
    if riim == "lõpp":
        print("Kõige suurem riimumisnäitaja", meeles, "oli sõnal", meelessõna)
        break
    esialgneList = list(alg)
    uusList = list(riim)
    vaja = []
    if len(esialgneList) > len(uusList):
        palju = len(esialgneList) - len(uusList)
        while palju > 0:
            palju -= 1
            vaja.append(palju)
        vaja = reversed(vaja)
        for i in vaja:
            del esialgneList[0]
    elif len(esialgneList) < len(uusList):
        palju = len(uusList) - len(esialgneList)
        while palju > 0:
            palju -= 1
            vaja.append(palju)
        vaja = reversed(vaja)
        for i in vaja:
            del uusList[0]
    for s in esialgneList:
        if s == uusList[nummerdus]:
            riimilisus += 1
        nummerdus += 1
            
    print("Riimilisusnäitaja on", riimilisus)
        
    if riimilisus > meeles:
        meeles = riimilisus
        meelessõna = riim
        riimilisus = 0
        nummerdus = 0
    else:
        riimilisus = 0
        nummerdus = 0
