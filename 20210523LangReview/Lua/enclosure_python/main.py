
def getInt():
    tmp = [0]
    def addOne():
        tmp[0] += 1
        return tmp[0]
    return addOne

g = getInt()
for i in range(3):
    print(g())