def failist_järjendisse(u):
    m = []
    s = []
    lugeja = 0
    fail = open(u)
    for rida in fail:
        rida = rida.split()
        s = []
        for i in rida:
            s.append(int(i))
        m.append(s)
    return m

def on_bingo_tabel(maatriks):
    false = 0
    for j in maatriks:
        for i in j:
            if j.index(i) == 0:
                if i > 15 or i < 1:
                    false = 1
            elif j.index(i) == 1:
                if i > 30 or i < 15:
                    false = 1
            elif j.index(i) == 2:
                if i > 45 or i < 30:
                    false = 1
            elif j.index(i) == 3:
                if i > 60 or i < 45:
                    false = 1
            elif j.index(i) == 4:
                if i > 75 or i < 60:
                    false = 1
    if false == 1:
        return False
    if false == 0:
        return True
                    
        
u = "bingo.txt"
print(str(on_bingo_tabel(failist_järjendisse(u))))
            
            