n=int(input())
s=list(map(int,input().split()))
def merge_two_list(a,b):    #используем метод 2 указателей
        c=[]
        i=j=0
        while i<len(a) and j<len(b):
            if a[i]<b[j]:
                c.append(a[i])
                i+=1
            else:
                c.append(b[j])
                j+=1
        if i<len(a):
            c+=a[i:]
        elif j<len(b):
            c+=b[j:]

        return c

def merge_sort(s):
    if len(s)==1:
        return s
    middle=len(s)//2
    left=merge_sort(s[:middle])
    right=merge_sort(s[middle:])
    return merge_two_list(left,right)

for i in merge_sort(s):
    print(i,end=" ")