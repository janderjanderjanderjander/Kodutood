fail = open("pikkused.txt")
failist = fail.readlines()
lühim = 300
test = 100
pikim = 0
mitu = 0
keskmine = 0
for rida in failist:
    mitu += 1
    keskmine += int(rida)
    if lühim > int(rida):
        lühim = int(rida)
    elif pikim < int(rida):
        pikim = int(rida)
print("Kõige lühema korvpalluri pikkus on", lühim, "cm")
print("Kõige pikema korvpalluri pikkus on", pikim, "cm")
print("Meeskonnas on", mitu, "korvpallurit.")
print("Korvpallurite keskmine pikkus on", round((keskmine / mitu), 1),".")

    