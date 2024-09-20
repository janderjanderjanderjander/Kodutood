u = input("Sisesta arvud: ")
u = u.split()
u.reverse()
#midagi mis mäletab viimast venda, kes kõige kaugemale nägi
mälu_kes = 0
mälu_palju = 0
mitmes = 0
võrdlus = []
lühi = []
for i in u:
    mitmes += 1
    if mälu_kes == 0:
        mälu_kes = i
        lühi.append(mitmes)
    elif i == u[-1]:
        lühi.append(mälu_kes)
        lühi.append(mälu_palju)
        võrdlus.append(lühi)
    else:
        if mälu_kes > i:
            mälu_palju += 1
        else:
            lühi.append(mälu_kes)
            lühi.append(mälu_palju)
            mälu_palju = 0
            mälu_kes = i
            võrdlus.append(lühi)
            lühi = []
            lühi.append(mitmes)
mälu = 0
nr = 0
pikkus = 0
for j in võrdlus:
    if j[2] > mälu:
        mälu = j[2]
        nr = j[0]
        pikkus = j[1]
    else:
        continue
print("Inimene nr " + str(mitmes - nr + 1) + " pikkusega " + str(pikkus) + " näeb kõige kaugemale.")
            
