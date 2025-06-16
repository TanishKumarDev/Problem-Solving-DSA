// Problem Statement
// Sum of first N natural numbers using recursion.

// Example: If n=5, output should be: 15

#include <bits/stdc++.h>
using namespace std;
// Approach 1 : Parameterized Recursion

// Intuition
// We need to calculate the sum of the first N natural numbers using recursion. The idea is to use a recursive function that adds the current number to the sum of the previous numbers until it reaches 0.

// Algorithm
// 1. Define a recursive function that takes one parameter: the current number.
// 2. The function will add the current number to the sum of the previous numbers.
// 3. Base Case: If the current number is 0, we return 0.
// 4. Return the current number plus the sum of the previous numbers.

// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space
int functionalSum(int n) {
    // Base case: If n is 0, return 0
    if (n == 0) return 0;
    
    // Recursive case: Return n + sum of first (n-1) natural numbers
    return n + functionalSum(n - 1);
}

// Approach 2 : Parameterized Recursion

// Intuition
// We need to calculate the sum of the first N natural numbers using recursion. The idea is to use a recursive function that takes an additional parameter to keep track of the accumulated sum.

// Algorithm
// 1. Define a recursive function that takes two parameters: the current number and the accumulated sum.
// 2. The function will add the current number to the accumulated sum.
// 3. Base Case: If the current number is less than 1, we return the accumulated sum.
// 4. Return the accumulated sum plus the current number and make a recursive call with the next lower number.

// T.C: O(n) - Makes n recursive calls
// S.C: O(n) - Recursion stack space
int parameterizedSum(int n, int sum) {
    if(n < 1) return sum;

    return parameterizedSum(n - 1, sum + n);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    cout <<  "functionalSum " << functionalSum(n)<< endl;
    cout <<  "parameterizedSum " << parameterizedSum(n,0)<< endl;

    return 0;
}
