class Animail(object):
    def eat(self):
        print('动物能吃')
class Dog(Animail):
    def eat(self):
        print('狗吃骨头。')
class Pig(Animail):
    def eat(self):
        print('猪吃糠')
class Human(object):
    def eat(self):
        print('人吃五谷杂粮')
def chi(obj):
    obj.eat()

chi(Dog())
chi(Human())
chi(Pig())
chi(Animail())