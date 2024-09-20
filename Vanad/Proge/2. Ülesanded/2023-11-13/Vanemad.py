fail1 = "lapsed.txt"
fail2 = "nimed.txt"
def seosta_lapsed_ja_vanemad(fail1, fail2):
    lapsed = []
    vanemad = []
    seosed = {}
    väljund = {}
    fail = open(fail1, "r", encoding="UTF-8")
    for rida in fail:
        rida = rida.strip().split()
        lapsed.append(rida[0])
        vanemad.append(rida[1])
    fail.close()
    fail = open(fail2, "r", encoding="UTF-8")
    for rida in fail:
        rida = rida.strip().split()
        seosed[rida[0]] = rida[1] + " " + rida[2]
    mitu = -1
    for i in vanemad:
        mitu += 1
        if seosed[i] in list(väljund.keys()):
            mälu = väljund[seosed[i]]
            mälu.add(seosed[lapsed[mitu]])
            väljund[seosed[i]] = mälu
        else:
            väljund[seosed[i]] = {seosed[lapsed[mitu]]}
    return väljund
se = seosta_lapsed_ja_vanemad(fail1, fail2)
ss = list(se.items())
ss[0], ss[1], ss[2], ss[3] = ss[3], ss[1], ss[0], ss[2]
s = dict(ss)
for i in s:
    S = ", ".join(s[i])
    print(i + ": " + S)
    