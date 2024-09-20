def info_isikukoodist(isikukood):
    isikukood = list(isikukood)
    if isikukood[0] in [1, 3, 5, 7]
        print("Sugu: Mees")
    else:
        print("Sugu: Naine")
        
    if str(isikukood[3]) + str(isikukood[4]) == "01":
        kuu = "jaanuar"
    elif str(isikukood[3]) + str(isikukood[4]) == "02":
        kuu = "veebruar"
    elif str(isikukood[3]) + str(isikukood[4]) == "03":
        kuu = "märts"
    elif str(isikukood[3]) + str(isikukood[4]) == "04":
        kuu = "aprill"
    elif str(isikukood[3]) + str(isikukood[4]) == "05":
        kuu = "mai"
    elif str(isikukood[3]) + str(isikukood[4]) == "06":
        kuu = "juuni"
    elif str(isikukood[3]) + str(isikukood[4]) == "07":
        kuu = "juuli"
    elif str(isikukood[3]) + str(isikukood[4]) == "08":
        kuu = "august"
    elif str(isikukood[3]) + str(isikukood[4]) == "09":
        kuu = "september"
    elif str(isikukood[3]) + str(isikukood[4]) == "10":
        kuu = "oktoober"
    elif str(isikukood[3]) + str(isikukood[4]) == "11":
        kuu = "november"
    else:
        kuu = "detsember"
    
    päev = str(isikukood[5]) + str(isikukood[6])
    if isikukood[0] in [1, 2]:
        aasta = "18" + str(isikukood[1]) + str(isikukood[2])
    elif isikukood[0] in [3, 4]:
        aasta = "19" + str(isikukood[1]) + str(isikukood[2])
    elif isikukood[0] in [5, 6]:
        aasta = "20" + str(isikukood[1]) + str(isikukood[2])
    else:
        aasta = "21" + str(isikukood[1]) + str(isikukood[2])
    print("Sünnikuupäev: " + päev + ". " + kuu + " " + aasta)
    
info_isikukoodist("50303114923")