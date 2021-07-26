k = int(input())
t=[0,1,3]
n=3
while n<=k:
    if t[n-1]-n>0 and t[n-1]-n not in t:
        t.append(t[n-1]-n)
    else:
        t.append(t[n-1]+n)
    n+=1
print(t[k])


n = int(input())
l=[0]
while len(l)<n+1:
    i=len(l)
    if l[-1]-i>0 and l[-1]-i not in l:l+=l[-1]-i
    else:l+=l[-1]+i
print(l[n])