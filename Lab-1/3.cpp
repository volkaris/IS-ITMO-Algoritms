n=int(input())
a=list(map(int,input().split()))
q=min(a)
a.remove(q)
p=min(a)
print(q,p)