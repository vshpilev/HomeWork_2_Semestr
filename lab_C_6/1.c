#include <stdio.h>

int main() {
char arr[100]; // символьный массив, максимальный размер 100
char c; // символ, который будем искать
int max_len = 0, len = 0; // максимальная длина последовательности и текущая длина последовательности
printf("Enter a character to search: ");
scanf("%c", &c);
printf("Enter character array: ");
scanf("%s", arr);
for (int i = 0; arr[i] != '\0'; i++) {
if (arr[i] == c) {
len++; // увеличиваем длину последовательности, если символ совпадает
} else {
if (len > max_len) {
max_len = len; // обновляем максимальную длину последовательности, если текущая больше
}
len = 0; // сбрасываем текущую длину последовательности
}
}
if (len > max_len) {
max_len = len; // проверяем длину последовательности в конце, если она больше максимальной
}
printf("Maximum length of a continuous character sequence %c: %d\n", c, max_len);
return 0;
}