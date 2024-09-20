s = [[' ','X','X',' '], ['X','O',' ',' '], ['X','O','O',' '], [' ','O',' ','O']]
#[' ','X','X',' ']
#['X','O',' ',' ']
#['X','O','O',' ']
#[' ','O',' ','O']



def kontrolli_diagonaale(maatriks):
    mitmes = 0
    mälu1 = 0
    mälu2 = 0
    mälu3 = 0
    mälu4 = 0
    for j in maatriks:
        for i in j:
            if mitmes == 0:
                if i != " ":
                    if mälu1 == 0:
                        mälu1 = i
                    
            
            









def kontrolli_ridu(maatriks):
    mälu = 0
    for i in maatriks:
        if i[0] == i[1] == i[2] != " " or i[1] == i[2] == i[3] != " ":
            mälu += 1
    return mälu

def kontrolli_veergusid(maatriks):
    mälu1 = 0
    mälu2 = 0
    mälu3 = 0
    mälu4 = 0
    mitmes = 0
    mälu = []
    for j in maatriks:
        for i in j:
            if mitmes == 0:
                mitmes += 1
                if i != " ":
                    if mälu1 == 0:
                        mälu1 = i
                    else:
                        mälu1 += i
            elif mitmes == 1:
                mitmes += 1
                if i != " ":
                    if mälu2 == 0:
                        mälu2 = i
                    else:
                        mälu2 += i
            elif mitmes == 2:
                mitmes += 1
                if i != " ":
                    if mälu3 == 0:
                        mälu3 = i
                    else:
                        mälu3 += i
            elif mitmes == 3:
                mitmes = 0
                if i != " ":
                    if mälu4 == 0:
                        mälu4 = i
                    else:
                        mälu4 += i
    mälu.append(mälu1)
    mälu.append(mälu2)
    mälu.append(mälu3)
    mälu.append(mälu4)
    mitmes = 0
    võimalused = ["XXX", "XXXO", "OXXX", "OOO", "OOOX", "XOOO"]
    for i in mälu:
        if i in võimalused:
            mitmes += 1
    return mitmes


            

                
print(kontrolli_veergusid(s))
            
            