failinimi = input("Sisesta faili nimi: ")
pilve_nimi = input("Sisesta pilveteenuse nimi: ")
laenu_summa = input("Sisesta laenusumma: ")
mitmes = 0
oli = 0
mälu_üks = 0
mälu_kaks = 1000
failist = open(failinimi).readlines()
def arvuta(laen, tasu):
    return round(( laen / tasu ) / 60, 1)
for rida in failist:
    if rida[-1:] == "\n":
        rida = rida[:-1]
        pass
    if mitmes == 0:
        if rida == pilve_nimi:
            oli = 1
        mälu_üks = rida
        mitmes = 1
    elif mitmes == 1:
        rida = float(rida)
        if oli == 1:
            tasu = rida
            oli = 0
        mitmes = 2
        if rida < mälu_kaks:
            mälu_kaks = rida
            soodsaim = mälu_üks
    elif mitmes == 2:
        if rida == "jah":
            hetkeline_pilveteenus = mälu_üks
        mitmes = 0
print("Laenu eest saab pilveteenust kasutada", arvuta(float(laenu_summa), tasu), "tundi.")
print("Soodsaim pilveteenus on " + soodsaim + ".")
kirfail = open("hostimine.txt", "w")
if hetkeline_pilveteenus == pilve_nimi:
    kirfail.write("Sama pilveteenus - " + hetkeline_pilveteenus + ".")
    kirfail.close()
else:
    kirfail.write("Uus pilveteenus - " + pilve_nimi + ".")
    kirfail.close()

    

        
