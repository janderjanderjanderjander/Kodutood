temperatuurid = []
fail = open("arvud.txt")
for rida in fail:
    ühe_päeva_temperatuurid = []
    osad = rida.split()
    ühe_päeva_temperatuurid.append(float(osad[1]))
    ühe_päeva_temperatuurid.append(float(osad[0]))
    temperatuurid.append(ühe_päeva_temperatuurid)
fail.close()
 
print(temperatuurid)