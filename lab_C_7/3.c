#include <stdio.h>

int main() {
char word[50];
int vowels = 0, consonants = 0;
printf("Enter one word in Latin: ");
scanf("%s", word);
char *ptr = word;
while (*ptr != '\0') {
if (*ptr == 'a' || *ptr == 'e' || *ptr == 'i' || *ptr == 'o' || *ptr == 'u') {
vowels++;
} else {
consonants++;
}
ptr++;
}
printf("Number of vowels: %d\n", vowels);
printf("Number of consonants: %d\n", consonants);
return 0;
}

