/**
 * Problem: Implement atoi() function recursively
 * atoi() converts a string to its integer representation
 * Example: 
 * - "1234" -> 1234
 * - "0" -> 0
 * - "-123" -> -123
 * - "12a3" -> 12 (stops at first non-digit)
 * 
 * Approaches:
 * 1. Right to Left Recursion
 * 2. Left to Right Recursion
 * 3. Iterative Approach
 * 
 * Intuition:
 * - Convert each character to its digit value
 * - Build number by multiplying previous result by 10
 * - Handle negative numbers and invalid characters
 * - Can process string from either end
 */

#include <bits/stdc++.h>
using namespace std;

/**
 * Approach 1: Right to Left Recursion
 * - Processes string from right to left
 * - Builds number by multiplying previous result by 10
 * - More intuitive for understanding place values
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
int atoiRightToLeft(string& s, int n) {
    // Base case: empty string
    if (n == 0) return 0;
    
    // Validate last character is a digit
    if (!isdigit(s[n-1])) {
        throw invalid_argument("Invalid character in string");
    }
    
    // Get last digit and recursive call
    int digit = s[n-1] - '0';
    return atoiRightToLeft(s, n-1) * 10 + digit;
}

/**
 * Approach 2: Left to Right Recursion
 * - Processes string from left to right
 * - Uses accumulator parameter
 * - More efficient as it doesn't need multiplication at each step
 * 
 * TC: O(n) - Makes n recursive calls
 * SC: O(n) - Recursion stack space
 */
int atoiLeftToRight(string& s, int idx, int result) {
    // Base case: reached end of string
    if (idx == s.length()) return result;
    
    // Validate current character is a digit
    if (!isdigit(s[idx])) {
        throw invalid_argument("Invalid character in string");
    }
    
    // Process current digit and recursive call
    int digit = s[idx] - '0';
    return atoiLeftToRight(s, idx + 1, result * 10 + digit);
}

/**
 * Approach 3: Iterative Approach
 * - Uses loop instead of recursion
 * - More space efficient
 * - Easier to handle edge cases
 * 
 * TC: O(n) - Single pass through string
 * SC: O(1) - Constant space
 */
int atoiIterative(string& s) {
    int result = 0;
    bool isNegative = false;
    int i = 0;
    
    // Handle negative sign
    if (s[0] == '-') {
        isNegative = true;
        i = 1;
    }
    
    // Process each character
    for (; i < s.length(); i++) {
        if (!isdigit(s[i])) {
            throw invalid_argument("Invalid character in string");
        }
        result = result * 10 + (s[i] - '0');
    }
    
    return isNegative ? -result : result;
}

// Helper function to validate and clean input string
string validateInput(string& s) {
    // Remove leading whitespace
    s.erase(0, s.find_first_not_of(" \t"));
    
    // Check if string is empty after cleaning
    if (s.empty()) {
        throw invalid_argument("Empty string after cleaning");
    }
    
    // Handle negative numbers
    bool isNegative = (s[0] == '-');
    if (isNegative) s = s.substr(1);
    
    // Remove leading zeros
    s.erase(0, s.find_first_not_of('0'));
    
    // If string is empty after removing zeros, it was "0" or "-0"
    if (s.empty()) return "0";
    
    // Add back negative sign if needed
    return isNegative ? "-" + s : s;
}

// Helper function to print conversion result
void printConversion(const string& input, int result) {
    cout << "Input string: \"" << input << "\"" << endl;
    cout << "Converted integer: " << result << endl;
    cout << "------------------------" << endl;
}

// 🎯 Driver Function
int main() {
    try {
        string input;
        // cout << "Enter a string to convert: ";
        cin >> input;
        
        // Validate and clean input
        string cleanedInput = validateInput(input);
        
        // Approach 1: Right to Left
        cout << "\nApproach 1 - Right to Left Recursion:" << endl;
        int result1 = atoiRightToLeft(cleanedInput, cleanedInput.length());
        printConversion(input, result1);
        
        // Approach 2: Left to Right
        cout << "\nApproach 2 - Left to Right Recursion:" << endl;
        int result2 = atoiLeftToRight(cleanedInput, 0, 0);
        printConversion(input, result2);
        
        // Approach 3: Iterative
        cout << "\nApproach 3 - Iterative:" << endl;
        int result3 = atoiIterative(cleanedInput);
        printConversion(input, result3);
        
    } catch (const invalid_argument& e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    } catch (const exception& e) {
        cerr << "Unexpected error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

/**
 * Additional Notes:
 * 1. Error Handling:
 *    - Invalid characters (non-digits)
 *    - Empty strings
 *    - Leading/trailing whitespace
 *    - Leading zeros
 *    - Negative numbers
 * 
 * 2. Edge Cases:
 *    - "0" -> 0
 *    - "-0" -> 0
 *    - "123" -> 123
 *    - "-123" -> -123
 *    - "00123" -> 123
 *    - "12a3" -> error
 *    - "" -> error
 * 
 * 3. Performance Comparison:
 *    - All approaches have O(n) time complexity
 *    - Iterative has O(1) space complexity
 *    - Recursive approaches have O(n) space complexity
 * 
 * 4. Applications:
 *    - Command line argument parsing
 *    - Configuration file reading
 *    - Data validation
 *    - String processing
 * 
 * 5. Limitations:
 *    - Integer overflow not handled
 *    - Very large numbers may cause issues
 *    - Could be extended to handle floating point
 */
