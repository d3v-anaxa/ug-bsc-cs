/*
Program 12 : Design a class polar which describes a point in the plain using
polar coordinates radius and angle. Use overloaded operator to add two objects
of Polar.
Algorithm :
STEP_1: Start
STEP_2: Declare class “polar” with data members “radius” and “angle”, member functions
“set_data” to read and set “radius” and “angle”
STEP_3: Inside the class “polar”, “+” operator is overloaded in order to add two polar
objects together by using the mathematical rules of addition of polar coordinates.
STEP_4: In the “main” function, create three polar objects “obj1”, “obj2” and “obj3”
STEP_5: Call “set_data” member function over “obj1” and “obj2” and set the values
STEP_6: obj3 ⇐ obj1 + obj2
STEP_7: print “radius” and “angle” which were stored data inside “obj3”
STEP_8: End
*/
#include <iostream>
#include <cmath>
#define PI 3.14
class polar{
    double radius{}, angle{};
    public:
    void set_data(){
        double r{}, a{};
        std::cout << "Enter radius : " && std::cin >> r;
        std::cout << "Enter angle (in degree[°]) : " && std::cin >> a;
        radius = r;
        angle = a;
    }
    double deg_to_rad(double angle){return PI / double(180) * angle;};
    double rad_to_deg(double angle){return double(180) / PI * angle;};
    polar operator + (polar obj){
        polar temp_p;
        double temp_1{}, temp_2{}, temp_rad{};
        double obj_angle_in_rad = (deg_to_rad(obj.angle));
        double temp_angle_in_rad = (deg_to_rad(angle));
        temp_1 = (radius * cos(temp_angle_in_rad)) + (obj.radius * cos(obj_angle_in_rad));
        temp_2 = (radius * sin(temp_angle_in_rad)) + (obj.radius * sin(obj_angle_in_rad));
        temp_rad = atan(temp_2 / temp_1);
        temp_p.radius = sqrt(temp_1 * temp_1 + temp_2 * temp_2);
        temp_p.angle = rad_to_deg(temp_rad);
        return temp_p;
    }
    void display(){std::cout << "Polar value : " << radius << " ∠" << angle << "°" <<
        std::endl;};
};
int main(void){
    polar obj1, obj2, obj3;
    obj1.set_data();
    obj1.display();
    obj2.set_data();
    obj2.display();
    obj3 = obj1 + obj2;
    std::cout << "Value after addition" << std::endl;
    obj3.display();
    return 0;
}
/*
Output :
Set-1 :
Enter radius : 6
Enter angle (in degree[°]) : 120
Polar value : 6 ∠120°
Enter radius : 10
Enter angle (in degree[°]) : 36.9
Polar value : 10 ∠36.9°
Value after addition
Polar value : 12.268 ∠65.9594°
Set-2 :
Enter radius : 20
Enter angle (in degree[°]) : 22.5
Polar value : 20 ∠22.5°
Enter radius : 35
Enter angle (in degree[°]) : 75
Polar value : 35 ∠75°
Value after addition
Polar value : 49.7773 ∠56.4094°
Discussion :
Time Complexity: O(n)
Space Complexity: O(1)
*/
