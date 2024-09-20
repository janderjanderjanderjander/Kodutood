mitu = 0
sõnastik = {}
while True:
    sisestus = input("Sisesta sõna: ")
    if sisestus in sõnastik.keys():
        print(sisestus + " tähendab " + sõnastik[sisestus])
    elif sisestus == "":
        break
    else:
        mitu += 1
        tähendus = input("Mida " + sisestus + " tähendab?: ")
        if sõnastik == {}:
            sõnastik = {sisestus: tähendus}
        else:
            sõnastik[sisestus] = tähendus
        
fail = open("sõnad.txt", "w")
for i in sõnastik:
    fail.write(i + " - " + sõnastik[i] + "\n")
fail.close()
print("Sõnastik kirjutati faili.")
print("Sõnastikus on " + str(mitu) + " sõna.")