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
a=input('a=');b=input('b=');c=input('c=')
a=float(a);b=float(b);c=float(c)
k=j(a,b,c)
print (k)
