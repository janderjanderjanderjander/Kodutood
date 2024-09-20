def kumba_on_rohkem(nimekiri):
    m = 0
    for i in nimekiri:
        if i == "poiss":
            m += 1
        elif i == "tüdruk":
            m -= 1
    if m > 0:
        return 1
    elif m < 0:
        return -1
    else:
        return 0

s = input("Sisestage tantsurühmas osalejate sugu: ")
l = kumba_on_rohkem(s.split())
if l > 0:
    print("Tantsurühmas on poisse rohkem")
elif l < 0:
    print("Tantsurühmas on tüdrukuid rohkem")
else:
    print("Tantsurühmas on poisse ja tüdrukuid võrdselt")
