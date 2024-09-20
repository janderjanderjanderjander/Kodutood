class Isik:
    def __init__(self, nimi, vanus_a, pikkus_cm, kaal_kg):
        self.nimi = nimi
        self.vanus = int(vanus_a)
        self.pikkus = int(pikkus_cm)
        self.kaal = int(kaal_kg)
    def kmi(self):
        return round(self.kaal / (self.pikkus / 100 * self.pikkus / 100), 1)
    
#pregame
Anne = Isik("Anne", 29, 164, 70)
Paul = Isik("Isik", 32, 141, 45)
if Anne.pikkus < Paul.pikkus:
    print("Anne on lühem kui Paul")
elif Anne.pikkus == Paul.pikkus:
    print("Samad")
else:
    print("Anne on pikem kui Paul")
if Anne.kaal < Paul.kaal:
    print("Anne kaalub vähem kui Paul")
elif Anne.kaal == Paul.kaal:
    print("Sama kaal")
else:
    print("Anne kaalub rohkem kui Paul")




#programm
with open("tervisekontroll.txt", encoding="UTF-8") as fail:
    isikud_koodidena = []
    for rida in fail:
        faili_list = rida.strip().split(",")
        isiku_kood = Isik(faili_list[0], faili_list[1], faili_list[2], faili_list[3])
        isikud_koodidena.append(isiku_kood)
for i in isikud_koodidena:
    if i.kmi() > 25:
        arvamus = "peaksid maha võtma"
    elif i.kmi() < 19:
        arvamus = "peaksid juurde võtma"
    else:
        arvamus = "oled normaalkaalus"
    print(i.nimi + ", " + str(i.vanus) + "-aastane: sinu kehamassiindeks on " + str(i.kmi()) + ", " + arvamus)
