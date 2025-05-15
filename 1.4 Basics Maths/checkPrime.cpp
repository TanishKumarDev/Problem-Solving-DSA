#include <bits/stdc++.h>
using namespace std;

bool isPrime_brute(int n) {
    if (n <= 1) return false; // Numbers less than or equal to 1 are not prime

    int cnt = 0;
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) // If 'i' divides 'n' without remainder
            cnt++;
    }
    return cnt == 2; // If there are exactly two divisors (1 and n), the number is prime
}

bool checkPrime_better(int n) {
    int cnt = 0;  // Counter to count divisors.

    // Loop from 1 to sqrt(n)
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cnt++;  // Increment count for divisor i
            if (n / i != i) {
                cnt++;  // If n/i is not equal to i, increment for the reciprocal divisor
            }
        }
    }

    // If there are exactly 2 divisors, return true (prime)
    return (cnt == 2);
}

int main() {
    int n;
    cin >> n; // Input the number

    // Test brute force method
    if (isPrime_brute(n)) {
        cout << n << " is a prime number (Brute Force)." << endl;
    } else {
        cout << n << " is not a prime number (Brute Force)." << endl;
    }

    // Test optimized method
    if (checkPrime_better(n)) {
        cout << n << " is a prime number (Optimized)." << endl;
    } else {
        cout << n << " is not a prime number (Optimized)." << endl;
    }

    return 0;
}
