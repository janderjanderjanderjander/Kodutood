from random import randint

uksA = float(input("Mitu kinga esimese ukse juures?: "))
uksB = float(input("Mitu kinga teise ukse juures?: "))
kord = float(input("Mitu korda teen läbi?: "))

#n kingi
paljalt = 0
on = 0
mitmes = 0
#Läheb minema
while mitmes < kord:
    mitmes += 1
    valik = randint(1, 2)
    if valik == 1:
        uksA -= 1
        if uksA < 0:
            paljalt += 1
            uksA = 0
            on = 1
    else:
        uksB -= 1
        if uksB < 0:
            uksB = 0
            paljalt += 1
            on = 1

        

    #tuleb tagasi
    valik = randint(1, 2)
    if valik == 1:
        if on == 1:
            on = 0
        else:
            uksA += 1
    else:
        if on == 1:
            on = 0
        else:
            uksB += 1
keskmine = paljalt / kord
print(keskmine)

    

    
    