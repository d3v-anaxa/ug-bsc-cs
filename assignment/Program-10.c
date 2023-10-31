// Performing diff. functions in the array
#include <stdio.h>
#include <stdlib.h>
#define range(x, y) for(int i = x; i < y; i++)

static int size = 0;

void printEven(int array[]){
    printf("Even values : ");
    range(0, size){
        if (! (array[i]%2) )
        printf(" %d", array[i]);
    }
    printf("\n");
}

void printOdd(int array[]){
    printf("Odd values : ");
    range(0, size){
        if (array[i]%2)
        printf(" %d", array[i]);
    }
    printf("\n");
}

void printSumAndAvg(int array[]){
    int sum = 0;
    range(0, size){
        sum += array[i];
    }
    printf("Sum : %d, ", sum);
    printf("Average : %.2f\n",(double) sum / size);
}

void printMaxAndMin(int array[]){
    int max = (1 << 31);
    int min = (1 << 30) + ((1 << 30) - 1);
    range(0, size){
        if(array[i] > max){max = array[i];}
        if(array[i] < min){min = array[i];}
    }
    printf("Maximum : %d, ", max);
    printf("Minimum : %d\n", min);
}

void printReverseArray(int array[]){
    printf("Reverse Array : ");
    range(0, size)
    printf(" %d", array[size - i - 1]);
    printf("\n");
}

void arrayEntry(int array[]){
    size = 0;
    printf("Enter size of array [n>0] : ");
    scanf("%d", &size);
    range(0, size){
      printf("Enter element : %d : ", i+1);
      scanf("%d", &array[i]);
    }
}

void menu(){
    printf("\n");
    printf("1 -> Print Even Values\n");
    printf("2 -> Print Odd Values\n");
    printf("3 -> Print Sum and Average\n");
    printf("4 -> Print Maximim and Minimum value\n");
    printf("5 -> Print array elements in reverse order\n");
    printf("6 -> Re-enter array elements\n");
    printf("7 -> Exit\n");
    printf("Enter choice [1-7] : ");
}

int main(void){
   int array[100];
   int choice = 0;
   arrayEntry(array);
   while(1){
       menu();
       scanf("%d", &choice);
       printf("\n");
       switch (choice){
           case 1:
               printEven(array);
               break;
           case 2:
               printOdd(array);
               break;
           case 3:
               printSumAndAvg(array);
               break;
           case 4:
               printMaxAndMin(array);
               break;
           case 5:
               printReverseArray(array);
               break;
           case 6:
               arrayEntry(array);
               break;
           default:
               printf("Program Exited Successfully!!\n");
               exit(0);
       }
   }
}
