class Sõiduk:
    def __init__(self, mark, hind, kütusekulu_100):
        self.mark = mark
        self.hind = hind
        self.kütusekulu_100 = kütusekulu_100
    def __str__(self):
        return self.mark, self.hind, self.kütusekulu_100
        
    
class Veoauto(Sõiduk):
    def __init__(self):
        self.liitrihind = 1.8
        self.hobujõud = 500
    def sõidu_maksumus(self, teepikkus_km):
        return (self.kütusekulu_100 * teepikkus_km / 100) * self.liitrihind
    def hobujõud(self):
        print(self.hobujõud)
    
class Sõiduauto(Sõiduk):
    def __init__(self):
        self.liitrihind = 1.9
        self.hobujõud = 180
    def sõidu_maksumus(self, teepikkus_km):
        return (self.kütusekulu_100 * teepikkus_km / 100) * self.liitrihind
    def hobujõud(self):
        print(self.hobujõud)
    
class Mootorratas(Sõiduk):
    def __init__(self):
        self.liitrihind = 1.85
        self.hobujõud = 85
    def sõidu_maksumus(self, teepikkus_km):
        return (self.kütusekulu_100 * teepikkus_km / 100) * self.liitrihind
    def hobujõud(self):
        print(self.hobujõud)

class Garaaž(self, sõiduki_järjend):
    def __init__(self, sõiduki_järjend):
        self.sõiduki_järjend = sõiduki_järjend
    def kuva():
        print("Garaažis on järgmised sõidukid:")
        

#PROGRAMM - - - -
