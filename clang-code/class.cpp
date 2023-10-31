#include <iostream>

class newClass {
    private : 
        int getInput();

    public : 
        void getFactorial();
};

int newClass::getInput() {
    int start = 0;
    std::cout << "Input a positive integer : " && std::cin >> start;
    if (start < 1) {
        std::cout << "invalid input value" << std::endl;
        return newClass::getInput();
    }
    return start;
}


void newClass::getFactorial(){
    static int n = newClass::getInput();
    int factorial = 1;
    while (n != 1) {
        factorial *= n;
        --n;
    }
    if (factorial <= 0) {
    std::cout << "Limit Exceeded" << std::endl;
    exit(EXIT_SUCCESS);
    }
    std::cout << " Factorial  : " << factorial << std::endl;
}

int main () {
    newClass obj1;
    obj1.getFactorial();
    return 0;
}
