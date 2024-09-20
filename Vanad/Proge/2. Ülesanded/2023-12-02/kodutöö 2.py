class Tõukeratas: #näiteks, tõuks1
    def __init__(self, firma, alustustasu, saja_meetri_hind, sõidukaugus):
        self.firma = firma
        self.alustustasu = float(alustustasu)
        self.saja_meetri_hind = float(saja_meetri_hind)
        self.sõidukaugus = float(sõidukaugus) 
    def sõidu_hind(self, sõidu_pikkus):
        mälu = self.sõidukaugus - sõidu_pikkus
        if mälu < 0:
            return 1000
        else:
            sõidukaugus_m = sõidu_pikkus * 1000
            return self.alustustasu + ((sõidukaugus_m * self.saja_meetri_hind) / 100)
    def sõida(self, sõidu_pikkus):
        self.sõidukaugus = self.sõidukaugus - sõidu_pikkus
    def lae(self, laetud_kaugus):
        self.sõidukaugus = self.sõidukaugus + laetud_kaugus

class Laenutus:
    def __init__(self, järjend_isenditest):
        self.järjend_isenditest = järjend_isenditest
    def kuva_valik(self, sõidu_pikkus_km):
        ajutine_dict = {}
        for tõuks_terve in self.järjend_isenditest:
            ajutine_dict[tõuks_terve.firma] = tõuks_terve.sõidu_hind(sõidu_pikkus_km)
        järjekorras_ajutine_dict = dict(sorted(ajutine_dict.items(), key=lambda x: x[1]))
        mitmes = 0
        for i in järjekorras_ajutine_dict.keys():
            mitmes += 1
            print(f'{mitmes}. {i} - {järjekorras_ajutine_dict[i]} eurot')
    def laenuta(self, tõukeratta_nimi, sõidu_pikkus_km):
        milline_tõuks = 0
        for tõuks_terve_isend in self.järjend_isenditest:
            if tõuks_terve_isend.firma.lower() == tõukeratta_nimi.lower():
                milline_tõuks = tõuks_terve_isend
        if milline_tõuks.sõidu_hind(sõidu_pikkus_km) == 1000:
            print("Tõukeratta aku on liiga tühi selle sõidu jaoks.")
        else:
            print(f'Sõidu hind oli {milline_tõuks.sõidu_hind(sõidu_pikkus_km)} eurot')
            milline_tõuks.sõida(sõidu_pikkus_km)
    def lae_tõukeratast(self, tõuksi_nimi, palju_laen):
        milline_tõuks = 0
        for tõuks_terve_isend in self.järjend_isenditest:
            if tõuks_terve_isend.firma.lower() == tõuksi_nimi.lower():
                milline_tõuks = tõuks_terve_isend
        milline_tõuks.lae(palju_laen)
            
#Programm
sisestus1 = input("Sisesta firma, alustustasu, saja meetri hind, sõidukaugus: ")
#sisestus1 = "Bolt, 1.5, 0.1, 20"
sisestus_andmed1 = sisestus1.split(",")
tõuks1 = Tõukeratas(sisestus_andmed1[0], sisestus_andmed1[1], sisestus_andmed1[2], sisestus_andmed1[3])
sisestus2 = input("Sisesta firma, alustustasu, saja meetri hind, sõidukaugus: ")
#sisestus2 = "Tuul, 1, 0.15, 18"
sisestus_andmed2 = sisestus2.split(",")
tõuks2 = Tõukeratas(sisestus_andmed2[0], sisestus_andmed2[1], sisestus_andmed2[2], sisestus_andmed2[3])
sisestus3 = input("Sisesta firma, alustustasu, saja meetri hind, sõidukaugus: ")
#sisestus3 = "Bird, 0, 0.3, 34"
sisestus_andmed3 = sisestus3.split(",")
tõuks3 = Tõukeratas(sisestus_andmed3[0], sisestus_andmed3[1], sisestus_andmed3[2], sisestus_andmed3[3])
sj = []
sj.append(tõuks1)
sj.append(tõuks2)
sj.append(tõuks3)
laen = Laenutus(sj)

laen.kuva_valik(2)

laen.laenuta("Bolt", 3)

laen.laenuta("Tuul", 18)

laen.laenuta("Tuul", 5)

laen.lae_tõukeratast("Tuul", 5)

laen.laenuta("Tuul", 2)