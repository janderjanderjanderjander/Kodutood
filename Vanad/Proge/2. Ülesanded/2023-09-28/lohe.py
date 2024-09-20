def söök(lohe, madu, saurus):
    päev = 0
    while lohe != 0 and madu != 0 or madu != 0 and saurus != 0 or saurus != 0 and lohe != 0:
        päev += 1
        #hommikusöök lohe sööb ühe mao
        madu = madu - 1 * lohe
        if madu < 0:
            madu = 0
            pass
        #lõunasöök madu sööb ühe sauruse
        saurus = saurus - 1 * madu
        if saurus < 0:
            saurus = 0
            pass
        #õhtusöök saurus sööb lohe
        lohe = lohe - 1 * saurus
        if lohe < 0:
            lohe = 0
            pass
    print("Viimane söögikord toimus ", päev, ". päeval")
    if lohe > 0:
        print("Järele jäi", round(lohe), "lohe")
    elif madu > 0:
        print("Järele jäi", round(madu), "madu")
    elif saurus > 0:
        print("Järele jäi", round(saurus), "saurust")
        
lohe = float(input("Mitu lohe?: "))
madu = float(input("Mitu madu?: "))
saurus = float(input("Mitu saurust?: "))
söök(lohe, madu, saurus)
    
        
        