#include <bits/stdc++.h>
using namespace std;

/*
Intuition for Recursive Approach:
1. We process the string character by character from left to right
2. For each character, we convert it to a digit and add it to our running result
3. The recursive approach builds the number digit by digit, multiplying the previous result by 10
   and adding the current digit
4. Base case: when we reach the end of string, return the accumulated result
*/
// Time Complexity: O(n) where n is the length of input string
// Space Complexity: O(n) due to recursion stack and string copies
int recursiveAtoi(string str, int i = 0, int result = 0) {
    if (i == str.length()) return result; // base case when we have reached the end of the string
    
    int digit = str[i] - '0'; // convert the character to an integer
    result = result * 10 + digit; // update the result by shifting left (multiply by 10) and adding new digit
    
    return recursiveAtoi(str, i + 1, result); // recursive call with next position and updated result
}

/*
Intuition for Iterative Approach:
1. Handle edge cases first:
   - Skip leading whitespace
   - Check for sign (+ or -)
2. Process digits one by one:
   - Convert each character to digit
   - Build number by multiplying previous result by 10 and adding new digit
3. Handle overflow:
   - Use long to detect overflow during calculation
   - Clamp result to INT_MAX or INT_MIN if overflow occurs
4. Return final result with appropriate sign
*/
// Time Complexity: O(n) where n is the length of input string
// Space Complexity: O(1) due to constant space usage for variables and no recursion stack needed
int myAtoi(string s) {
    int i = 0, sign = 1;
    long result = 0; // Use long to detect overflow during calculation

    // Step 1: Ignore leading whitespace
    while (i < s.size() && s[i] == ' ') {
        i++; 
    }

    // Step 2: Check for sign character
    if (i < s.size() && (s[i] == '+' || s[i] == '-')) {
        sign = (s[i++] == '-') ? -1 : 1; // if the character is a minus sign, set the sign to -1, otherwise set it to 1
    }

    // Step 3: Read digits until non-digit or end of string
    while (i < s.size() && isdigit(s[i])) {
        int digit = s[i++] - '0'; // convert the character to an integer

        // Step 4: Check for overflow and clamp
        if (result > (INT_MAX - digit) / 10) { // if the result is greater than the maximum integer value, return the maximum integer value
            return (sign == 1) ? INT_MAX : INT_MIN; // if the sign is positive, return the maximum integer value, otherwise return the minimum integer value
        }

        // Step 5: Convert digit to integer
        result = result * 10 + digit;
    }

    // Step 6: Return final result with sign
    return static_cast<int>(result * sign);
}

int main()
{   
    // Approach 1: Recursive
    string s;
    cout << "Enter a string: ";
    cin >> s;
    cout << "The integer value of the string is: " << recursiveAtoi(s) << endl;

    // Approach 2: Iterative
    cout << "The integer value of the string is: " << myAtoi(s) << endl;

    return 0;
}







