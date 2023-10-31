# Semester-1 CMSA notes and source code

## Build all binary files

 ```
mkdir bin; for f in *.c ; do gcc $f -o bin/${f%.c}.out ; done ; for f in *.cpp ; do g++ $f -o bin/${f%.cpp}.out ; done ;
 ```
## Lecture notes

* SEPT 22, 2022 ---------------------------------> PM

\\ Preprocessor directives in C

We can consider a preprocessor as a compilation process, which runs when the developer runs the program. It is a pre-process of execution of a program using c/c++ language. To initialize a process of preprocessor commands, it's mandated to define with a hash symbol (#).  It can  preferably be the non-blank character, and for better readability, a preprocessor directive should start in the first column.

List of Preprocessor Directives
To execute a preprocessor program on a certain statement, some of the preprocessor directives types are:

```c
#define: It substitutes a preprocessor using macro.
#include: It helps to insert a certain header from another file.
#undef: It undefines a certain preprocessor macro.
#ifdef: It returns true if a certain macro is defined.
#ifndef: It returns true if a certain macro is not defined.
#if, #elif, #else, and #endif: It tests the program using a certain condition; these directives can be nested too. 
#line: It handles the line numbers on the errors and warnings. It can be used to change the line number and source files while generating output during compile time.
#error and #warning: It can be used for generating errors and warnings.
#error can be performed to stop compilation.
#warning is performed to continue compilation with messages in the console window.
#region and #endregion: To define the sections of the code to make them more understandable and readable, we can use the region using expansion and collapse features.
```

\\ macro-expansion ['./macro-expansion.c']
\\ edge cases in loops ['./loop-extras.c']
\\ integer value swap without using third (temp) variable ['./integer-value-swap-without-third-variable.c']
\\ calculator program ['./calculator.c']

* SEPT 23, 2022 ---------------------------------> JM

