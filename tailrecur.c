#include <stdio.h>

int factTR(int n, int a) {
    if(n == 0)
        return a;
    return factTR(n - 1, n * a);
}

int fact(int n) {
    return factTR(n, 1);
}

void main() {
    int n;
    printf("Enter number: ");
    scanf("%d", &n);
    printf("Factorial = %d\n", fact(n));
}
