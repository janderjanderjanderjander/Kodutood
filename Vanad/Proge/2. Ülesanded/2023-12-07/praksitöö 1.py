import math
class Kook:
    kõik_isendid = []
    def __init__(self, nimi, mõõt, hind): #kook on ruut ja mõõt on külg
        self.nimi = nimi
        self.mõõt = mõõt
        self.hind = hind
        Kook.kõik_isendid.append(self)
    def pindala(self):
        return self.mõõt * self.mõõt
    def cm2hind(self):
        return round((self.hind / self.pindala()) * 100 , 2)
class Ümarkook(Kook):
    def pindala(self):
        return math.pi * ((self.mõõt / 2) * (self.mõõt / 2))
class Pitsa(Ümarkook):
    def __init__(self, nimi, mõõt, hind, kate):
        super().__init__(nimi, mõõt, hind)
        self.kate = kate
    def cm2hind(self):
        return round(((self.hind + self.kate) / self.pindala()) * 100, 2)
    
#- - - - - - PROGRAMM - - - - - -
k1 = Kook("Mustikakook", 8, 3.52)
k2 = Ümarkook("Prograndi-kõrvitsa pitsapõhi", 24, 1.85)
k3 = Pitsa("Ceasari pitsa", 24, 1.85, 6.70)
kõik_isendid = Kook.kõik_isendid
mälu = []
mälu_hind = 100000000

for i in kõik_isendid:
    if i.cm2hind() < mälu_hind:
        mälu = [i.nimi, i.cm2hind()]
        mälu_hind = i.cm2hind()
        
print(f'{mälu[0]} {mälu[1]}')


    