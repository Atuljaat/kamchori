#include <stdio.h>

int main() {
    printf("Prerit || BCA-2A");
    int size, location, i;

    scanf("%d", &size);

    int array[size];

    for (i = 0; i < size; i++) {
        scanf("%d", &array[i]);
    }

    scanf("%d", &location);

    if (location >= size+1) {
        printf("Invalid location.\n");
    } else {
        for (i = location - 1; i < size - 1; i++) {
            array[i] = array[i + 1];
        }

        size--;

        for (i = 0; i < size; i++) {
            printf("%d ", array[i]);
        }
        printf("\n");
    }

    return 0;
}