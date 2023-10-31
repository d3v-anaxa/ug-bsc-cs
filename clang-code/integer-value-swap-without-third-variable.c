#include <stdio.h>
#include <stdlib.h>

void main()
{
  int n1 = 0, n2 = 0;
  printf("Enter the 1st integer : ");
  scanf("%d", &n1);
  printf("Enter the 2nd integer : ");
  scanf("%d", &n2);
  printf("[BEFORE SWAP]\t : ");
  printf("n1 -> %d\tn2 -> %d\n", n1, n2);

  n1 = n1 + n2;
  n2 = n1 - n2;
  n1 = n1 - n2;

  printf("[AFTER SWAP]\t : ");
  printf("n1 -> %d\tn2 -> %d\n", n1, n2);
}