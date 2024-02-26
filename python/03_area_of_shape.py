class Rectangle:
    def __init__(self):
        self.length = float(input("Enter length (unit/s): "))
        self.breadth = float(input("Enter breadth (unit/s): "))
        self.area = self.length * self.breadth
        print(f"Area -> {self.area} sq. units.")

class Square:
    def __init__(self):
        self.side = float(input("Enter length of each side (unit/s): "))
        self.area = self.size ** 2
        print(f"Area -> {self.area} sq. units.")

    
class Circle:
    def __init__(self):
        self.radius = float(input("Enter radius (unit/s): "))
        PI = 3.1415926
        self.area = PI * self.radius ** 2
        print(f"Area -> {self.area} sq. units.")

class Triangle:
    def __init__():
        self.left = float(input("Enter length of left side: "))
        self.base = float(input("Enter length of base side: "))
        self.right = float(input("Enter length of right side: "))
        self.semi_param = (self.left + self.base + self.right)/2
        self.area = (self.semi_param * 
                     (self.semi_param - self.left) *
                     (self.semi_param - self.base) *
                     (self.semi_param - self.right)) ** 0.5
        print(f"Area -> {self.area} sq. units.")

match int(input("1. Rectangle/ 2. Square/ 3. Circle/ 4. Triangle : ")):
    case 1:
        Rectangle()

    case 2:
        Square()

    case 3:
        Circle()

    case 4:
        Triangle()

    case _:
        print("Invalid choice!")


