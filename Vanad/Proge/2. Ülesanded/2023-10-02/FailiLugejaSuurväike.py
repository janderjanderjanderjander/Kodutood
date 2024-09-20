def suurväike(x):
    p = x.swapcase()
    return p
x = input("Sisesta faili nimi: ")
fail = open(x)
failistE = fail.readlines()
list = []
for p in failistE:
    list.append(suurväike(p))
for p in list:
    print(p)



