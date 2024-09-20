def loetleFilmid(zanr):
    nimekiri = []
    if zanr == "märul":
        zanr = "mÃ¤rul"
    elif zanr == "õudukas":
        zanr = "Ãµudukas"
    fail = open("filmid.txt")
    for i in fail:
        z = i.split()
        if zanr in z:
            film = None
            for sõna in z:
                if sõna == "-":
                    break
                else:
                    if film == None:
                        film = sõna
                    else:
                        film = film + " " + sõna
            nimekiri.append(film)
    if nimekiri == []:
        return -1
    else:
        return nimekiri
def lisaFilm(nimi, zanr):
    fail = open("filmid.txt", "a")
    fail.write("\n" + nimi + " - " + zanr)
    fail.close()
def kustutaFilm(täisnimi):
    if "märul" in täisnimi.split():
        uusnimi = None
        for i in täisnimi.split():
            if uusnimi == None:
                uusnimi = i
            elif i == "märul":
                uusnimi = uusnimi + " mÃ¤rul"
            else:
                uusnimi = uusnimi + " " + i
        täisnimi = uusnimi
    if "õudukas" in täisnimi.split():
        uusnimi = None
        for i in täisnimi.split():
            if uusnimi == None:
                uusnimi = i
            elif i == "õudukas":
                uusnimi = uusnimi + " Ãµudukas"
            else:
                uusnimi = uusnimi + " " + i
        täisnimi = uusnimi
    fail = open("filmid.txt", "r")
    read = fail.readlines()
    fail = open("filmid.txt", "w")
    for rida in read:
        if rida.strip("\n") != täisnimi:
            fail.write(rida)
    fail.close()
    
print("Tee valik:")
print("	Vaata filme (V)")
print("	Lisa film (L)")
print("	Kustuta film (K)")
print("	Lõpeta (E)")


while True:
    valik = input("Valik: ")
    if valik == "V":
        zanr = input("Sisesta zanr: ")
        if loetleFilmid(zanr) == -1:
            print("Sellest žanrist ei ole ühtegi filmi")
        else:
            for rida in loetleFilmid(zanr):
                print(rida)
            print(" ")
    elif valik == "L":
        nimi = input("Sisesta filmi nimi: ")
        zanr = input("Sisesta zanr: ")
        lisaFilm(nimi, zanr)
        print("Film lisatud!")
        print(" ")
    elif valik == "K":
        kust = input("Sisesta filmi nimi kustutamiseks: ")
        kustutaFilm(kust)
        print("Film nimekirjast kustutatud!")
        print(" ")
    elif valik == "E":
        break
    else:
        print("Sellist valikut pole")
        print(" ")
