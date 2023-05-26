// Given a number n, print n-th Fibonacci Number using Dynamic Programming.
#include <iostream>
using namespace std;

int fibonacci(int n) {
    if (n <= 1) {
        return n;
    }
    
    int fib[n+1];
    fib[0] = 0;
    fib[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    return fib[n];
}

int main() {
    int n;
    cout << "Enter the value of n: ";
    cin >> n;
    
    int fibNumber = fibonacci(n);
    
    cout << "The " << n << "-th Fibonacci number is: " << fibNumber << endl;
    
    return 0;
}
