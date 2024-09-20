lapsed = ['50303114923', '50303114923', '30102392013', '38283928472', '85738437289']
vanemad = ['48012204916', '39494941349', '49339320304', '49339320304', '49339320304']
seosed = {'50303114923': 'Jander', '48012204916': 'Ema', '49339320304': 'ÜksikIsa', '39494941349': 'Isa', '30102392013': 'SuvakasLaps', '38283928472': 'Pets', '85738437289': 'Ants'}
väljund = {}
mitu = -1
for i in vanemad:
    mitu += 1
    if seosed[i] in list(väljund.keys()):
        mälu = väljund[seosed[i]]
        mälu.add(seosed[lapsed[mitu]])
        väljund[seosed[i]] = mälu
    else:
        väljund[seosed[i]] = {seosed[lapsed[mitu]]}
print(väljund)
