#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    printf("Enter the number of rows\n");
    scanf("%d", &n);
    long int *factorial = malloc((n + 1) * sizeof(long));

    factorial[0] = 1;
    for (int i = 1; i <= n; i++) {
        factorial[i] = factorial[i - 1] * i;
    }

    for (int i = 0; i < n; i++) {
        for (int c = 0; c < (n - i - 1); c++) {
            printf(" ");
        }
        for (int c = 0; c <= i; c++) {
            long int coeff = factorial[i] / (factorial[c] * factorial[i - c]);
            printf("%ld ", coeff);
        }
        printf("\n");
    }

    free(factorial);
    return 0;
}
