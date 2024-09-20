def kuld(mitmes):
    if mitmes == 0:
        return 1
    else:
        return mitmes - 1 + kuld(mitmes - 1)
def kuld2(mitmes):
    if mitmes == 0:
        return 0
    elif mitmes == 1:
        return 1
    else:
        return (mitmes-1) * (mitmes-1) + kuld2(mitmes - 1)
def kuld3(mitmes):
    if mitmes == 0:
        return 0
    elif mitmes == 1:
        return 1
    else:
        return 2 * kuld3(mitmes - 1) + 1