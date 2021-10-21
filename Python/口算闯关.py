import random
t=-1
while True:
    t+=1
    a=random.randint(1,100)
    b=random.randint(1,100)
    c=a+b
    d=input(f'{a}+{b}=')
    while True:
        try:
            d=int(d)
            break
        except:
            print('你输入了奇怪的数据,请重新输入')
            d=input(f'{a}+{b}=')
    if c==d:
        print('你答对啦，下一轮')
    else:
        print(f'游戏结束，正确答案是{c},你本次游戏的积分是{t}')
        break
input()
