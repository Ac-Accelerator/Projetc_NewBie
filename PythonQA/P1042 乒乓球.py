c=""
while True:
    a=input()
    c+=a
    if 'E' in a:
        break
n11=int(c.index('E'))
point=0
for b in range(int (n11/11)+1):
    hua=0  
    dui=0
    if(b==int(n11/11)):
        for _ in range(n11%11):
            if(c[point]=='W'):
                hua+=1
            else :
                dui+=1
            point+=1
    else :
        for _ in range(11):
            if(c[point]=='W'):
                hua+=1
            else :
                dui+=1
            point+=1
    print(f"{hua}:{dui}")
print("")
point=0
for b in range(int (n11/21)+1):
    hua=0
    dui=0
    if(b==int(n11/21)):
        for _ in range(n11%21):
            if(c[point]=='W'):
                hua+=1
            else :
                dui+=1
            point+=1
    else :
        for _ in range(21):
            if(c[point]=='W'):
                hua+=1
            else :
                dui+=1
            point+=1
    print(f"{hua}:{dui}")

