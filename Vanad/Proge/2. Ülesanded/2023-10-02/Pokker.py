def käsi(x):
    y = list(x)
    if "0" in y:
        x = x.replace("10", "O")
    x = list(x)
    olikaks = 0
    olikolm = 0
    akaardid = []
    p = 0
    lõpp = 0
    flush = ["23456", "34567", "45678", "56789", "6789O", "789JO", "89JOQ", "9JKOQ"]
    akaardid = x
    akaardid.sort()
    l = akaardid[5] + akaardid[6] + akaardid[7] + akaardid[8] + akaardid[9]
    n = akaardid[0] + akaardid[1] + akaardid[2] + akaardid[3] + akaardid[4]
    if l == "♣♣♣♣♣" or l == "♥♥♥♥♥" or l == "♦♦♦♦♦" or l == "♠♠♠♠♠":
        if n == "AJKOQ":
            return "Kuninglik mastirida"
        elif n in flush:
            return "Mastirida"
    for s in list(n):
        if akaardid.count(s) == 4:
            return "Nelik"
        if akaardid.count(s) == 2:
            olikaks += 1
        if akaardid.count(s) == 3:
            olikolm += 1
        if olikaks == 2 and olikolm == 3:
            return "Maja"
    if l == "♣♣♣♣♣" or l == "♥♥♥♥♥" or l == "♦♦♦♦♦" or l == "♠♠♠♠♠":
        return "Mast"
    elif n in flush:
        return "Rida"
    elif olikolm == 3 and olikaks == 0:
        return "Kolmik"
    elif olikaks == 4:
        return "Kaks paari"
    elif olikaks == 2:
        return "Üks paar"
    else:
        return "Kõrge kaart"

print(käsi("8♦9♦10♦J♦Q♦"))




