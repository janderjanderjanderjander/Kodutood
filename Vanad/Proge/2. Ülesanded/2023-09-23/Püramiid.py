def arvuta(i):
    x = 1
    l = 0
    z = 0
    while l < i:
        z += x
        x += 1
        l += 1
    return float(z)


i = float(input("Sisesta arv: "))
print("Vastus on ", round(arvuta(i)))