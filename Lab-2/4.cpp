a=[]
n=int(input())
a=list(map(int,input().split()))
count=0
flag=False
for i in range(1,len(a)):
    k=i
    while k!=0 and a[k-1]>a[k]:
        a[k - 1],a[k]=a[k],a[k-1]
        k-=1
        flag=True
    if flag==True:
        print(*a)
        flag=False
