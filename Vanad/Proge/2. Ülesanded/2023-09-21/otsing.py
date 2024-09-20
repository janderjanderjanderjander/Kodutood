from os.path import exists, getsize
def faili_suurus(a):
    if exists(a) == True:
        return getsize(a)
    else:
        return -1


print(faili_suurus("test.txt"))