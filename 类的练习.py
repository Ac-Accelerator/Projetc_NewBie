class Student:        #我TM开局声明一条类，默认类名称首字母大写，不然其他程序员看不懂
    birth_place='hunan'   #这玩意是个类属性
    def __init__(b,name,age):  #叫做初始化方法,默认好像会叫self，后面可加变量
        b.name=name         #前面的叫做实例属性
        b.age=age           #为方便，前后名称一致比较好
    def eat(self):          #在类之外定义叫函数，在类中定义实例方法，习惯上写为self，可改成别的，空的也行
        print('学生在吃饭')
    @staticmethod           #声明静态方法
    def sleep():            #默认不能有
        print('sleep在街上')
    @classmethod            #声明类方法
    def study(cls):         #不知为何写cls
        print('类方法')