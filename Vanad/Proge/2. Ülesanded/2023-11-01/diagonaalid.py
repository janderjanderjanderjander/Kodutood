def peadiagonaali_summa(maatriks):
    mitmesS = -1
    mälu = []
    for j in maatriks:
        mitmesS += 1
        mitmesV = -1
        for i in j:
            mitmesV += 1
            if mitmesV == mitmesS:
               mälu.append(i)
            else:
                continue
    summa = 0
    for i in mälu:
        summa += i
    return summa

def kõrvaldiagonaali_summa(maatriks):
    mitmesS = 0
    for j in maatriks:
        mitmesS += 1
    mälu = []
    for j in maatriks:
        mitmesS -= 1
        mitmesV = -1
        for i in j:
            mitmesV += 1
            if mitmesV == mitmesS:
               mälu.append(i)
            else:
                continue
    summa = 0
    for i in mälu:
        summa += i
    return summa

def diagonaalide_vahe(maatriks):
    return peadiagonaali_summa(maatriks) - kõrvaldiagonaali_summa(maatriks)