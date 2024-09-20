def loe_albumid(failinimi):
    with open(failinimi, encoding="UTF-8") as fail:
        sõnastik = {}
        for rida in fail:
            sõnastiku_list = []
            faili_list = rida.strip().split(":")
            if faili_list == [""]:
                break
            proov = faili_list[1].split("(")
            if faili_list[0] in sõnastik.keys():
                sõnastiku_list = sõnastik[faili_list[0]]
                sõnastiku_list.append([proov[0].strip(), int(proov[1].strip(")"))])
                sõnastik[faili_list[0]] = sõnastiku_list
            else:
                sõnastiku_list.append([proov[0].strip(), int(proov[1].strip(")"))])
                sõnastik[faili_list[0]] = sõnastiku_list
    return sõnastik
def vaata_albumeid(sõnastik): #[esitaja nimi]: [albumi nimi] ([aastaarv])
    for i in sõnastik.keys():
        if len(sõnastik[i]) > 1:
            for j in sõnastik[i]:
                print(f'{i}: {j[0]} ({j[1]})')
        else:
            print(f'{i}: {sõnastik[i][0][0]} ({sõnastik[i][0][1]})')
def lisa_album(esitaja_nimi, albumi_nimi, aastaarv, sõnastik):
    if esitaja_nimi in sõnastik.keys():
        for i in sõnastik[esitaja_nimi]:
            if albumi_nimi == i[0]:
                print(f'Album juba olemas!')
                return sõnastik
        sõnastiku_list = sõnastik[esitaja_nimi]
        sõnastiku_list.append([albumi_nimi, aastaarv])
        sõnastik[esitaja_nimi] = sõnastiku_list
        print(f'Album lisatud!')
    else:
        sõnastik[esitaja_nimi] = [[albumi_nimi, aastaarv]]
        print(f'Album lisatud!')
    return sõnastik
def eemalda_album(esitaja_nimi, albumi_nimi, sõnastik):
    oli = 0
    if esitaja_nimi in sõnastik.keys():
        for i in sõnastik[esitaja_nimi]:
            if albumi_nimi == i[0]:
                oli = 1
                sõnastiku_list = sõnastik[esitaja_nimi]
                if len(sõnastiku_list) == 1:
                    del sõnastik[esitaja_nimi]
                else:
                    sõnastiku_list.pop(sõnastiku_list.index(i))
                    sõnastik[esitaja_nimi] = sõnastiku_list
    if oli == 1:
        print(f'Album on eemaldatud!')
        return sõnastik
    else:
        print(f'Sellist albumit pole!')
        return sõnastik
def salvesta_faili(sõnastik):
    try:
        fail = open("albumid.txt", "w")
        for i in sõnastik.keys():
            if len(sõnastik[i]) > 1:
                for j in sõnastik[i]:
                    fail.write(f'{i}: {j[0]} ({j[1]})\n')
            else:
                fail.write(f'{i}: {sõnastik[i][0][0]} ({sõnastik[i][0][1]})\n')
        fail.close()
        print(f'Salvestatud faili')
    except:
        print(f'Ei õnnestunud salvestada faili')
        
#PÕHIPROGRAMM
sõnastik = loe_albumid("albumid.txt")
while True:
    parool = input("Sisesta parool: ")
    if parool == "1985":
        break
    else:
        print("Vale parool")
while True:
    print(f'Vali tegevus:')
    print(f'1 - Vaatan albumeid')
    print(f'2 - Lisan albumi')
    print(f'3 - Eemaldan albumi')
    print(f'4 - Salvestan faili')
    print(f'5 - Lõpetan programmi töö')
    sisestus = input()
    if sisestus == "1":
        vaata_albumeid(sõnastik)
    elif sisestus == "2":
        essa = input("Sisesta esitaja: ")
        teine = input("Sisesta album: ")
        kolmas = input("Sisesta aasta: ")
        sõnastik = lisa_album(essa, teine, kolmas, sõnastik)
    elif sisestus == "3":
        essa = input("Sisesta esitaja: ")
        teine = input("Sisesta album: ")
        sõnastik = eemalda_album(essa, teine, sõnastik)
    elif sisestus == "4":
        salvesta_faili(sõnastik)
    elif sisestus == "5":
        print("Programm lõpetas töö.")
        break