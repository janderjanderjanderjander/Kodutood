tulemused = []
eesti = 0
soome = 0
fail = open("tulemused.txt")
for rida in fail:
    ühe_mängu_tulemused = []
    osad = rida.split()
    ühe_mängu_tulemused.append(float(osad[0]))
    ühe_mängu_tulemused.append(float(osad[1]))
    tulemused.append(ühe_mängu_tulemused)
fail.close()
for i in tulemused:
    if i[0] > i[1]:
            eesti += 1
    elif i[0] < i[1]:
            soome += 1
if eesti == 3:
    print("Eesti võitis 3-" + str(soome))
elif soome == 3:
    print("Soome võitis 3-" + str(eesti))
  
    
