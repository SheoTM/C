#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    int rows, cols;

    printf("Row: ");
    if (scanf("%d", &rows) != 1 || rows <= 0) {
        printf("Row must be over 0\n");
        return 1;
    }

    printf("Column: ");
    if (scanf("%d", &cols) != 1 || cols <= 0) {
        printf("Column must be over 0\n");
        return 1;
    }

    int *matrix = malloc(rows * cols * sizeof(int));
    if (matrix == NULL) {
        printf("Memory allocation error\n");
        return 1;
    }

    srand(time(NULL));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            matrix[i * cols + j] = rand() % 100;
        }
    }

    printf("\nMatrix: %dx%d:\n", rows, cols);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%3d ", matrix[i * cols + j]);
        }
        printf("\n");
    }

    free(matrix);
    return 0;
}