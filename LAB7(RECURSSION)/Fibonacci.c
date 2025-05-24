#include <stdio.h>
#include <conio.h>
// Function to return the nth Fibonacci number
int fibonacci(int n) {
    if (n <= 1)
        return n;
    else
        return fibonacci(n - 1) + fibonacci(n - 2);
}

int main() {
    int n;
    printf(" Enter Number to find Fibonacci series: ");
    scanf("%d", &n);

    if (n < 0) {
        printf(" Invalid input! Please enter a non-negative integer.\n");
    } else {
        int result = fibonacci(n);
        printf(" The %dth term of the Fibonacci series is: %d\n", n, result);
    }

    return 0;
}

