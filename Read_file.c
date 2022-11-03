#include<stdio.h>
#include<stdlib.h>

int main(){
char ch;
int num;
FILE *f_in, *f_out;

f_in = fopen("parsing.asm", "r");

if (!f_in)
{
  perror("Error opening the input file");
  return -1;
}

f_out = fopen("parsing_b", "wb");
if (!f_out)
{
 perror("Error opening the output file");
  return -1;
}


do
{
  ch = fgetc(f_in);
  num = ch;
  fwrite(&num, sizeof(int), 1, f_out);
} while (ch!=EOF);

fclose(f_in);
fclose(f_out);
return 0;

}