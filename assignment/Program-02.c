// Print reverse number
#include <stdio.h>

void printRev (char* str);

int main(void){
    char *str ;
    printf("Enter a number [ to reverse it ] : ");
    scanf("%s", str);
    if (str[0] == '-') printf("-");
    printRev(str);
    printf("\n");
    return 0;
}

void printRev (char* str){
    if (*str == '\0') return;
    printRev(str+1);
    if ( *str != '-')
    printf("%c", *str);
}
