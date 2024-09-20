import time
protsent = float(input("Sisesta jahtumisprotsend: ")) / 100
supi_temp = float(input("Sisesta supi algtemperatuur: "))
ruumi_temp = float(input("Sisesta ruumi temperatuur: "))


langus = (supi_temp - ruumi_temp) * protsent

while supi_temp > ruumi_temp + 0.001:

    langus = (supi_temp - ruumi_temp) * protsent
    if langus == 0:
        langus = 0.1
        pass
    supi_temp = supi_temp - langus
    print("Supi temperatuur on hetkel ", supi_temp, "kraadi.")
    time.sleep(3)
print("Supp on jahtunud toatemperatuurile")