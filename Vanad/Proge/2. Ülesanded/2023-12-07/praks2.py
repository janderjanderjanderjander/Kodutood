import random
class Draakon:
    kõik_isendid = []
    def __init__(self, nimi):
        self.nimi = nimi
        Draakon.kõik_isendid.append(self)
    def ründa(self):
        print(f'{self.nimi} möirgab')
class Maadraakon(Draakon):
    def __init__(self, nimi, järelolev_energia):
        super().__init__(nimi)
        self.järelolev_energia = järelolev_energia
    def ründa(self):
        if self.järelolev_energia > 0:
            print(f'{self.nimi} väristab maad')
            self.järelolev_energia -= 1
        else:
            super().ründa()
class Tuledraakon(Draakon):
    def __init__(self, nimi, järelolev_kütus):
        super().__init__(nimi)
        self.järelolev_kütus = järelolev_kütus
    def ründa(self):
        if self.järelolev_kütus >= 10:
            print(f'{self.nimi} sülgab tuld')
            self.järelolev_kütus -= 10
        else:
            super().ründa()
class Kividraakon(Maadraakon):
    def __init__(self, nimi, järelolev_energia, kivide_arv):
        super().__init__(nimi, järelolev_energia)
        self.kivide_arv = kivide_arv
    def ründa(self):
        if self.kivide_arv >= 3:
            print(f'{self.nimi} heidab 3 kivi')
            self.kivide_arv -= 3
        elif self.kivide_arv > 0:
            print(f'{self.nimi} heidab {self.kivide_arv} kivi')
            self.kivide_arv = 0
        else:
            super().ründa()
class Laavadraakon(Tuledraakon):
    def __init__(self, nimi, järelolev_kütus, laavakogus):
        super().__init__(nimi, järelolev_kütus)
        self.laavakogus = laavakogus
    def ründa(self):
        if self.laavakogus >= 100:
            laava_hulk = random.randint(1, 100)
            self.laavakogus -= laava_hulk
            print(f'{self.nimi} paiskab {laava_hulk} laavat')
        elif self.laavakogus > 0:
            laava_hulk = random.randint(1, self.laavakogus)
            self.laavakogus -= laava_hulk
            print(f'{self.nimi} paiskab {laava_hulk} laavat')
        else:
            super().ründa()
            
            
chiki = Kividraakon("Chiki", 4, 12)
bolder = Kividraakon("Bolder", 7, 2)
rytys = Laavadraakon("Rytys", 30, 110)
pane_tuli_kustu = Laavadraakon("PTK", 100, 0)

kõik_isendid = Draakon.kõik_isendid

for i in range(0, 20):
    mis_drago = random.choice(kõik_isendid)
    mis_drago.ründa()


            