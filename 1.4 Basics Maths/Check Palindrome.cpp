#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Palindrome Number
// Example: x=121 → true, x=-121 → false, x=10 → false
// Constraints: -2^31 <= x <= 2^31 - 1

// 🔴 Approach 1: Brute Force (String Comparison)
// Intuition: Convert the integer to a string to easily access and compare digits. Reverse the string using a built-in function and check if it matches the original. Handle negative numbers by returning false since they cannot be palindromes due to the negative sign.
// TC: O(log n), SC: O(log n)
bool isPalindromeBrute(int x) {
    if (x < 0) return false;
    string s = to_string(x);
    string rev = s;
    reverse(rev.begin(), rev.end());
    return s == rev;
}

// 🟡 Approach 2: Better (Full Number Reversal)
// Intuition: Extract the last digit of the number using x % 10, build the reversed number by multiplying the current reversed number by 10 and adding the digit, then remove the last digit from x using x / 10. Compare the reversed number with the original. Use a long for the reversed number to handle potential overflow.
// TC: O(log n), SC: O(1)
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

// 🟢 Approach 3: Optimal (Half Number Comparison)
// Intuition: Instead of reversing the entire number, reverse only half the digits. Stop when the remaining number (x) is less than or equal to the reversed number. For odd-length numbers, the middle digit is handled by comparing x with reversed / 10. Handle edge cases: negative numbers and numbers ending in 0 (except 0 itself) are not palindromes.
// TC: O(log n), SC: O(1)
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
    cout << "Enter a number: ";
    cin >> num;
    cout << "Brute: " << (isPalindromeBrute(num) ? "Yes" : "No") << endl;
    cout << "Better: " << (isPalindromeBetter(num) ? "Yes" : "No") << endl;
    cout << "Optimal: " << (isPalindromeOptimal(num) ? "Yes" : "No") << endl;
    return 0;
}
/*

👉 DRY RUN FOR OPTIMAL APPROACH

- Input: `x = 1221`
- Initialize: `reversed = 0`, check `x ≥ 0` and `x % 10 != 0 || x == 0`.
- Step 1: `x = 1221 > reversed = 0`:
    - `digit = 1221 % 10 = 1`.
    - `reversed = 0*10 + 1 = 1`.
    - `x = 1221 / 10 = 122`.
- Step 2: `x = 122 > reversed = 1`:
    - `digit = 122 % 10 = 2`.
    - `reversed = 1*10 + 2 = 12`.
    - `x = 122 / 10 = 12`.
- Step 3: `x = 12 ≤ reversed = 12`, stop.
- Compare: `x = 12 == reversed = 12` → `true`.

*/