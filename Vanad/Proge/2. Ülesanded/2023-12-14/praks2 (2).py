import math
def osta(raha, joogi_hind, pant):
    if raha < joogi_hind + pant:
        return 0
    else:
        mitu_pudelit = math.floor(raha/(joogi_hind + pant))
        raha -= mitu_pudelit * joogi_hind
        return mitu_pudelit + osta(raha, joogi_hind, pant)
   

raha = float(input("Sisesta rahasumma: "))
joogi_hind = float(input("Sisesta ühe pudeli joogi hind: "))
pant = float(input("Sisesta ühe pudeli pandi hind: "))
m = osta(raha, joogi_hind, pant)
print(f'Juku saab osta {m} pudelit jooki.')