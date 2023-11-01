n = int(input())
c = []
for i in range(n) :
    a, b = map(int,input().split())
    c.append([a,b])
c.sort()
minc, maxc = c[0]
k = 0
for i in range(1,n):

    if c[i][1] > maxc :
        if c[i][0] <= maxc :
            maxc = c[i][1]                  #рассматриваем случай когда правая первая левая меньше или равна предыдущей,но второй чел закрасил больше чем первый

        else :
            k += maxc - minc + 1    #если  такого нет,то просто из конца вычитаем начало
            minc, maxc = c[i]

k += maxc - minc + 1 #если было,то все равно считаем также
print(k)