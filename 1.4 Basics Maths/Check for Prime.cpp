#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- Prime has exactly two distinct divisors: 1 and itself
- Only need to check divisors up to sqrt(n)
*/

// Approach 1: Brute Force (Full scan)
// Time: O(n)
// Space: O(1)
bool isPrimeBrute(int n) {
    if (n <= 1) return false;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Approach 2: Better (Check up to n/2)
// Time: O(n/2) = O(n)
// Space: O(1)
bool isPrimeBetter(int n) {
    if (n <= 1) return false;
    for (int i = 2; i <= n/2; i++) {
        if (n % i == 0) return false;
    }
    return true;
}

// Approach 3: Optimal (Check up to sqrt(n))
// Time: O(sqrt(n))
// Space: O(1)
bool isPrimeOptimal(int n) {
    if (n <= 1) return false;
    if (n == 2) return true;
    if (n % 2 == 0) return false;
    for (int i = 3; i <= sqrt(n); i += 2) {
        if (n % i == 0) return false;
    }
    return true;
}

int main() {
    int num;
    cin >> num; // Input a number

    cout << "Brute: " << (isPrimeBrute(num) ? "Yes" : "No") << endl;
    cout << "Better: " << (isPrimeBetter(num) ? "Yes" : "No") << endl;
    cout << "Optimal: " << (isPrimeOptimal(num) ? "Yes" : "No") << endl;
    return 0;
}