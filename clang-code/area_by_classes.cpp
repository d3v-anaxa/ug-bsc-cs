#include <cstdlib>
#include <iostream>

using namespace std;

class shape {
    private : 
        float l{}, b{}, s{};
        int select_option();
        void eval_area(float s);
        void eval_area(float l,float b );
    public :
        void get_output ();
};

int shape::select_option() {
    int x{};
    std::cout << "Select Shape" << std::endl;
    std::cout << "1-> Square" << std::endl;
    std::cout << "2-> Rectangle" << std::endl;
    std::cout << "Enter your choice : " && std::cin >> x;
    return x;
}

void shape::get_output () {
    switch (this->select_option()) {
        case 1 :
            std::cout << "Enter the length of every side of the square : " && std::cin >> this->s;
            if ( s <= 0) {std::cout << "Invalid input" << std::endl; exit(EXIT_FAILURE);}
            eval_area(s);
            break;
        case 2 :
            std::cout << "Enter the length of the rectangle : " && std::cin >> this->l;
            std::cout << "Enter the breadth of the rectangle : " && std::cin >> this->b;
            if ( l <= 0 || b <= 0) {std::cout << "Invalid input" << std::endl; exit(EXIT_FAILURE);}
            eval_area(l , b);
            break;
    }
}

void shape::eval_area(float s) {
    float area = s * s;
    std::cout << "The area of the square is : " << area << std::endl;
}

void shape::eval_area(float l, float b) {
    float area =l * b;
    std::cout << "The area of the rectangle is : " << area << std::endl;
}

int main(void) {
    shape abc;
    abc.get_output();
}
