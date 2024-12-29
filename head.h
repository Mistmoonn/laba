#ifndef DEQUE_H
#define DEQUE_H

typedef struct Node {
    int data;
    struct Node* next;
    struct Node* prev;
} Node;

typedef struct Deque {
    Node* front;
    Node* rear;
} Deque;

Deque* createDeque();
void insertRear(Deque* deque, int value);
void freeDeque(Deque* deque);
void bubbleSort(int* arr, int n);
void writeToFile(const char* filename, int* arr, int n);

#endif // DEQUE_H
