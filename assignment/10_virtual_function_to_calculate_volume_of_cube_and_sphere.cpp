/*
PROGRAM 10 : Create a class object with show as virtual function. Inherit two
other classes sphere and cube from object. Calculate volume of sphere and cube
using necessary parameters and member function.

Algorithm :
STEP_1: Start
STEP_2: Declare class “object” with data member “volume” and virtual member function
“show” that prints the value of the data member volume
STEP_3: Declare a derived class “sphere” that inherits the base class “object” with data
member “radius” and a parameterized constructor that takes and integer input “radius” and
sets “radius” and calculates and sets “volume” of the object
STEP_4: Declare a derived class “cube” that inherits the base class “object” with data
member “side” and a parameterized constructor that takes and integer input “side” and
sets “side” and calculates and sets “volume” of the object
STEP_5: Declare pointer object *obj;
STEP_6: Choose between either “sphere” or “cube” derived class to create an instance
STEP_7: Write the address of the created instance to the created pointer variable “obj” of
class “object”
STEP_8: Read input
STEP_9: Print volume by calling the “show” function
STEP_10: End
 */

#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;
class object{
    public:
        double volume{};
        virtual void show(){std::cout << "Volume is : " << volume << std::endl;};
};
class sphere: public object{
    double radius{};
    public:
    sphere(double radius){
        this->radius = radius;
        object::volume = 4/3 * PI * pow(radius, 3);
    };
    ~sphere(){};
};
class cube: public object{
    double side{};
    public:
    cube(double side){this->side = side;object::volume = pow(side, 3);
    }
    ~cube(){};
};

int main(void){
    double n{};
    int choice{};
    object *obj;
    std::cout << "Object type : (1) Sphere (2) Cube" << std::endl;
    std::cout << "Enter choice : " && std::cin >> choice;
    switch(choice) {
        case 1 :{
                    std::cout << "Enter the radius the sphere : " && std::cin >> n;
                    if(n < 0){std::cout << "Invalid input!!" << std::endl; exit(EXIT_FAILURE);};
                    sphere obj1(n);
                    obj = &obj1;
                    break;}
        case 2 :{
                    std::cout << "Enter the length of each side of the cube : " && std::cin >> n;
                    if(n < 0){std::cout << "Invalid input!!" << std::endl; exit(EXIT_FAILURE);};
                    cube obj1(n);
                    obj = &obj1;
                    break;}
        default :{std::cout << "Invalid Choice!!" << std::endl;exit(EXIT_FAILURE);}
    }
    obj->show();
    return 0;
}

/*
Output :
Set-1 :
Object type : (1) Sphere (2) Cube
Enter choice : 1
Enter the radius the sphere : 21
Volume is : 29079.5
Set-2 :
Object type : (1) Sphere (2) Cube
Enter choice : 2
Enter the length of each side of the cube : 4.5
Volume is : 91.125
Discussion :
Time Complexity : O(n)
Space Complexity : O(1)
Program limitations : In the above program, input range of “side” and “range” is within
range of 1 to INT_MAX. Input beyond this limit may return inaccurate results.
*/
