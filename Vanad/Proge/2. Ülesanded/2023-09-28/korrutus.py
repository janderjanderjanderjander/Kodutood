x = float(input("Sisesta esimene positiivne täisarv: "))
y = float(input("Sisesta teine positiivne täisarv: "))

z = 1
p = x
while z < y:
    p += x
    z += 1
print(round(p))