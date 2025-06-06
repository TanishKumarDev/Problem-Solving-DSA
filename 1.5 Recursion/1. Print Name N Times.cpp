#include <bits/stdc++.h>
using namespace std;

// 🔄 Recursive Approach
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