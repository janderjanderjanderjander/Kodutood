sisestus = input("Sisesta esemete arvud: ")
asjad = sisestus.split()
kolm = 0
mälu = 0
mitmes = 0
for i in asjad:
    i = int(i)
    mitmes += 1
    if i > 3:
        kolm += 1
    if i > mälu:
        mälu = i
        mälu_mitme = mitmes
print("Järjekorras seisab", mitmes ,"inimest")
print("Rohkem kui kolm eset on korvis", kolm ,"inimesel")
print("Kõige rohkem esemeid on", str(mälu) + ". inimesel, kellel on", mälu_mitme ,"eset")
        
