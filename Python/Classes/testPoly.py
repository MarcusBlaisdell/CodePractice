from math import pi

class Shape:
    def __init__(self, name):
        self.name = name

    def area(self):
        pass

    def base(self):
        return "Base class is Shape"

    def fact(self):
        return "I am a two-dimensional shape."

    def __str__(self):
        return self.name

class Square(Shape):
    def __init__(self, length):
        super().__init__("Square")
        self.length = length

    def area(self):
        return self.length**2

    def fact(self):
        return "Squares have four sides of equal length with each angle equal to 90 degrees"

class Circle(Shape):
    def __init__(self, radius):
        super().__init__("Circle")
        self.radius = radius

    def area(self):
        return pi*self.radius**2

    def base(self):
        return "I have been overridden, I am a Circle, my base class is Shape"

a = Square(4)
b = Circle(7)

print(b)
print(b.fact())
print(a.fact())
print(b.area())
print("a base: ", a.base())
print("b base: ", b.base())
#help(Circle)
