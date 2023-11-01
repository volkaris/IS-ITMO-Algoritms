def quick_sort(s):
    if len(s)<=1:
        return s
    pivot=s[0]
    left=list(filter(lambda x: x<pivot,s))
    right=list(filter(lambda x: x>pivot,s))
    center=[i for i in s if i==pivot]
    return quick_sort(left)+center+quick_sort(right)

n=int(input())
l=quick_sort(list(map(int,input().split())))
for k in l:
    print (k,end=" ")
