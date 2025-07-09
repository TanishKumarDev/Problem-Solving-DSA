#include <bits/stdc++.h>
using namespace std;

// Problem Statement
// Print numbers from N to 1 using recursion.
// Example: If n=5, output should be:
// 5
// 4
// 3
// 2
// 1

// Intuition
// We need to print numbers from N to 1 using recursion. The idea is to use a recursive function that prints the current number and calls itself with the next lower number until it reaches 1.

// Algorithm
// 1. Define a recursive function that takes one parameter: the current number.
// 2. The function will print the current number and call itself with the next lower number.
// 3. Base Case: If the current number is 0, we stop the recursion.
// 4. Print the current number.
// 5. Make a recursive call to print the next lower number.

// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space

void printName(int n) {
    // Base condition
    if(n == 0)
    return;
    // Print the current value
    cout << n << endl;
    // Recursive call
    printName(n-1);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    printName(n);

    return 0;
}
