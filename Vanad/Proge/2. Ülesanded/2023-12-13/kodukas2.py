def on_palindroom(sõne):
    if len(sõne) <= 1:
        return True
    else:
        return sõne[0] == sõne[-1] and on_palindroom(sõne[1:-1])
#- - - programm - - -
print(on_palindroom(input("Sisesta sõna: ")))