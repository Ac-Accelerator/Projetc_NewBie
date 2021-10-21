class A:
    pass
class B:
    pass
class C(A,B):
    def __init__(self,name,age):
        self.name=name
        self.age=age
p1=C('jack',24)
print(p1.__dict__) #实例对象的属性字典
print(C.__dict__)
print(p1.__class__)#输出对象所属的类
print(C.__bases__)#输出其所有父类元组
print(C.__base__)#输出定义在前的父类
print(C.__mro__)#输出类的层次结构
print(A.__subclasses__())#输出子类列表，记得加括号