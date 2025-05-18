#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- A palindrome reads the same backward as forward
- Compare original number with its reverse
*/

// Approach 1: Brute Force (String comparison)
// Time: O(n)
// Space: O(n)
bool isPalindromeBrute(int x) {
    if (x < 0) return false;
    string s = to_string(x);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// Approach 2: Better (Full number reversal)
// Time: O(n)
// Space: O(1)
bool isPalindromeBetter(int x) {
    if (x < 0) return false;
    long reversed = 0;
    int original = x;
    while (x != 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return original == reversed;
}

// Approach 3: Optimal (Half number comparison)
// Time: O(n)
// Space: O(1)
bool isPalindromeOptimal(int x) {
    if (x < 0 || (x % 10 == 0 && x != 0)) return false;
    int reversed = 0;
    while (x > reversed) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    return x == reversed || x == reversed / 10;
}

int main() {
    int num;
    cin >> num; // Input a number
    
    cout << "Brute: " << (isPalindromeBrute(num) ? "Yes" : "No") << endl;
    cout << "Better: " << (isPalindromeBetter(num) ? "Yes" : "No") << endl;
    cout << "Optimal: " << (isPalindromeOptimal(num) ? "Yes" : "No") << endl;
    return 0;
}