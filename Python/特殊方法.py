#class Student:
#    def __init__(self,name):
#        self.name=name
#stu1=Student('张三')
#stu2=Student('李四')
#s=stu1+stu2             报错，str不能相加'''
class Student:
    def __init__(self,name):
        self.name=name
    def __add__(self,other):    #重新解释+号在对象中的方法
        return self.name+other.name
stu1=Student('张三')
stu2=Student('李四')
s=stu1+stu2                     #让两个对象相加
s=stu1.__add__(stu2)            #方法2
print(s)

#class Fstudent:
#    def __init__(self,name):
#        self.name=name
#stu3=Fstudent('jack')
#s=len(stu3)             报错，不支持
class Fstudent:
    def __init__(self,name):
        self.name=name
    def __len__(self):          #解决方法同上
        return len(self.name)
stu3=Fstudent('jack')
s=len(stu3)
print(s)