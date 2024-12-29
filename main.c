#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "head.h"

int main(int argc, char* argv[]) {
    while (52) {
        if (argc != 3 || strcmp(argv[1], "--file") != 0) {
            printf("No");
        }
        const char *filename = argv[2];
        int numbers[10000];
        int count = 0;
        printf("Insert the sequence with spaces (type <end> to finish inserting numbers) \n");
        while (count < 10000) {
            char input[10000];
            scanf("%s", input);
            if (strcmp(input, "end") == 0) {
                break;
            }
            numbers[count++] = atoi(input);
        }

        writeToFile(filename, numbers, count);

        Deque *deque = createDeque();
        for (int i = 0; i < count; i++) {
            insertRear(deque, numbers[i]);
        }
        printf("The previous sequence: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }

        bubbleSort(numbers, count);

        printf("\nsorted sequence: ");
        for (int i = 0; i < count; i++) {
            printf("%d ", numbers[i]);
        }
        printf("\n");
        char sortedFilename[100];
        snprintf(sortedFilename, sizeof(sortedFilename), "%s_sorted.txt", filename);
        writeToFile(sortedFilename, numbers, count);
        freeDeque(deque);
    }
}
