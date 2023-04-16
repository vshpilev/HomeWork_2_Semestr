#include <stdio.h>

void print(int numArr[], int size);
void insert(int numArr[], int size, int numInput);
void append(int numArr[], int size, int numInput);

int main() {

    int size;
    int elem;
    int numInput;
    int numFun;

    printf("Enter the size of the array: \n");
    scanf("%d", &size);
    
    printf("Enter the number of elements: \n");
    scanf("%d", &elem);

    if (elem > size) {
        printf("Error! The number of elements exceeds the size of the array. \n");
        return 0;
    }
    
    int numArr[size];

    int k;

    for (k = 0; k < size; k++) {
        if (k < elem) {
            numArr[k] = k;
        } else if (k >= elem) {
            numArr[k] = 0;
        }
    }   

    print(numArr, size);
        
    printf("Enter the number you want to add to the array: \n");
    scanf("%d", &numInput);
        
    printf("Enter the number of the operation you want to perform: \n1. insert\n2. append\n");
    scanf("%d", &numFun);
    if (numFun == 1) {
        insert(numArr, size, numInput);
    } else if (numFun == 2) {
        append(numArr, size, numInput);
    }

    return 0;
}

void print(int numArr[], int size) {
    int j;

    printf("{");
    for (j = 0; j < size; j++) {
        if (j == size - 1) {
            printf("%d}\n", numArr[j]);
            break;
        }
        printf("%d, ", numArr[j]);
    }
}

void insert(int numArr[], int size, int numInput) {
    numArr[size/2] = numInput;
    print(numArr, size);
}
    
void append(int numArr[], int size, int numInput) {
    numArr[size - 1] = numInput;
    print(numArr, size);
}