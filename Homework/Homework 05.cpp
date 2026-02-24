#include <stdio.h> 
int main(void) {
char message[1024];
int vowel_count = 0;
printf("Input message here");
if (fgets(message, sizeof(message), stdin) == NULL)
{return 1;}
}