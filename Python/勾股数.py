import time as t
a=3;b=3             #初始化赋值
d={}             #创建名为d的字典
for x in range(10000):
    d[x**2]=x
while a<=10000:
    b=b+1;c=a**2+b**2
    if c<=100000000:
        if c in d:
           print(a,b,d[c])
    else:
        a=a+1;b=a
print('end',)