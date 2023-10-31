/*
Program 11 : Copy the contents of one text file to another file, after removing all
whitespaces.
Algorithm :
STEP_1: Start
STEP_2: function copyToAnotherFile
STEP_2.1: Input filename “fin”
STEP_2.2: Input filename “fout”
STEP_2.3: Declare two file pointers fl1 and fl2
STEP_2.4: Declare ch
STEP_2.5: Set fl1 file ponter at the beginning of “fin” in read mode
STEP_2.6: Set fl2 file ponter at the beginning of “fout” in write mode
STEP_2.7: Read character fl1 and set it inside ch
STEP_2.8: While ((ch = fgetc(fl1))!= EOF)
STEP_2.8.1: Print ch
STEP_2.8.2: if (ch != ‘ ‘)
STEP_2.8.2.1: Insert ch through fl2 pointer inside “fout” file
STEP_2.8.3: end if
STEP_2.9: end While
STEP_2.10: Close fl2 file pointer
STEP_2.11: Set fl2 file ponter at the beginning of “fout” in read mode
STEP_2.12: Read character fl2 and set it inside ch
STEP_2.13: While ((ch = fgetc(fl1))!= EOF)
STEP_2.13.1: Print ch
STEP_2.14:end While
STEP_3: end function copyToAnotherFile
STEP_4: Read input and output filenames
STEP_5: Call function copyToAnotherFile with both filenames as arguments
STEP_ 6 : End
*/
#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <unistd.h>
using namespace std;
void copyToAnotherFile(char fin[], char fout[]){
    FILE *fl1,*fl2;
    char ch;
    fl1 = fopen(fin, "r");
    fl2 = fopen(fout, "w");
    std::cout << "[CONTENTS OF \"" << fin << "\" FILE]" <<std::endl;
    while ((ch = fgetc(fl1))!= EOF){
        std::cout << ch;
        if (ch != ' '){fputc(ch, fl2);};
    }
    std::cout << "[CONTENTS OF \"" << fout << "\" FILE]" <<std::endl;
    fclose(fl2);
    fl2 = fopen(fout, "r");
    while ((ch = fgetc(fl2))!= EOF){std::cout << ch;}
    fclose(fl1);
    fclose(fl2);
}
int main(int argc, char **argv){
    switch (argc) {
        case 1 : {std::cout << "Specify Input and Output file" << std::endl;exit(EXIT_FAILURE);}
        case 2 : {std::cout << "Specify Output file" << std::endl;exit(EXIT_FAILURE);}
        case 3 : {if (access(argv[1], F_OK) != 0) {
                     std::cout << argv[1] << "Input file not found!!" << std::endl;
                     exit(EXIT_FAILURE);}
                 copyToAnotherFile(argv[1], argv[2]);
                 break;
                 }
        default : {std::cout << "Too many arguments" << std::endl;exit(EXIT_FAILURE);}
    }
    return 0;
}
/*
Output :
Set-1 : [$ ./a.out sample.txt new.txt ]
[CONTENTS OF "sample.txt" FILE]
foot ball
water melon
jack pot
[CONTENTS OF "new.txt" FILE]
football
watermelon
jackpot
Set-2 : [$ ./a.out sample2.txt new2.txt ]
[CONTENTS OF "sample2.txt" FILE]
butter flies
robin hood
note book
[CONTENTS OF "new2.txt" FILE]
butterflies
robinhood
notebook
Discussion :
Time Complexity: O(n)
Space Complexity: O(1)
Program Limitation: In the above program, only plain text files are allowed as input file.
*/
