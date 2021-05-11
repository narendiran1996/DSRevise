
givenArray = [3, 1, 2, 3, 6, 2, 3, 6, 2, 3, 6, 3, 2, 3, 6, 2, 3, 4, 3, 2, 5, 4, 2, 1, 2, 1, 2, 3,
              1, 2, 6, 2, 3, 6, 2, 3, 6, 3, 2, 3, 1, 5, 3, 2, 1, 2, 4, 2, 1, 8, 1, 2]

# givenArray = [10, 7, 12, 2, 4, 7, 2, 4, 1, 2, 6, 6, 3, 2, 1, 4, 7, 2, 7, 3, 1, 3, 11, 4, 2,
#              1, 5, 2, 3, 3, 3, 6, 1, 3, 9, 5, 2, 1, 2, 11, 9,2, 3, 8, 2, 5, 1, 2, 7, 2, 4, 11, 2, 12]

newArray = []
num = 0
newArray.append(num)
for i in range(0, len(givenArray)):
    if i % 2 == 0:
        num = num + givenArray[i]
    else:
        num = num - givenArray[i]
    newArray.append(num)
maxVal = max(newArray) + 2
sumVal = sum(newArray)

# print(newArray, sumsa)
BUFFERG = [[0 for j in range(sumVal)] for i in range(maxVal)]
G = 0
rindx = maxVal - 1
cindx = 0

humanDone = False
for i in range(1, len(newArray)):

    B = newArray[i]

    diff = B-G
    G = B
    for j in range(abs(diff)):
        sym = 0
        if(diff > 0):
            sym = 1
        else:
            sym = -1
        if(rindx == 2 and humanDone == False):
            # print("human")
            BUFFERG[rindx-2][cindx+1] = 2

            BUFFERG[rindx-1][cindx] = 1
            BUFFERG[rindx-1][cindx+1] = 3
            BUFFERG[rindx-1][cindx+2] = -1

            BUFFERG[rindx][cindx] = 4
            BUFFERG[rindx][cindx+2] = 5
            # print(rindx, cindx)
            # BUFFERG[rindx][cindx-1] = 2
            # BUFFERG[rindx][cindx] = 3
            humanDone = True
        else:
            if rindx != 2:
                BUFFERG[rindx][cindx] = sym
        if j != abs(diff) - 1:
            rindx = rindx - sym
        cindx = cindx + 1
st = ''

for i in BUFFERG:
    for j in i:
        if j == 0:
            st = st + ' '
        elif j == 1:
            st = st + '/'
        elif j == -1:
            st = st + '\\'
        elif j == 2:
            st = st + 'o'
        elif j == 3:
            st = st + '|'
        elif j == 4:
            st = st + '<'
        elif j == 5:
            st = st + '>'
    st = st + '\n'
# print(st)
with open('output.txt', 'w+') as f:
    f.write(st)
    f.close()
