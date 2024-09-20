def kirja_hind(x):
    if x <= 250:
        return 1.75
    elif x <= 500:
        return 2.70
    elif x <= 1000:
        return 2.85
    elif x > 1000:
        return 4.35
    else:
        retun -1
    
    

y = float(input("Sisesta kirjade arv: "))
s = 1
p = 0
while s <= y:
    print("Sisesta ", s, ". kirja kaal: ")
    x = float(input())
    p += kirja_hind(x)
    s += 1
print("Nende kirjade saatmine läheb maksma ", p, "eurot.")
    
    