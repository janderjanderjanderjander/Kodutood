fail = open("hinnad.txt")
failist = fail.readlines()
summa = 0
kogu = 0
for rida in failist:
    try:
        summa += float(rida)
        kogu += 1
    except:
        continue
print("Ostetud kaupade koguarv on ", kogu, ", kogusummaga ", summa + 0.00)