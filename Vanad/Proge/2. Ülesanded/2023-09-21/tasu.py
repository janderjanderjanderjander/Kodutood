def arvuta_tasu(x, y):
    #x on töötatud tundide arv
    #y on tavaline tasumäär tunnis
    #40 on norm
    if x < 40:
        z = x * y
        return z
    else:
        p = x - 40
        z = 40 * y + p * (1.5 * y)
        return z

A = input("Esimene töötaja: ")
Aa = float(input("Tema tundide arv: "))
Ab = float(input("Tasumäär: "))
B = input("Teise nimi: ")
Ba = float(input("Tunnid: "))
Bb = float(input("Määr: "))

Apalk = float(arvuta_tasu(Aa, Ab))
Bpalk = float(arvuta_tasu(Ba, Bb))
if Apalk > Bpalk:
    print(A, "saab suuremat tasu kui", B)
elif Bpalk > Apalk:
    print(B, "saab suuremat tasu kui", A)
else:
    print("Nad saavad sama palju")
