#include <stdio.h>
#include <stdbool.h>
#include <string.h>

void print_array(char arr[][50], int size) {
for (int i = 0; i < size; i++) {
printf("%s ", arr[i]);
}
printf("\n");
}

void selection_sort(char arr[][50], int size, int* iterations) {
for (int i = 0; i < size-1; i++) {
int min = i;
for (int j = i+1; j < size; j++) {
if (strcmp(arr[j], arr[min]) < 0) {
min = j;
}
(*iterations)++;
}
if (min != i) {
char temp[50];
strcpy(temp, arr[i]);
strcpy(arr[i], arr[min]);
strcpy(arr[min], temp);
}
}
}

void bubble_sort(char arr[][50], int size, int* iterations) {
for (int i = 0; i < size-1; i++) {
bool swapped = false;
for (int j = 0; j < size-i-1; j++) {
if (strcmp(arr[j], arr[j+1]) > 0) {
char temp[50];
strcpy(temp, arr[j]);
strcpy(arr[j], arr[j+1]);
strcpy(arr[j+1], temp);
swapped = true;
}
(*iterations)++;
}
if (!swapped) {
break;
}
}
}

void comb_sort(char arr[][50], int size, int* iterations) {
int gap = size;
float shrink = 1.3;
bool swapped = false;
while (gap > 1 || swapped) {
gap = (int) (gap / shrink);
if (gap < 1) {
gap = 1;
}
int i = 0;
swapped = false;
while (i+gap < size) {
if (strcmp(arr[i], arr[i+gap]) > 0) {
char temp[50];
strcpy(temp, arr[i]);
strcpy(arr[i], arr[i+gap]);
strcpy(arr[i+gap], temp);
swapped = true;
}
i++;
(*iterations)++;
}
}
}

int main() {
char words[10][50];
printf("Enter 10 words:\n");
for (int i = 0; i < 10; i++) {
scanf("%s", words[i]);
}
printf("Original array: ");
print_array(words, 10);
int iterations = 0;
int choice;
printf("Choose an algorithm:\n1. Selection sort\n2. Bubble sort\n3. Comb sort\n4. All three\n");
scanf("%d", &choice);
switch (choice) {
case 1:
selection_sort(words, 10, &iterations);
printf("Sorted array: ");
print_array(words, 10);
printf("Iterations: %d\n", iterations);
break;
case 2:
bubble_sort(words, 10, &iterations);
printf("Sorted array: ");
print_array(words, 10);
printf("Iterations: %d\n", iterations);
break;
case 3:
comb_sort(words, 10, &iterations);
printf("Sorted array: ");
print_array(words, 10);
printf("Iterations: %d\n", iterations);
break;
case 4:
selection_sort(words, 10, &iterations);
printf("Selection sort iterations: %d\n", iterations);
iterations = 0;
bubble_sort(words, 10, &iterations);
printf("Bubble sort iterations: %d\n", iterations);
iterations = 0;
comb_sort(words, 10, &iterations);
printf("Comb sort iterations: %d\n", iterations);
printf("Sorted array:\n");
print_array(words, 10);
break;
default:
printf("Invalid choice\n");
}
return 0;
}