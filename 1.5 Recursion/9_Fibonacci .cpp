#include <bits/stdc++.h>
using namespace std;

// Recursion for Nth Fibonacci term
int fibonacciRecursive(int n) {
    if (n <= 1) return n;
    return fibonacciRecursive(n - 1) + fibonacciRecursive(n - 2);
}

// Print Brute Force (DP Array) Version
void printFibonacciDP(int n) {
    vector<int> fib(n + 1);
    fib[0] = 0;
    if (n >= 1) fib[1] = 1;

    for (int i = 2; i <= n; i++)
        fib[i] = fib[i - 1] + fib[i - 2];

    cout << "\n🔹 Brute Force (DP Array):\n";
    for (int i = 0; i <= n; i++)
        cout << fib[i] << " ";
    cout << endl;
}

// Print Optimized Version (2 variables)
void printFibonacciOptimized(int n) {
    int a = 0, b = 1;
    cout << "\n🔹 Optimized (O(1) Space):\n";
    if (n >= 0) cout << a << " ";
    if (n >= 1) cout << b << " ";
    
    for (int i = 2; i <= n; i++) {
        int c = a + b;
        cout << c << " ";
        a = b;
        b = c;
    }
    cout << endl;
}

int main() {
    int n;
    // cout << "Enter the value of N (0-based index): ";
    cin >> n;

    // if (n < 0) {
    //     cout << "❌ Please enter a non-negative integer.\n";
    //     return 0;
    // }

    printFibonacciDP(n);
    printFibonacciOptimized(n);

    cout << "\n🔹 Recursive (Nth Fibonacci Only):\n";
    cout << "F(" << n << ") = " << fibonacciRecursive(n) << endl;

    return 0;
}
