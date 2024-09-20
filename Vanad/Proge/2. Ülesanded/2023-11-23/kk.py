li = [9, 8, 7, 6, 5, 4, 3, 2, 1]
for i in li:
    if li.index(i) % 2 == 0:
        li.remove(i)
print(li)