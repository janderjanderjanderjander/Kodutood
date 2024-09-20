class Kandidaat:
    def __init__(self, nimi):
        self.nimi = nimi
        self.tema_hääled = 0
    def lisa_hääl(self):
        self.tema_hääled += 1
        
class Valija:
    def __init__(self, nimi):
        self.nimi = nimi
    def hääleta(self, kandidaat_isend):
        kandidaat_isend.lisa_hääl()
        
#Programm
valijad = ["Jaanus", "Urve", "Ain", "Maarja", "Siim"]

Jaanus = Valija("Jaanus")
Kaja = Kandidaat("Kaja")
Urve = Valija("Urve")
Jüri = Kandidaat("Jüri")
Ain = Valija("Ain")
Martin = Kandidaat("Martin")
Maarja = Valija("Maarja")
Siim = Valija("Siim")

kandidaadid = [Kaja, Jüri, Martin]

Jaanus.hääleta(Kaja)
Urve.hääleta(Jüri)
Ain.hääleta(Martin)
Maarja.hääleta(Kaja)
Siim.hääleta(Kaja)
Siim.hääleta(Martin)
Maarja.hääleta(Jüri)
Jaanus.hääleta(Jüri)
Ain.hääleta(Kaja)
mälu = 0
nime_mälu = None
for i in kandidaadid:
    if i.tema_hääled > mälu:
        nime_mälu = i.nimi
        mälu = i.tema_hääled
    print(i.nimi + " " + str(i.tema_hääled))
print("Võitja on " + nime_mälu)




