#include <stdio.h>
#include <stdlib.h>
#define SIZE 12

int hash[SIZE] = {0};


void insertLinear(int data) {
    int index = data % SIZE;
    int i = 0;
    while (hash[(index + i) % SIZE] != 0) {
        i++;
    }
    hash[(index + i) % SIZE] = data;
}


int searchLinear(int data) {
    int index = data % SIZE;
    int i = 0;
    while (hash[(index + i) % SIZE] != data) {
        if (hash[(index + i) % SIZE] == 0) {
            return -1;
        }
        i++;
    }
    return (index + i) % SIZE;
}


void insertQuadratic(int data) {
    int index = data % SIZE;
    int i = 0,j=0;
    while (hash[(index + i * i) % SIZE] != 0) {
        i++;
    }
    hash[(index + i * i) % SIZE] = data;
}

int searchQuadratic(int data) {
    int index = data % SIZE;
    int i = 0;
    while (hash[(index + i * i) % SIZE] != data) {
        if (hash[(index + i * i) % SIZE] == 0) {
            return -1;
        }
        i++;
    }
    return (index + i * i) % SIZE;
}

void display() {
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("%d ", hash[i]);
    }
    printf("\n");
}

int main() {
    int choice, data, index;
    printf("1. Insert using Linear Probing\n");
    printf("2. Search using Linear Probing\n");
    printf("3. Insert using Quadratic Probing\n");
    printf("4. Search using Quadratic Probing\n");
    printf("5. Display Hash Table\n");
    printf("6. Exit\n");
    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertLinear(data);
                break;
            case 2:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                index = searchLinear(data);
                if (index == -1) {
                    printf("Data not found\n");
                } else {
                    printf("Data found at index %d\n", index);
                }
                break;
            case 3:
                printf("Enter the data to insert: ");
                scanf("%d", &data);
                insertQuadratic(data);
                break;
            case 4:
                printf("Enter the data to search: ");
                scanf("%d", &data);
                index = searchQuadratic(data);
                if (index == -1) {
                    printf("Data not found\n");
                } else {
                    printf("Data found at index %d\n", index);
                }
                break;
            case 5:
                display();
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice\n");
        }
    }
    return 0;
}
