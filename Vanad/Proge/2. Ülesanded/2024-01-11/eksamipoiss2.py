import random
def lift(korrus): #algselt liftis 1 inimene
    if korrus == 0:
        return 1
    else:
        tõenäosus = random.randint(0, 100)
        if tõenäosus < 20:
            print(f'{korrus}. korrusel ei lisandunud kedagi')
            return lift(korrus - 1)
        elif tõenäosus > 19 and tõenäosus < 50:
            print(f'{korrus}. korrusel lisandus 2 inimest')
            return lift(korrus - 1) + 2
        else:
            print(f'{korrus}. korrusel lisandus 1 inimene')
            return lift(korrus - 1) + 1
    
print(f'Liftiga jõudis nullkorrusele kokku {lift(5)} inimest.')