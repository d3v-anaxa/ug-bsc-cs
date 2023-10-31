#include <iostream>
using namespace std;

class binaryString {
    private :
        string bin = "";
        string bin_1_comp = "";
        void check(string temp);
    public:
        void set_bin();
        void get_bin();
        void get_comp_1();
        void menu();
        binaryString(string temp);
        ~binaryString();
};

void binaryString::check(std::string temp) {
    int decimal_count = 0;
    for (int i = 0; i < temp.length(); ++i) {
        switch ( temp[i] ) {
            case '0' : 
                binaryString::bin += "0";
                binaryString::bin_1_comp += "1";
                break;

            case '1' :
                binaryString::bin += "1";
                binaryString::bin_1_comp += "0";
                break;

            case '.' :
                ++decimal_count;
                binaryString::bin += ".";
                binaryString::bin_1_comp += ".";
                if (decimal_count > 1) {
                    std::cerr << "invalid decimal_point count" << std::endl;
                    exit(EXIT_FAILURE);
                    }
                break;

            default :
                std::cout << "Invalid binary string input" << std::endl;
                exit(EXIT_FAILURE);
        }
    }
    binaryString::get_comp_1();
}

void binaryString::set_bin() {
    string temp{};
    std::cout << "Enter a binary string : " && std::cin >> temp;
    binaryString::bin = "";
    binaryString::bin_1_comp = "";
	std::cout << std::endl;
    binaryString::check(temp);
}

void binaryString::get_bin() {
    std::cout << "Binary string : " << bin << std::endl;
}

void binaryString::get_comp_1() {
    std::cout << "1's complement of " << bin << " is : " << bin_1_comp <<std::endl;
}

void binaryString::menu() {
    int choice{};
    char rep{};
    do {
        std::cout << std::endl;
	    std::cout << "1. get binary string" << std::endl;
	    std::cout << "2. set binary string" << std::endl;
	    std::cout << "3. get 1's complement" << std::endl;
	    std::cout << std::endl;
	    std::cout << "Enter your choice [1-3]: " && std::cin >> choice;
	    switch (choice) {
	        case 1 :
	            std::cout << std::endl;
	            binaryString::get_bin();
	            break;
	        case 2 :
	            std::cout << std::endl;
	            binaryString::set_bin();
	            break;
	        case 3 :
	            std::cout << std::endl;
	            binaryString::get_comp_1();
	            break;
	        default :
	            break;
	     }
	    std::cout << std::endl;
	    std::cout << "Do you want to continue [y/n] : " && std::cin >> rep; 
    } while (rep != 'n');
}

binaryString::binaryString (std::string temp) {
    binaryString::check(temp);
}

binaryString::~binaryString () {
    std::cout << "Object destroyed" << std::endl;
}


int main (int argc, char **argv) {
    if (argc == 1) {
        std::cout << "Enter a binary string as a command line argument" << std::endl;
        exit(EXIT_FAILURE);
    }
    if (argc != 2) {
        std::cout << "Too many Arguments" << std::endl;
        exit(EXIT_FAILURE);
    }
    binaryString obj(argv[1]);
    obj.menu();
	std::cout << std::endl;
}
