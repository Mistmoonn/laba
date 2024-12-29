#include <stdio.h>
#include <stdlib.h>
#include "head.h"


Deque* createDeque() {
    Deque* deque = (Deque*)malloc(sizeof(Deque));
    deque->front = NULL;
    deque->rear = NULL;
    return deque;
}

void insertRear(Deque* deque, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = value;
    newNode->next = NULL;
    newNode->prev = deque->rear;
    if (deque->rear != NULL) {
        deque->rear->next = newNode;
    }
    deque->rear = newNode;
    if (deque->front == NULL) {
        deque->front = newNode;
    }
}

void freeDeque(Deque* deque) {
    Node* current = deque->front;
    while (current != NULL) {
        Node* temp = current;
        current = current->next;
        free(temp);
    }
    free(deque);
}


void bubbleSort(int* arr, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}


void writeToFile(const char* filename, int* arr, int n) {
    FILE* file = fopen(filename, "w");
    if (file == NULL) {
        printf("mistake while openning a file");
    }
    for (int i = 0; i < n; i++) {
        fprintf(file, "%d ", arr[i]);
    }
    fclose(file);
}
