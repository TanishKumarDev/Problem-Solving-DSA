#include <bits/stdc++.h>
using namespace std;

// Problem Statement
// Print a name 'n' times using recursion.
// Example: If n=5, output should be:
// 1
// 2
// 3
// 4
// 5

// Intuition 
// We need to print a name 'n' times using recursion. The idea is to use a recursive function that prints the name and calls itself until it has printed the name 'n' times.

// Algorithm
// 1. Define a recursive function that takes two parameters: the current number and the total number.
// 2. We will use a recursive function to print numbers from 1 to n.
// 3. The function will take two parameters: the current number and the total number.
// 4. Base Case: If the current number exceeds n, we stop the recursion.
// 5. Print the current number.
// 6. Make a recursive call to print the next number.


// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space

void printNumbers(int i, int n)
{
    // Base case: Stop when we reach n+1
    if (i > n) return;
    
    // Print current number
    cout << i << endl;
    
    // Recursive call for next number
    printNumbers(i + 1, n);
}

// 🎯 Driver Function
int main()
{
    int n;
    // Input: n (print numbers from 1 to n)
    cin >> n;

    // Start recursion from i=1
    printNumbers(1, n);
    return 0;
}