def summa(u, v):
    global vastus
    vastus = (((u + v) / (1 + ((u * v) / (c * c)))))
c = float(299792.458)
u = float(input("esimene: "))
v = float(input("teine: "))
a = float(input("kolmas: "))
b = float(input("neljas: "))
summa(u, v)
vastusessa = vastus
summa(vastusessa, a)
vastusessa = vastus
summa(vastusessa, b)
print(vastus)
