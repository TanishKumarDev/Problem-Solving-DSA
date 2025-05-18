#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- Sum of digits raised to power of digit count equals number
- Example: 153 = 1^3 + 5^3 + 3^3
*/

// Approach 1: Brute Force (String conversion)
// Time: O(n)
// Space: O(n)
bool isArmstrongBrute(int n) {
    string s = to_string(n);
    int k = s.length();
    long sum = 0;
    for (char c : s) {
        sum += pow(c - '0', k);
    }
    return sum == n;
}

// Approach 2: Better (Count digits separately)
// Time: O(n)
// Space: O(1)
bool isArmstrongBetter(int n) {
    int original = n, count = 0;
    while (original != 0) {
        original /= 10;
        count++;
    }
    original = n;
    long sum = 0;
    while (original != 0) {
        sum += pow(original % 10, count);
        original /= 10;
    }
    return sum == n;
}

// Approach 3: Optimal (Early termination)
// Time: O(n)
// Space: O(1)
bool isArmstrongOptimal(int n) {
    int original = n, count = 0;
    long sum = 0;
    // Count digits
    while (original != 0) {
        original /= 10;
        count++;
    }
    original = n;
    // Calculate sum with early termination
    while (original != 0 && sum <= n) {
        sum += pow(original % 10, count);
        original /= 10;
    }
    return sum == n;
}

int main() {
    int num;
    cin >> num; // Input a number
    
    cout << "Brute: " << (isArmstrongBrute(num) ? "Yes" : "No") << endl;
    cout << "Better: " << (isArmstrongBetter(num) ? "Yes" : "No") << endl;
    cout << "Optimal: " << (isArmstrongOptimal(num) ? "Yes" : "No") << endl;
    return 0;
}