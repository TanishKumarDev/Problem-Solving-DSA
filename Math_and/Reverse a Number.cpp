#include <iostream>
#include <string>
#include <algorithm>
#include <climits>
using namespace std;

// === Approach 1: Brute Force (String Reversal) ===
// Intuition: Convert the number to a string, reverse it, and convert back to an integer.
// Algorithm:
//   1. Convert |N| to a string using to_string.
//   2. Reverse the string using std::reverse.
//   3. Convert the string back to an integer using stoi, handling overflow with try-catch.
//   4. Return the negative of the result if N was negative, or 0 if overflow occurs.
// Time Complexity: O(n), where n is the number of digits (string conversion and reversal).
// Space Complexity: O(n) for the string.
// Use: Simple but inefficient due to string operations; handles overflow via exception.
int reverseBrute(int n) {
    string s = to_string(abs(n)); // Convert absolute value to string
    reverse(s.begin(), s.end());  // Reverse the string
    try {
        int reversed = stoi(s);   // Convert back to integer
        return n < 0 ? -reversed : reversed; // Apply original sign
    } catch (...) {
        return 0; // Return 0 on overflow
    }
}

// === Approach 2: Better (Long Long Handling) ===
// Intuition: Build the reversed number using a long long to avoid overflow during computation.
// Algorithm:
//   1. Initialize reversed as 0 (long long).
//   2. While N != 0:
//      - Extract the last digit using N % 10.
//      - Update reversed = reversed * 10 + digit.
//      - Remove the last digit from N using N /= 10.
//   3. Check if reversed is within [INT_MIN, INT_MAX]; return 0 if overflow.
//   4. Return reversed with the original sign.
// Time Complexity: O(n), where n is the number of digits.
// Space Complexity: O(1), uses only a constant amount of extra space.
// Use: More efficient than string method, but overflow check is done after computation.
int reverseBetter(int n) {
    long long reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10; // Append digit
        n /= 10; // Remove last digit
    }
    // Check for 32-bit integer overflow
    return (reversed < INT_MIN || reversed > INT_MAX) ? 0 : reversed;
}

// === Approach 3: Optimal (Overflow Check) ===
// Intuition: Build the reversed number iteratively, checking for overflow before each update.
// Algorithm:
//   1. Initialize reversed as 0 (int).
//   2. While N != 0:
//      - Extract the last digit using N % 10.
//      - Check if reversed * 10 + digit would overflow [INT_MIN, INT_MAX].
//      - If no overflow, update reversed = reversed * 10 + digit.
//      - Remove the last digit from N using N /= 10.
//   3. Return reversed with the original sign.
// Time Complexity: O(n), where n is the number of digits.
// Space Complexity: O(1), uses only a constant amount of extra space.
// Use: Most robust for production, proactively prevents overflow; handles all edge cases.
int reverseOptimalOverflowCheck(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        // Check for overflow before multiplying
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && digit > 7)) return 0;
        if (reversed < INT_MIN / 10 || (reversed == INT_MIN / 10 && digit < -8)) return 0;
        reversed = reversed * 10 + digit; // Append digit
        n /= 10; // Remove last digit
    }
    return reversed;
}

// === Approach 4: Optimal (Simple Division) ===
// Intuition: Build the reversed number by extracting digits, enhanced to handle negative numbers and overflow.
// Algorithm:
//   1. Initialize reversed as 0 (int).
//   2. Store the sign of N and work with |N|.
//   3. While N > 0:
//      - Extract the last digit using N % 10.
//      - Check for overflow before updating reversed.
//      - Update reversed = reversed * 10 + digit.
//      - Remove the last digit from N using N /= 10.
//   4. Return reversed with the original sign, or 0 if overflow occurs.
// Time Complexity: O(n), where n is the number of digits.
// Space Complexity: O(1), uses only a constant amount of extra space.
// Use: Simple and intuitive, but requires overflow and negative number handling for robustness.
int reverseOptimalSimple(int n) {
    int reversed = 0;
    int sign = (n < 0) ? -1 : 1; // Store the sign
    n = abs(n); // Work with absolute value
    while (n > 0) {
        int ld = n % 10; // Extract last digit
        // Check for overflow before updating
        if (reversed > INT_MAX / 10 || (reversed == INT_MAX / 10 && ld > 7)) return 0;
        reversed = (reversed * 10) + ld; // Append digit
        n /= 10; // Remove last digit
    }
    return sign * reversed; // Apply original sign
}

int main() {
    int num;
    cin >> num; // Input a number
    
    cout << "Brute (String): " << reverseBrute(num) << endl;
    cout << "Better (Long Long): " << reverseBetter(num) << endl;
    cout << "Optimal (Overflow Check): " << reverseOptimalOverflowCheck(num) << endl;
    cout << "Optimal (Simple Division): " << reverseOptimalSimple(num) << endl;
    return 0;
}