\\ basic logic gates : [[https://www.geeksforgeeks.org/logic-gates-definition-types-uses/]]
\\ universal  gates : [[https://www.electronics-tutorials.ws/logic/universal-gates.html]]

* OCT 12, 2022 ---------------------------------> PM

\\ file access / manipulation ['./file_access.c']
\\ command line arguments [argc & argv] ['./command_line_arguments.c']

* OCT 14, 2022 ---------------------------------> JM

\\ combinational logic circuit (Half & Full Adder) [[computer_system_architecture - 3ed - morris_mano ~ pg 20]]

* OCT 21, 2022 ---------------------------------> JM

\\ Multiplexer [ definition | 4x1 MUX | 8x1 MUX using 2 4x1 MUX ]
\\ DeMux [ definition | 1x4 DeMux | 1x8 DeMux using 2 1x4 DeMux ]

* NOV 03, 2022 ---------------------------------> PM

\\ Array [ Definition | Declaration + Initialization | Initialisation of values using loops & scanf() ] ['./array.c']

[IMPORTANT TOPICS FOR EXAM]:
    > Datatypes [1 Question]
    > Storage Classes
    > {Bitwise , Conditional/Ternary , Sizeof} operator
    > goto statement
    > defference in all loops
    > difference between if-else & switch (advantages & disadvantages)
    > nested if-else
    > break & continue
    > function prototype {declaration, Overloading}
 ## > call by value & call by reference
 
* NOV 04, 2022 ---------------------------------> JM

\\ Encoder [ definition | block diagram | truth table | logic circuit  | Decimal to binary | Octal to binary ]
\\ Decoder [ definition | block diagram | truth table | logic circuit  | 2-to-4 decoder | 3-to-8 decoder using 2 2-to-4 encoder ]
   [[https://dducollegedu.ac.in/Datafiles/cms/ecourse%20content/Chapter-2.pdf]]
|EXTRA| {BCD CODE -> (259)_(10) => (0010 0101 1001)_(BCD)}


* NOV 07, 2022 ---------------------------------> PM

\\ String functions : strcpy(), strcat(), strcmp(), gets(), puts(), fgets(), fputs()
\\ file access using commandline arguments [argc & argv] ['./file_access_2.c']


* NOV 12, 2022 ---------------------------------> JM

\\ Number System && Base Conversion [ Integer && Float ] : Binary > Decimal > Octal > Hexadecimal
   [[https://www.geeksforgeeks.org/number-system-and-base-conversions/]]
\\ Binary Addition
\\ Binary Subtraction

* NOV 12, 2022 ---------------------------------> PM

\\ Intro to C++
\\ Concept of Object-Oriented-Programming : [ Abstraction | Encapsulation | Inheritence | Polymorphism | Class | Object ]
   [[https://www.geeksforgeeks.org/object-oriented-programming-in-cpp/]]

* NOV 16, 2022 ---------------------------------> PM

\\ Printing factorial using class in c++
\\ Printing the area of square/rectangle/circle using class & function overloading

* NOV 17, 2022 ---------------------------------> JM

\\ Binary Multiplication, Division
\\ 1's Complement, 2,s Complement
\\ Subtraction using  1's Complement & 2,s Complement.

[H/W : WAP to get 1's complement of any binary string in C++]


* NOV 24, 2022 ---------------------------------> PM

\\ Karnaugh-map
\\ SOP [MINTERMS]
\\ K-Map using (2, 3, 4) variables
   [[https://www.geeksforgeeks.org/introduction-to-k-map-karnaugh-map]]

* NOV 25, 2022 ---------------------------------> PM

\\ Constructor [ default & parameterised | syntax | use-cases ]
\\ inheritance [ syntax | types of inheritance | use-cases ]
\\ Deconstructor in C++ [ use-cases | syntax ]

* NOV 25, 2022 ---------------------------------> JM

\\ class test on NUMBER SYSTER [26/40]

* NOV 28, 2022 ---------------------------------> PM

\\ practical_inmplementation [ ./inheritance.cpp | ./"1's_complement.cpp" ]

* NOV 30, 2022 ---------------------------------> PM

\\ Implementation of SOP function using multiplexer
    [[https://www.geeksforgeeks.org/implementation-of-sop-function-using-multiplexer/]]
\\ Sequential Logic Circuit
    [[https://www.geeksforgeeks.org/introduction-of-sequential-circuits/]]
\\ Flip-flops
    [[https://www.geeksforgeeks.org/flip-flop-types-their-conversion-and-applications/]]
\\ Conversion between multiple flip-flops (with Excitation Table)
    [[computer_system_architecture - 3ed - morris_mano ~ pg 29]]
    [[https://www.geeksforgeeks.org/conversion-of-s-r-flip-flop-into-t-flip-flop/]]
    [[https://www.geeksforgeeks.org/conversion-of-s-r-flip-flop-into-d-flip-flop/]]
    [[https://www.geeksforgeeks.org/conversion-of-j-k-flip-flop-into-t-flip-flop/]]
    [[https://www.geeksforgeeks.org/conversion-of-j-k-flip-flop-into-d-flip-flop/]]

* DEC 07, 2022 ---------------------------------> PM

\\ Operator Overloading [ unary && binary ]
   [[https://www.geeksforgeeks.org/operator-overloading-c/?ref=lbp]]
   [[https://www.geeksforgeeks.org/types-of-operator-overloading-in-c/]]
\\ Friend functions
   [[https://www.tutorialspoint.com/cplusplus/cpp_friend_functions.htm]]
\\ Programs :: Printing Armstrong numbers
   [[./armstrong_number.cpp]]


* DEC 08, 2022 ---------------------------------> PM

\\ Counter 
    [[https://youtube.com/playlist?list=PLuYnCh-Sh1Xd5cLa-CfK883tPmJwrjSwF]]
    [[https://www.cukashmir.ac.in/cukashmir/User_Files/imagefile/DIT/StudyMaterial/LogicDesign/DigitalLogic_Counters.pdf]]
\\ MOD-3 
    [[https://maxwell.ict.griffith.edu.au/yg/teaching/dns/ds_module3_p1.pdf]]
