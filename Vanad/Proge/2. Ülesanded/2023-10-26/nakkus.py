andmed_sisestus = input("Sisesta andmed: ")
andmed = andmed_sisestus.split()
mälu = []
sõne = None
for i in andmed:
    if int(i) in mälu or int(i) <= 0:
        continue
    else:
        mälu.append(int(i))
list.sort(mälu)
for i in mälu:
    if sõne == None:
        sõne = str(i) + " "
    else:
        sõne += str(i) + " "
print("Nakatajad on: " + sõne)
edasikandjad = []
lähtepunktid = []
for i in mälu:
    if int(andmed[i-1]) > 0:
        edasikandjad.append(i)
    else:
        lähtepunktid.append(i)
        
        
        
sõne = None
for i in edasikandjad:
    if sõne == None:
        sõne = str(i) + " "
    else:
        sõne += str(i) + " "
print("Nakkuse edasikandjad on: " + sõne)



sõne = None
for i in lähtepunktid:
    if sõne == None:
        sõne = str(i) + " "
    else:
        sõne += str(i) + " "
print("Nakkuse lähtepunktid on: " + sõne)
        

