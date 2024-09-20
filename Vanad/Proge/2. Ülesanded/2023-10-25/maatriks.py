def vahimatest_suurim(maatriks):
    suurem_mälu = []
    for rida in maatriks:
        mälu = None
        for i in rida:
            if mälu == None or i < mälu:
                mälu = i
        suurem_mälu.append(mälu)
    mälu = None
    for rida in suurem_mälu:
        if mälu == None or rida > mälu:
            mälu = rida
    return mälu

print(vahimatest_suurim([[-1, 9], [5, -1], [-1, 1]]))