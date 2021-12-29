# class Person:
#     def __init__(self):
#         self.name = 'Sarah'
#         self._age = 26
#         self.__id = 30

# p = Person()
# print(p._Person__id)


class Color():
    def __init__(self, color, value):
        self.__color = color
        self.__value = value
    
    @property
    def color(self):
        return self.__color
    
    @color.setter
    def color(self, color):
        self.__color = color

    @property
    def value(self):
        return self.__value
    
    @value.setter
    def value(self, value):
        self.__value = value

cor = Color(color="Preto", value="#000")
print(cor.color)
cor.color="white"
cor.value="#fff"
print(cor.color)