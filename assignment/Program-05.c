// check for palindrome
#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool chechPalindrome(char*, unsigned int);

int main(void){
    char *buffer = {};
    size_t buf = 64, len = 0;
    printf("Enter string : ");
    len = getline(&buffer, &buf, stdin);
    printf(chechPalindrome(buffer, len) ? "Is palindrome" : "Is not a palindrome");
    printf("\n");
    return 0;
}

bool chechPalindrome(char* str, unsigned int length){
   int start = 0, 
       end = length - 2;
   while (start < end){
       while (str[start] == ' ') start++;
       while (str[end] == ' ') end--;
       if (str[start] != str[end]) return false;
       else{
           start++;
           end--;
       }
   }
   return true;
}
