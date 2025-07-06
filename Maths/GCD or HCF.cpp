#include <bits/stdc++.h>
using namespace std;

//
// ==================================================
// Brute Force Method
// ==================================================
//
// Intuition:
// Try every number from min(a, b) down to 1.
// Return the first number that divides both.
//
// Time: O(min(a, b))
// Space: O(1)
//
// Dry Run (a = 24, b = 36):
// Try i = 24 ↓ to 1 → First i that divides both is 12
//
int gcd_brute(int a, int b) {
    for (int i = min(a, b); i >= 1; i--) {
        if (a % i == 0 && b % i == 0)
            return i;
    }
    return 1;
}

//
// ==================================================
// Euclidean Algorithm – Subtraction
// ==================================================
//
// Intuition:
// Keep subtracting smaller from larger until both are equal.
// GCD(a, b) = GCD(a - b, b) until a == b
//
// Time: O(max(a, b))
// Space: O(1)
//
// Dry Run (a = 24, b = 36):
// Step 1: b = 36 - 24 = 12
// Step 2: a = 24 - 12 = 12
// Now: a == b == 12 → return 12
//
int gcd_sub(int a, int b) {
    while (a != b) {
        if (a > b)
            a = a - b;
        else
            b = b - a;
    }
    return a;
}

//
// ==================================================
// Euclidean Algorithm – Division (Iterative)
// ==================================================
//
// Intuition:
// Use GCD(a, b) = GCD(b, a % b).
// Keep replacing until b becomes 0.
//
// Time: O(log(min(a, b)))
// Space: O(1)
//
// Dry Run (a = 24, b = 36):
// gcd(24, 36)
// → gcd(36, 24)
// → gcd(24, 12)
// → gcd(12, 0) → return 12
//
int gcd_div(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

//
// ==================================================
// Euclidean Algorithm – Recursion
// ==================================================
//
// Intuition:
// Same as division method, implemented recursively.
//
// Time: O(log(min(a, b)))
// Space: O(log(min(a, b))) → due to recursive call stack
//
// Dry Run (a = 24, b = 36):
// gcd(24, 36) → gcd(36, 24) → gcd(24, 12) → gcd(12, 0)
// → return 12
//
int gcd_recursive(int a, int b) {
    if (b == 0)
        return a;
    return gcd_recursive(b, a % b);
}

//
// ==================================================
// Main Function: Test All
// ==================================================
//
int main() {
    int a, b;
    // cout << "Enter two numbers: ";
    cin >> a >> b;

    cout << "\nBrute Force GCD: " << gcd_brute(a, b) << endl;
    cout << "Euclidean (Subtraction): " << gcd_sub(a, b) << endl;
    cout << "Euclidean (Division): " << gcd_div(a, b) << endl;
    cout << "Euclidean (Recursive): " << gcd_recursive(a, b) << endl;

    return 0;
}
