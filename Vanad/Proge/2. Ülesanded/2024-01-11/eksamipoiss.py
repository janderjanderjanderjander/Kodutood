class Kasutaja:
    def __init__(self, kasutajanimi, meiliaadress):
        self.kasutajanimi = kasutajanimi
        self.meiliaadress = meiliaadress
    def __str__(self):
        return f'Kasutajanimi: {self.kasutajanimi}, meiliaadress: {self.meiliaadress}'
    def kuva(self):
        print(f'Kasutajanimi: {self.kasutajanimi}, meiliaadress: {self.meiliaadress}')
class Administraator(Kasutaja):
    def __init__(self, kasutajanimi, meiliaadress): #kasutajad on järjend
        super().__init__(kasutajanimi, meiliaadress)
        self.kasutajad = []
    def kinnita_kasutaja(self, Kasutaja):
        if Kasutaja in self.kasutajad:
            print(f'{Kasutaja.kasutajanimi} on juba olemas!')
        else:
            self.kasutajad.append(Kasutaja)
            print(f'{Kasutaja.kasutajanimi} kinnitatud!')
            
juhosepp = Kasutaja("juhosepp", "juho@sepp.ee")
peetrebane = Kasutaja("peetrebane", "peet@rebane.ee")
admin = Administraator("admin", "admin@admin.ee")

juhosepp.kuva()
peetrebane.kuva()
print(admin)

admin.kinnita_kasutaja(juhosepp)
admin.kinnita_kasutaja(peetrebane)
admin.kinnita_kasutaja(peetrebane)