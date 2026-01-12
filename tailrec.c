#include <stdio.h>

void print(int n) {
    if(n < 0)
        return;
    printf("%d ", n);
    print(n - 1);  // Last statement - Tail Recursive
}

void main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    print(n);
}