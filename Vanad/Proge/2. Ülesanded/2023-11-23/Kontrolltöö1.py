def loe_andmed(failinimi):
    with open(failinimi, "r", encoding = "UTF-8") as fail:
        tagastus = []
        for rida in fail:
            rida = rida.strip("\n").split(";")
            mitmes = 0
            uusrida = []
            for i in rida:
                if mitmes == 0:
                    uusrida.append(i)
                    mitmes += 1
                    continue
                i = float(i)
                uusrida.append(i)
            tagastus.append(uusrida)
    return tagastus
    
def keskmine_ja_parim(järjend, nimi):
    mitmes = 0
    keskmine = 0
    palju = 0
    parim = 1000
    for i in järjend:
        if i[0] != nimi:
            continue
        for j in i:
            if mitmes == 0:
                mitmes += 1
                continue
            keskmine += j
            palju += 1
            if j < parim:
                parim = j
    keskmine = round(keskmine / palju, 2)
    return (keskmine, parim)
            
#PROGRAMM
failinimi = input("Sisesta faili nimi: ")
sportlane = input("Sisesta sportlase nimi: ")
l = loe_andmed(failinimi)
print("Sportlane " + sportlane + ":")
print("- keskmine aeg on " + str(keskmine_ja_parim(l, sportlane)[0]) + " sekundit,")
print("- parim aeg on " + str(keskmine_ja_parim(l, sportlane)[1]) + " sekundit.")