#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Add Two Integers
// Example: num1 = 12, num2 = 5 → 17
// Constraints: -100 <= num1, num2 <= 100

// 🟢 Direct Addition
// TC: O(1), SC: O(1)
int sum(int num1, int num2) {
    return num1 + num2;
}

int main() {
    int num1 = 12, num2 = 5;
    cout << "Sum: " << sum(num1, num2) << endl; // Output: 17
    return 0;
}
