#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "head.h"

int main(int argc, char* argv[]) {
    while (52) {
        if (argc != 3 || strcmp(argv[1], "--file") != 0) {
            printf("no");

        }

        const char *filename = argv[2];
        int numbers[100];
        int count = 0;

        printf("Insert the sequence with spaces (type <end> to finish inserting numbers) \n");

        while (count < 100) {
            char input[10];
            scanf("%s", input);

            if (strcmp(input, "end") == 0) {
                break;
            }

            numbers[count++] = atoi(input);
        }

        // Запись исходного ряда в файл
        writeToFile(filename, numbers, count);

        // Создание дека и добавление элементов
        Deque *deque = createDeque();
        for (int i = 0; i < count; i++) {
            insertRear(deque, numbers[i]);
        }

        // Сортировка
        bubbleSort(numbers, count);

        // Вывод исходного и отсортированного рядов
        printf("The previous sequence: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }

        printf("\nsorted sequence: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }

        printf("\n");

        // Запись отсортированного ряда в файл
        char sortedFilename[100];
        snprintf(sortedFilename, sizeof(sortedFilename), "%s_sorted.txt", filename);
        writeToFile(sortedFilename, numbers, count);

        // Освобождение памяти
        freeDeque(deque);

    }
}
