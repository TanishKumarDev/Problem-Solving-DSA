#include <bits/stdc++.h>
using namespace std;

// 🔄 Approach 1: Decrementing Recursion
// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space
void printNto1_Decrement(int i) {
    // Base case: Stop when we reach 0
    if (i < 1) return;

    // Print current number
    cout << i << endl;
    
    // Recursive call with decrement
    printNto1_Decrement(i - 1);
}

// ⚡ Approach 2: Using Backtracking
// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space
void printNto1_Backtrack(int i, int n) {
    // Base case: Stop when we exceed n
    if (i > n) return;
    
    // Recursive call first (backtracking)
    printNto1_Backtrack(i + 1, n);
    
    // Print after recursion (this will print in reverse)
    cout << i << endl;
}

// 🎯 Driver Function
int main() {
    int n;
    // Input: n (print numbers from n to 1)
    cin >> n;

    cout << "Approach 1 (Decrementing):\n";
    printNto1_Decrement(n);

    cout << "\nApproach 2 (Backtracking):\n";
    printNto1_Backtrack(1, n);
    
    return 0;
}

/* 
📝 Note: Both approaches achieve the same result but demonstrate different recursive thinking:
1. Decrementing: Direct approach, starts from n and decrements
2. Backtracking: Starts from 1, reaches n, then prints while returning
   - This is a good example of how recursion can be used for reverse operations
   - Useful pattern for many other problems (like printing array in reverse)
*/