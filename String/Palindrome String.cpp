#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Check if a String is a Palindrome
// Given a string, determine if it is a palindrome. A palindrome is a string that reads the same forward and backward.
// Example:
// Input: s = "racecar"  -> Output: 1 (true, it’s a palindrome)
// Input: s = "hello"    -> Output: 0 (false, not a palindrome)
// Constraints:
// - 1 <= s.length() <= 10^5
// - String contains lowercase English letters only (for simplicity)

// 🔴 Approach 1: Brute Force (Reverse String)
// Intuition: A string is a palindrome if it equals its reverse. Create a reversed copy of the string and compare.
// Algo:
// 1. Create a new string as a copy of the input string.
// 2. Reverse the new string.
// 3. Compare the original and reversed strings.
// TC: O(n) - Copying and reversing take O(n), comparison takes O(n).
// SC: O(n) - Extra space for the reversed string.
int palindromeReverse(const string& s) {
    string reversed = s; // Create a copy
    reverse(reversed.begin(), reversed.end()); // Reverse the copy
    return (s == reversed) ? 1 : 0; // Compare
}

// 🔵 Approach 2: Two-Pointer
// Intuition: Use two pointers (left and right) to compare characters from both ends moving inward.
// Algo:
// 1. Initialize left = 0 and right = s.length() - 1.
// 2. While left < right:
//    - If s[left] != s[right], return 0 (not a palindrome).
//    - Increment left, decrement right.
// 3. Return 1 (is a palindrome).
// TC: O(n) - Traverse at most n/2 characters.
// SC: O(1) - Only uses two pointers, no extra space.
int palindromeTwoPointers(const string& s) {
    int left = 0;
    int right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) {
            return 0; // Not a palindrome
        }
        left++;
        right--;
    }
    return 1; // Is a palindrome
}
int palindromeTwoPointersImproved(string s){
    int len = s.length();

    for(int i = 0; i<len / 2; i++){
        if(s[i] != s[len - i - 1]){
            return 0;
        }
    }
    return 1;
}
// 🟢 Approach 3: Recursive
// Intuition: Recursively compare characters from both ends, shrinking the problem size.
// Algo:
// 1. Base case: If left > right, return 1 (empty or single character is palindrome).
// 2. If s[left] != s[right], return 0 (not a palindrome).
// 3. Recurse with left + 1 and right - 1.
// TC: O(n) - Makes n/2 recursive calls, each O(1).
// SC: O(n) - Due to recursive call stack.
int palindromeRecursive(const string& s, int left, int right) {
    if (left >= right) {
        return 1; // Base case: empty or single character
    }
    if (s[left] != s[right]) {
        return 0; // Not a palindrome
    }
    return palindromeRecursive(s, left + 1, right - 1);
}

int main() {
    // Test cases
    vector<string> testCases = {"racecar", "hello", "abba", "tanish"};
    
    cout << "=== Palindrome Check Results ===\n";
    for (const string& s : testCases) {
        cout << "\nString: " << s << endl;
        
        // Approach 1: Reverse
        cout << "Approach 1 (Reverse): " << (palindromeReverse(s) ? "Palindrome" : "Not a Palindrome") << endl;
        
        // Approach 2: Two-Pointer
        cout << "Approach 2 (Two-Pointer): " << (palindromeTwoPointers(s) ? "Palindrome" : "Not a Palindrome") << endl;

        // Approach 2: Two-Pointer Improved
        cout << "Approach 2 (Two-Pointer Improved): " << (palindromeTwoPointersImproved(s) ? "Palindrome" : "Not a Palindrome") << endl;
        
        // Approach 3: Recursive
        cout << "Approach 3 (Recursive): " << (palindromeRecursive(s, 0, s.length() - 1) ? "Palindrome" : "Not a Palindrome") << endl;
    }
    
    return 0;
}