// print triangle
#include<stdio.h>
int main(void){
    int height = 0;
    printf("Enter the height [1 - 50]: ");
    scanf("%i", &height);
    if(height < 1 || height > 50){
        printf("Invalid Range\n");
        return 1;
    }
    int width = height;
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            printf("  ");
        }
        for(int j = 0; j < height -  width + 1; j++){
            printf(" *");
        }
        for(int j = 0; j < i; j++){
            printf(" *");
        }
        printf("\n");
        width--;
    }

}
