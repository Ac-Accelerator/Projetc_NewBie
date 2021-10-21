l=[]
n=0
while True:
    a,b=map(int,input().split())
    if a==0 and b==0:
        break
    c=[a,b]
    l=l+c
    n+=1
for t in range(0,2*n,2):
    print(l[t]+l[t+1])
