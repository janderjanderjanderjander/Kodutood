def erinevad_sümbolid(sõne):
    dic = set(sõne)
    return dic

def sümbolite_sagedus(sõne):
    sõnel = list(sõne)
    dic = set(sõne)
    booja = {}
    for i in dic:
        booja[i] = sõnel.count(i)
    return booja
    
def grupeeri(sõne):
    sõnel = list(sõne)
    sõnes = set(sõne)
    sõnes = list(sõnes)
    täht_list = []
    mälu = []
    for i in range(0, len(sõnes)):
        mälu.append(sõnes[i])
        mälu.append(sõnel.count(sõnes[i]))
        mälu = tuple(mälu)
        täht_list.append(mälu)
        mälu = []
    täishäälikud = "aeiouöäõüAEIOUÖÄÕÜ"
    kaashäälikud = "qwrtyplkjhgfdszxcvbnmQWRTYPLKJHGFDSZXCVBNM"
    lõpptik = {"Täishäälikud": {}, "Kaashäälikud": {}, "Muud": {}}
    for i in täht_list:
        i = list(i)
        if täishäälikud.find(i[0]) != -1:
            mälu = list(lõpptik["Täishäälikud"])
            mälu.append(tuple(i))
            mälu = set(mälu)
            lõpptik.update({"Täishäälikud": mälu})
            mälu = []
        elif kaashäälikud.find(i[0]) != -1:
            mälu = list(lõpptik["Kaashäälikud"])
            mälu.append(tuple(i))
            mälu = set(mälu)
            lõpptik.update({"Kaashäälikud": mälu})
            mälu = []
        else:
            mälu = list(lõpptik["Muud"])
            mälu.append(tuple(i))
            mälu = set(mälu)
            lõpptik.update({"Muud": mälu})
            mälu = []
    return lõpptik

print(grupeeri("assa poiss ahaa"))