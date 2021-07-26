m=input('larger:');n=input('smaller:')
m=int(m);n=int(n)
t=m*n
r=521
while not r==0:
    r=m-n
    while r-n>=0:
        r=r-n
    if not r==0:
        m=n;n=r
    else:
        print('最大公约数为:',n,'最小公倍数为:',int(t/n))
input('运算结果显示完毕')