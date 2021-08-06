# describe the Color class with 'color' and rgb 'value'
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
        