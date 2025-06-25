#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Recursive Implementation of atoi()
// Example: s = "123" → 123, s = "-456" → -456
// Constraint: 0 <= s.length() <= 10, digits and optional +/-, no overflow (basic)

// 🟢 Recursive Approach
// Intuition: Process one digit at a time, build result recursively.
// Algo:
// 1. Main: Handle sign, call helper with substring.
// 2. Helper: Base case (end of string), convert digit, recurse on rest.
// TC: O(n) for single pass
// SC: O(n) for call stack

int atoiHelper(string s, int index, long result) {
    // Base case: end of string
    if (index >= s.length()) return result;
    
    // Check for invalid character (variation)
    if (s[index] < '0' || s[index] > '9') return result;
    
    // Convert character to digit
    int digit = s[index] - '0';
    
    // Overflow check (variation)
    if (result > INT_MAX / 10 || (result == INT_MAX / 10 && digit > 7)) {
        return INT_MAX;
    }
    
    // Update result: result = result * 10 + digit
    result = result * 10 + digit;
    
    // Recurse on remaining string
    return atoiHelper(s, index + 1, result);
}

int atoi(string s) {
    // Empty string
    if (s.empty()) return 0;
    
    // Handle sign
    int sign = 1, start = 0;
    if (s[0] == '-') { sign = -1; start = 1; }
    else if (s[0] == '+') { start = 1; }
    
    // Call helper, apply sign
    long result = atoiHelper(s, start, 0);
    
    // Apply overflow check after sign
    if (sign == -1 && result > (long)INT_MAX + 1) return INT_MIN;
    if (sign == 1 && result > INT_MAX) return INT_MAX;
    
    return sign * (int)result;
}

int main() {
    // Test cases
    vector<string> tests = {"123", "-456", "0", "", "+42", "2147483647", "-2147483648"};
    for (string s : tests) {
        cout << "Input: \"" << s << "\" → Output: " << atoi(s) << endl;
    }
    return 0;
}