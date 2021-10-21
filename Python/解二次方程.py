import math
def j(a,b,c):
    if a==0:
        return -c/b
    elif b**2-4*a*c>0:
        t1= (-b-math.sqrt(b**2-4*a*c))/2/a
        t2= (-b+math.sqrt(b**2-4*a*c))/2/a
        return t1 ,t2
    elif b**2-4*a*c==0:
        return -b/2/a
    else:
        return 'None'
a,b,c=map(float,input('please input a,b,c in order:\n').split())
k=j(a,b,c)
print (k)
