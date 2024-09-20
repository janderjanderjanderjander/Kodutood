def päevade_arv(x):
    if x == 1 or x == 3 or x == 5 or x == 7 or x == 8 or x == 10 or x == 12:
        return 31
    elif x == 4 or x == 6 or x == 9 or x == 11:
        return 30
    elif x == 2:
        return 28
    else:
        return -1


while True:
    m = (input("Sisesta kuu number: "))
    if m == "lõpp":
        break
    else:
        try:
            m = int(m)
            if päevade_arv(m) == -1:
                print("Kuu number peab jääma lõiku 1 - 12")
            else:
                print("Selles kuus on ", päevade_arv(m), "päeva")
        except:
            print("Kuu number peab jääma lõiku 1 - 12")
print("Programm lõpetas töö")