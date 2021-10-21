class Person:        #声明一条类，默认类名称首字母大写，不然其他程序员看不懂
    birth_place='hunan'   #这玩意是个类属性
    def __init__(b,name,age,weight):  #叫做初始化方法,默认好像会叫self，后面可加变量
        b.name=name         #前面的叫做实例属性
        b.age=age           #为方便，前后名称一致比较好
        b.__weight=weight   #在前面加了两个下划线，不希望在类外被调用
    def eat(self):          #在类之外定义叫函数，在类中定义实例方法，习惯上写为self，可改成别的，空的也行
        print('人在吃饭')
    def weight(self):       #在类内调用weight构建的函数
        print(self.__weight)
    @staticmethod           #声明静态方法
    def sleep():            #默认不能有
        print('sleep在街上')
    @classmethod            #声明类方法
    def study(cls):         #不知为何写cls
        print('类方法')

stu1=Person('邓宇哲',18,47)   #创建Person类的对象
stu1.eat()                  #调用eat函数
Person.eat(stu1)           #方法2
print(stu1.name)            #输出
print(stu1.age)
#print(stu1.__weight)        出错，不希望被调用
print(stu1._Person__weight) #在类外强制调用
stu1.weight()               #在类内调用

print(stu1.birth_place)     #类属性的使用
Person.birth_place='湖南'
print(stu1.birth_place)     

Person.study()             #类方法的使用
Person.sleep()             #静态方法的使用

stu1.gender='男'            #动态绑定属性
print(stu1.gender)          #显示动态属性

def show():                 #定义函数
    print('动态绑定成功')
stu1.show=show              #动态绑定方法
stu1.show()                 #调用

class Student(Person):         #声明Student类，继承自Person
    def __init__(b, name, age, weight,stu_num): #定义对象属性
        super().__init__(name, age, weight)     #super().跟着继承的属性
        b.stu_num=stu_num
    def IDinfo(self):                       #定义函数
        print(self.name,self.stu_num)
    def sleep(self):                            #方法重写
        print('学生的sleep')
    def study(cls):
        super().study()                         #如果你依然希望调用父类
        print('lalala')

stu2=Student('张三',45,76,13401)        #引入对象张三
stu2.eat()                      #调用eat函数，可知其可以直接调用父类的函数
stu2.IDinfo()                   #调用本身类的函数也可
stu2.weight()                   #也属于类内调用
stu2.sleep()                    #方法重写的调用，并不会继承其父类的
stu2.study()                    #有对父类的调用，也有后面的