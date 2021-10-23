a,b=map(int,input().split())
l=[]
while True:
    k=input()
    for i in k:
        if(i==' '):
            continue
        if(i=='-'):
            
        l.append(int(i))
    if len(l)==a:
        break
if b in l:
    print(l.index(b)+1)
else :
    print(len(l)+1)