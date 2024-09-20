class Raamat:
    def __init__(self, pealkiri, autor, lehekülgede_arv, liik):
        self.pealkiri = pealkiri
        self.autor = autor
        self.lehekülgede_arv = lehekülgede_arv
        self.liik = liik
    def kuva_info(self):
        print("{},{},{},{}".format(self.pealkiri, self.autor, self.lehekülgede_arv, self.liik))

class Raamatukogu:
    def __init__(self):
        self.raamatukogu = []
    def lisa_raamat(self, raamat):
        self.raamatukogu.append(raamat)
    def kuva_raamatud(self):
        print("Raamatukogus olevad raamatud:")
        for i in self.raamatukogu:
            i.kuva_info()
    def laenuta_raamat(self, pealkiri):
        pealkiri = pealkiri.lower()
        for mitmes, raamat in enumerate(self.raamatukogu):
            if pealkiri == raamat.pealkiri.lower():
                self.raamatukogu.pop(mitmes)
                return raamat
        return None
    
###Programm
    
rk = Raamatukogu()
with open("raamatud.txt", encoding = "UTF-8") as fail:
    for mitmes, rida in enumerate(fail):
        rida = rida.strip().split(",")
        mitmes = Raamat(rida[0], rida[1], rida[2], rida[3])
        rk.lisa_raamat(mitmes)
rk.kuva_raamatud()
sai = 0
while sai == 0:
    print("")
    sisestus = input("Sisesta raamatu pealkiri: ")
    raamat = rk.laenuta_raamat(sisestus)
    if raamat == None:
        print("Ei leidnud sellist raamatut, proovi uuesti!")
        continue
    else:
        print("Raamat " + raamat.pealkiri + " edukalt laenutatud!")
        print("")
        rk.kuva_raamatud()
        sai = 1
        
        