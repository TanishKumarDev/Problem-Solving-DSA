#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Palindrome Number (LeetCode 9)
https://leetcode.com/problems/palindrome-number/submissions/1700483514/

// Example: x = 121 → true, x = -121 → false, x = 10 → false
// Constraints: -2³¹ <= x <= 2³¹ - 1

// 🔴 Brute Force (String Conversion)
// TC: O(log x), SC: O(log x)
bool isPalindromeBrute(int x) {
    string s = to_string(x);
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

// 🟢 Optimized (Mathematical - Reverse Number)
// TC: O(log x), SC: O(1)
bool isPalindromeOptimized(int x) {
    if (x < 0) return false;
    long long reversed = 0;
    int temp = x;
    while (temp > 0) {
        int digit = temp % 10;
        reversed = reversed * 10 + digit;
        temp /= 10;
    }
    return reversed == x;
}

int main() {
    int x = 121;
    cout << "Brute Force: " << (isPalindromeBrute(x) ? "true" : "false") << endl;
    cout << "Optimized: " << (isPalindromeOptimized(x) ? "true" : "false") << endl;
    return 0;
}
