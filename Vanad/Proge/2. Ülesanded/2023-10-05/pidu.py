def eelarve(inimeste_arv):
    return (10 * inimeste_arv) + 55
nimi = input("Sisesta failinimi: ")
väljund = input("Sisesta väljundfaili nimi: ")

fail = open(nimi)
failist = fail.readlines()

kutsutud = 0
vähim = 0
suurim = 0
for rida in failist:
    kutsutud += 0.5
    if rida == "?\n" or rida == "?":
        suurim += 1
    elif rida == "+\n" or rida == "+":
        suurim += 1
        vähim += 1
    else:
        continue
        
kirfail = open(väljund, "w")
kirfail.write("Kokku on kutsutud ")
kirfail.write(str(int(kutsutud)))
kirfail.write(" inimest\n")
kirfail.write("Vähim võimalik osavõtjate arv on ")
kirfail.write(str(vähim))
kirfail.write("\n")
kirfail.write("Suurim võimalik osavõtjate arv on ")
kirfail.write(str(suurim))
kirfail.write("\n")
kirfail.write("Peo vähim võimalik eelarve on ")
kirfail.write(str(eelarve(vähim)))
kirfail.write("\n")
kirfail.write("Peo suurim võimalik eelarve on ")
kirfail.write(str(eelarve(suurim)))
kirfail.write("\n")
kirfail.close()
print("Andmed kirjutatud faili")