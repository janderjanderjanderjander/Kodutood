def nimi_ja_hind(rida):
    jagatud = rida.split(";")
    return (jagatud[0], float(jagatud[2]))

vähim = float(input("Sisesta vähim hind: "))
suurim = float(input("Sisesta suurim hind: "))

fail = open("kingid.txt")
mälu = []
for rida in fail:
    m = nimi_ja_hind(rida)
    if m[1] >= vähim and m[1] <= suurim:
        mälu.append(m[0])
print("Sellesse hinnavahemikku jäävad järgmised kingid:")
for i in mälu:
    print(i)
    
