#include <bits/stdc++.h>
using namespace std;

// ---------------------------------------------------
// Approach 1: Brute Force - Recursive
// Time Complexity: O(N)
// Space Complexity: O(N) (due to recursion stack)
// ---------------------------------------------------
int factorialRecursive(int n) {
    if (n == 0 || n == 1) return 1;
    return n * factorialRecursive(n - 1);
}

// ---------------------------------------------------
// Approach 2: Better - Iterative
// Time Complexity: O(N)
// Space Complexity: O(1)
// ---------------------------------------------------
int factorialIterative(int n) {
    int ans = 1;
    for (int i = 2; i <= n; i++) {  // Minor optimize: start from 2
        ans *= i;
    }
    return ans;
}

int main() {
    int n;
    cin >> n;
    
    cout << "Factorial (Recursive) = " << factorialRecursive(n) << endl;
    cout << "Factorial (Iterative) = " << factorialIterative(n) << endl;
    
    return 0;
}
