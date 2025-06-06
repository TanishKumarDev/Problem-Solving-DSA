#include <bits/stdc++.h>
using namespace std;

// 🔄 Recursive Approach
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