#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NROWS 100
#define NCOLS 24

unsigned long hash(char *str) {
unsigned long hash = 5381;
int c;
while ((c = *str++))
hash = ((hash << 5) + hash) + c;
return hash;
}

int compare(char **a, char **b) {
return strcmp(*a, *b);
}

int main() {
char matrix[NROWS][NCOLS];
int n = 0;

// Read input
while (fgets(matrix[n], NCOLS, stdin)) {
// Remove new line character
matrix[n][strcspn(matrix[n], "\n")] = '\0';
n++;
if (n >= NROWS)
break;
}

// Sort matrix
qsort(matrix, n, NCOLS * sizeof(char), (int (*)(const void *, const void *)) compare);

// Remove duplicates
for (int i = 0; i < n;) {
unsigned long hash1 = hash(matrix[i]);
int j = i + 1;
while (j < n && hash(matrix[j]) == hash1) {
if (strcmp(matrix[j], matrix[i]) != 0)
printf("Error: hash collision!\n");
j++;
}
// Print unique row
printf("%s\n", matrix[i]);
i = j;
}

return 0;
}