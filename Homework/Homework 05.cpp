#include <stdio.h> 
int main(void) {
char message[1024];
int vowel_count = 0;
printf("Input message here:");
if (fgets(message, sizeof(message), stdin) == NULL)
{return 1;}

for (int i = 0; message[i] != '\0'; i++)
{ char c = message[i]; 
if (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U' ||
c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u') 
{ vowel_count++;}
}

printf("Number of vowels: %d\n", vowel_count);
return 0;
}