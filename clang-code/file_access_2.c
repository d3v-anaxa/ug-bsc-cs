#include <stdio.h>
#include <ctype.h>
#include <unistd.h>

void copyToAnotherFile(char fin[], char fout[])
{
  FILE *fl1, *fl2;
  char ch;
  fl1 = fopen(fin, "r");
  fl2 = fopen(fout, "w");
  printf("Input File contents:\n\n");
  while ((ch = fgetc(fl1)) != EOF)
  {
    printf("%c", ch);
    fputc(ch, fl2);
  }
  fclose(fl1);
  fclose(fl2);
  printf("\nFile copied successfully\n");
}

int main(int argc, char **argv)
{
    switch (argc) {
    case 1:
        printf("Specify Input and output file\n");
        return 1;
    case 2:
       printf("Specify output file\n");
       return 1;
    case 3:
       {
            if (access(argv[1],F_OK) != 0) {
                printf("\"%s\" file doesn't exist\n", argv[1]);
                return 1;
            }
            copyToAnotherFile(argv[1], argv[2]);
            return 0;
       }
     default:
       printf("Too many arguments!!\n");
       return 1;
    }
}
