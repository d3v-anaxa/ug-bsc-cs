#include <iostream>
#include <bits/stdc++.h>
using namespace std;

class parent {
    public :
        unsigned int parent_age{};
        void set_parent_age();
        parent(){};
        ~parent(){};
};

void parent::set_parent_age() {
    unsigned temp_age{};
    std::cout << "Enter parent's age : " && std::cin >> temp_age;
    if (temp_age <= 18){std::cout << "Under-Age!!" <<std::endl;return this->set_parent_age();}
    if (temp_age >= 100){std::cout << "You aren't dead  yet!!" <<std::endl;return this->set_parent_age();}
    parent_age = temp_age;
}

class child : public parent {
    public :
        unsigned int min_child_age{};
        void show_min_child_age();
        child(parent obj) {this->min_child_age = obj.parent_age - 18;};
        ~child(){std::cout << "Child OBJ destroyed" << std::endl;};
};

void child::show_min_child_age(){
    std::cout <<  "The child's minimum age should be " << min_child_age << "+ yrs" << std::endl;
}

int main(void) {
    parent father;
    father.set_parent_age();
    child elon(father);
    elon.show_min_child_age();
}
