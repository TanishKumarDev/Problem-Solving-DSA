#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- Largest number that divides both numbers
- Euclidean algorithm is most efficient
*/

// Approach 1: Brute Force (Linear scan)
// Time: O(min(a,b))
// Space: O(1)
int gcdBrute(int a, int b) {
    int gcd = 1;
    for (int i = 1; i <= min(a, b); i++) {
        if (a % i == 0 && b % i == 0) {
            gcd = i;
        }
    }
    return gcd;
}

// Approach 2: Better (Euclidean subtraction)
// Time: O(max(a,b)) worst case
// Space: O(1)
int gcdBetter(int a, int b) {
    while (a != b) {
        if (a > b) a -= b;
        else b -= a;
    }
    return a;
}

// Approach 3: Optimal (Euclidean division)
// Time: O(log(min(a,b)))
// Space: O(1)
int gcdOptimal(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int main() {
    int num1, num2;
    cin >> num1 >> num2; // Input two numbers

    cout << "Brute: " << gcdBrute(num1, num2) << endl;
    cout << "Better: " << gcdBetter(num1, num2) << endl;
    cout << "Optimal: " << gcdOptimal(num1, num2) << endl;
    return 0;
}