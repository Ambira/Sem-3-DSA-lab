#include <stdio.h>

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int factorial(int n)
{
    if (n == 0)
        return 1;
    return n * factorial(n - 1);
}
int fibonacci(int n)
{
    if (n <= 1)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int towerOfHanoi(int n, char from, char to, char aux)
{
    if (n == 1)
    {
        printf("Move disk 1 from %c to %c\n", from, to);
        return 0;
    }
    towerOfHanoi(n - 1, from, aux, to);
    printf("Move disk %d from %c to %c\n", n, from, to);
    towerOfHanoi(n - 1, aux, to, from);
    return 0;
}

int main()
{

    int choice;
    while (1)
    {
        printf("Recursion Menu:\n");
        printf("1. GCD\n");
        printf("2. Factorial\n");
        printf("3. Fibonacci number\n");
        printf("4. Tower of Hanoi\n");
        printf("5. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
        
            int a, b;
            printf("Enter two numbers: ");
            scanf("%d %d", &a, &b);
            printf("GCD of %d and %d is %d\n", a, b, gcd(a, b));
            break;
        
        case 2:
        
            int n;
            printf("Enter a number: ");
            scanf("%d", &n);
            printf("Factorial of %d is %d\n", n, factorial(n));
            break;
        
        case 3:
        
            int n;
            printf("Enter position (n): ");
            scanf("%d", &n);
            printf("Fibonacci number at position %d is %d\n", n, fibonacci(n));
            break;
        
        case 4:
        
            int n;
            printf("Enter number of disks: ");
            scanf("%d", &n);
            printf("Tower of Hanoi moves:\n");
            towerOfHanoi(n, 'A', 'C', 'B');
            break;
        
        case 5:
            printf("Exiting...\n");
            return 0;
        default:
            printf("Invalid choice! Try again.\n");
            break;
        
    }
}
