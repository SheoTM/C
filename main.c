#include <stdio.h>
#include "ex1.h"
#include "ex2.h"
#include "ex3.h"

int main() {
    int choice;
    printf("1. ex1\n");
    printf("2. ex2\n");
    printf("3. ex3\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1: run_ex1(); break;
        case 2: run_ex2(); break;
        case 3: run_ex3(); break;
        default: printf("Invalid choice\n");
    }

    return 0;
}
