def teisenda(x):
    if x > 1024:
        xKB = x / 1024
        if xKB > 1024:
            xMB = xKB / 1024
            if xMB > 1024:
                xGB = xMB / 1024
                return str(round(xGB, 1)) + " GB"
            else:
                return str(round(xMB, 1)) + " MB" 
        else:
           return str(round(xKB, 1)) + " KB"      
    else:
        return str(round(x, 1)) + " B"


print(teisenda(2030203201032))