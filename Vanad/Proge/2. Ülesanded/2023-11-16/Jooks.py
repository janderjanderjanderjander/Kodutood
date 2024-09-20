def failid_listi(failide_arv):
    tagastus_list = []
    for i in range(1, failide_arv + 1):
        hetkeline_list = []
        with open("üritus" + str(i) + ".txt", encoding = "UTF-8") as fail:
            for rida in fail:
                rida = rida.strip("\n")
                hetkeline_list.append(rida)
            tagastus_list.append(hetkeline_list)
    return tagastus_list

def failist_sõnastikku(failide_arv):
    tagastus_sõn = {}
    hetkeline_list = []
    mitmes = 0
    for i in range(1, failide_arv + 1):
        mitmes+= 1
        with open("üritus" + str(i) + ".txt", encoding = "UTF-8") as fail:
            for rida in fail:
                rida = rida.strip("\n")
                hetkeline_list.append(rida)
            tagastus_sõn[mitmes] = hetkeline_list
            hetkeline_list = []
    return tagastus_sõn

sisestus_üritus = int(input("Sisesta ürituste arv: "))
mälu = []
tagastus = []
mitmes = 0
mitu_uut = 0
võrdlus = []
s = failid_listi(sisestus_üritus)
se = failist_sõnastikku(sisestus_üritus)
for i in s:
    for j in i:
        mitmes += 1
        if j in mälu:
            if j in tagastus:
                continue
            tagastus.append(j)
            continue
        mälu.append(j)
        mitu_uut += 1
        print(j)
    if s[0] != i:
        võrdlus.append(mitu_uut)
    mitu_uut = 0
tagastus = []
mälu = []
mälu2 = []
mitmes = 0
mitu_uut = 0
print("Inimesed, kes osalesid mingil kahel järjestikusel üritusel, on:")
for i in se:
    if i == 1:
        continue
    l = set(se[i]) & set(se[i-1])
    if l == set():
        continue
    for i in l:
        if i in mälu:
            continue
        mälu.append(i)
for i in mälu:
    print(i)
try:
    print("Kõige rohkem esmakordseid osalejaid, " + str(max(võrdlus)) + " osalejat, oli üritusel " + str(võrdlus.index(max(võrdlus)) + 2) + ".")
except:
   print("Ainult üks üritus")