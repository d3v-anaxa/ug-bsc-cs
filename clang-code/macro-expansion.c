#include <stdio.h>
#include <stdlib.h>

#define PI 3.14159
#define AREA_OF_SQUARE (s * s)
#define AREA_OF_CIRCLE (PI * r * r)
#define AREA_OF_RECTANGLE (l * b)

void menu()
{
  printf("+---------------------------------------------------------------->\n");
  printf("| 1. AREA_OF_SQUARE\n");
  printf("| 2. AREA_OF_CIRCLE\n");
  printf("| 3. AREA_OF_RECTANGLE\n");
  printf("| 4. EXIT\n");
  printf("+---------------------------------------------------------------->\n");
}

void main()
{
  float l = 0, b = 0, r = 0, s = 0;
  int choice;

  menu();
  printf("Enter choice: ");
  scanf("%d", &choice);
  switch (choice)
  {
  case 1:
    printf("Enter the length of each side of the square: ");
    scanf("%f", &s);
    printf("AREA_OF_SQUARE -> %f\n", AREA_OF_SQUARE);
    break;
  case 2:
    printf("Enter the radius : ");
    scanf("%f", &r);
    printf("AREA_OF_CIRCLE -> %f\n", AREA_OF_CIRCLE);
    break;
  case 3:
    printf("Enter the length: ");
    scanf("%f", &l);
    printf("Enter the breath: ");
    scanf("%f", &b);
    printf("AREA_OF_RECTANGLE -> %f\n", AREA_OF_RECTANGLE);
    break;
  case 4:
    printf("[PROGRAM EXITED]\n");
    exit(EXIT_SUCCESS);
    break;
  default:
    printf("INVALID INPUT\n");
    main();
    break;
  }
  main();
}