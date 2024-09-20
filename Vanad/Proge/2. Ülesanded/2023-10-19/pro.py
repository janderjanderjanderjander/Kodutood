input_essa = input("Sisesta faili nimi: ")
input_teine = input("Sisesta teise faili nimi: ")
võistlejad_raw = open(input_essa).readlines()
kohad_raw = open(input_teine).readlines()
võistlejad_küps = []
kohad_küps = []
tulemus = []
mitu = 0
for i in võistlejad_raw:
    if i[-1:] == "\n":
        i = i[:-1]
    i = i[3:]
    võistlejad_küps.append(i)
for i in kohad_raw:
    if i[-1:] == "\n":
        i = i[:-1]
    kohad_küps.append(i)
for i in kohad_küps:
    i = int(i) - 1
    tulemus.append(võistlejad_küps[i])
kirfail = open("tulemus.txt", "w")
for i in tulemus:
    mitu += 1
    try:
        tulemus[int(tulemus.index(i)+1)]
        kirfail.write(str(mitu) +". " +str(i)+"\n")
    except:
        kirfail.write(str(mitu) +". " +str(i)+"\n")
        kirfail.close()
        print("Andmed kirjutatud faili")
        
