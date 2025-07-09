#include <bits/stdc++.h>
using namespace std;

// Problem Statement
// Print a name 'n' times using recursion.
// Example: If n=5, output should be:

// tanish
// tanish
// tanish
// tanish
// tanish

// Intuition 
// We need to print a name 'n' times using recursion. The idea is to use a recursive function that prints the name and calls itself until it has printed the name 'n' times.

// Algorithm
// 1. Define a recursive function that takes two parameters: the current count and the total count.
// 1. We will use a recursive function to print the name.
// 2. The function will take two parameters: the current count and the total count.
// 3. Base Case: If the current count exceeds the total count, we stop the recursion.
// 4. Print the name for the current count.
// 5. Make a recursive call to print the name for the next count.

// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space
void printNameNtimes(int i, int n) {
    // Base case: Stop when we've printed n times
    if (i > n) return;

    // Print current iteration
    cout << "tanish" << endl;
    
    // Recursive call for next iteration
    printNameNtimes(i + 1, n);
}

// 🎯 Driver Function
int main() {
    int n;
    // Uncomment for better UX
    // cout << "Enter number of times to print: ";
    cin >> n;

    // Start recursion from i=1
    printNameNtimes(1, n);
    return 0;
}