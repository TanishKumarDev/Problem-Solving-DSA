/**  
 * Problem: Check if a string reads the same forwards and backwards
 * 
 * A string is a palindrome if it remains unchanged when reversed.
 * 
 * https://www.geeksforgeeks.org/problems/palindrome-string0817/1
 * 
 * - Examples:
 * - "madam" -> true (reads same forwards and backwards)
 * - "hello" -> false (reads different)
 * - "racecar" -> true
 * - "a" -> true (single character)
 * - "" -> true (empty string)
 * 
 * Approaches:
 * 1. Recursive Two-Pointer Approach
 * 2. Iterative Two-Pointer Approach
 * 3. Using String Reversal
 * 
 * Intuition:
 * - A string is palindrome if first and last characters match,
 *   and the substring between them is also a palindrome
 * - We can check this by comparing characters from both ends
 * - Process continues until we reach the middle
 * - Single character and empty string are always palindromes
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Recursive Two-Pointer Approach
 * - Uses single pointer moving from start to middle
 * - Compares with corresponding character from end
 * - Most elegant recursive solution
 * 
 * TC: O(n/2) = O(n) - Makes n/2 recursive calls
 * SC: O(n/2) = O(n) - Recursion stack space
 */
bool isPalindromeRecursive(int i, string& s) {
    // Base case 1: reached or crossed middle
    if (i >= s.length() / 2) return true;
    
    // Base case 2: mismatch found
    if (s[i] != s[s.length() - i - 1]) return false;
    
    // Recursive case: check next pair of characters
    return isPalindromeRecursive(i + 1, s);
}

/**
 * Approach 2: Iterative Two-Pointer Approach
 * - Uses two pointers moving toward center
 * - More space efficient
 * - Same logic as recursive approach
 * 
 * TC: O(n/2) = O(n) - Makes n/2 comparisons
 * SC: O(1) - Constant space
 */
bool isPalindromeIterative(string& s) {
    int left = 0, right = s.length() - 1;
    while (left < right) {
        if (s[left] != s[right]) return false;
        left++;
        right--;
    }
    return true;
}

/**
 * Approach 3: Using String Reversal
 * - Creates a reversed copy of string
 * - Compares original with reversed
 * - Not in-place, uses extra space
 * - Demonstrates alternative approach
 * 
 * TC: O(n) - String reversal and comparison
 * SC: O(n) - Extra space for reversed string
 */
bool isPalindromeReversal(string& s) {
    string reversed = s;
    reverse(reversed.begin(), reversed.end());
    return s == reversed;
}

// Helper function to print result
void printResult(const string& s, bool isPal) {
    cout << "String: \"" << s << "\" is " << (isPal ? "a palindrome" : "not a palindrome") << endl;
}

// 🎯 Driver Function
int main() {
    string s;
    cout << "Enter a string: ";
    cin >> s;
    
    // Approach 1: Recursive
    cout << "\nApproach 1 - Recursive Two-Pointer:" << endl;
    printResult(s, isPalindromeRecursive(0, s));
    
    // Approach 2: Iterative
    cout << "\nApproach 2 - Iterative Two-Pointer:" << endl;
    printResult(s, isPalindromeIterative(s));
    
    // Approach 3: String Reversal
    cout << "\nApproach 3 - String Reversal:" << endl;
    printResult(s, isPalindromeReversal(s));
    
    return 0;
}

/**
 * Additional Notes:
 * 1. Two-Pointer Technique:
 *    - Very efficient for palindrome checking
 *    - Works for both even and odd length strings
 *    - Can be extended to check substrings
 * 
 * 2. Recursive vs Iterative:
 *    - Iterative is more space efficient (O(1) vs O(n))
 *    - Both have same time complexity O(n)
 *    - Recursive is more elegant but can cause stack overflow for long strings
 * 
 * 3. Edge Cases:
 *    - Empty string: always palindrome
 *    - Single character: always palindrome
 *    - Even length: pointers meet at middle
 *    - Odd length: pointers cross at middle
 * 
 * 4. Variations:
 *    - Case-insensitive palindrome (convert to lowercase first)
 *    - Alphanumeric palindrome (ignore non-alphanumeric chars)
 *    - Word-level palindrome (check if words form palindrome)
 * 
 * 5. Applications:
 *    - DNA sequence analysis
 *    - Text processing
 *    - Natural language processing
 *    - Data validation
 */
