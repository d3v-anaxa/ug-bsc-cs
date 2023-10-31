#include <iostream>
#include <cstring>

using namespace std;

class inp{
    string str{};
    public:
    inp(){this->str = " ";};
    inp(string str){this->str = str;};
    ~inp(){};
    inp operator + (inp arg){
        inp temp{};
        str.append(" ");
        temp.str = str.append(arg.str);
        return temp;
    }
    void display(){std::cout << this->str << std::endl;};
};

int main(void){
    string strF, strL;
    std::cout << "Enter first name : ";
    getline(cin, strF);
    inp Fname(strF);
    std::cout << "Enter last name : ";
    getline(cin, strL);
    inp Lname(strL);
    inp fullname;
    fullname = Fname + Lname;
    std::cout << "Your full name is : ";
    fullname.display();
    return 0;
}
