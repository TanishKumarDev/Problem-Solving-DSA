#include <bits/stdc++.h>
using namespace std;

// Approach 1: Brute Force (String Conversion) 
// Intuition: Convert the number to a string and count its characters.
// Algorithm:
//   1. Convert the absolute value of N to a string using to_string.
//   2. Return the length of the string.
// Time Complexity: O(n) where n is the number of digits (string conversion cost).
// Space Complexity: O(n) for storing the string.
// Use: Simple but less efficient due to string conversion overhead.
int countDigitsBrute(int n) {
    string s = to_string(abs(n)); // Handle negative numbers
    return s.length();

}

// Approach 2: Better (Logarithmic Method) 
// Intuition: Use the logarithm base 10 to calculate the number of digits.
// Algorithm:
//   1. If N is 0, return 1 (special case).
//   2. Compute floor(log10(|N|)) + 1 to get the digit count.
// Time Complexity: O(1) as log10 is a constant-time operation.
// Space Complexity: O(1) as only a constant amount of memory is used.
// Use: Fast and efficient for most cases, but needs special handling for N=0.
int countDigitsBetter(int n) {
    if (n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

// Approach 3: Optimal (Division Method) 
// Intuition: Repeatedly divide the number by 10 to count digits.
// Algorithm:
//   1. If N is 0, return 1 (special case).
//   2. Use a loop to divide |N| by 10, incrementing a counter until N becomes 0.
// Time Complexity: O(n) where n is the number of digits.
// Space Complexity: O(1) as only a counter is used.
// Use: Efficient and straightforward, works for all cases.
int countDigitsOptimal(int n) {
    if (n == 0) return 1;
    int count = 0;
    n = abs(n); // Handle negative numbers
    while (n > 0) {
        n /= 10;
        count++;
    }
    return count;
}

// Approach 4: Recursive Division 
// Intuition: Use recursion to divide the number by 10 and count steps.
// Algorithm:
//   1. Base case: If N is 0, return 1; if N < 10, return 1 (single digit).
//   2. Recursive case: Divide N by 10 and add 1 to the result of the recursive call.
// Time Complexity: O(n) where n is the number of digits (due to recursive calls).
// Space Complexity: O(n) due to the recursion stack.
// Use: Elegant but less efficient due to recursion overhead; good for understanding.
int countDigitsRecursive(int n) {
    if (n == 0) return 1; // Special case for 0
    n = abs(n); // Handle negative numbers
    if (n < 10) return 1; // Base case: single digit
    return 1 + countDigitsRecursive(n / 10); // Recursive call
}

int main() {
    int num;
    cin >> num; // Input a number

    // Test all approaches
    cout << "Brute (String): " << countDigitsBrute(num) << endl;
    cout << "Better (Logarithmic): " << countDigitsBetter(num) << endl;
    cout << "Optimal (Division): " << countDigitsOptimal(num) << endl;
    cout << "Recursive (Division): " << countDigitsRecursive(num) << endl;

    return 0;
}