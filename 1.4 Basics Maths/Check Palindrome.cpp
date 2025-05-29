#include <iostream>
using namespace std;

// === Approach: Optimal (Reverse Integer) ===
// Intuition:
//   A number is a palindrome if it reads the same forwards and backwards.
//   We reverse the number mathematically and compare it with the original.
// Algorithm:
//   1. Store the original number in a duplicate variable.
//   2. Initialize revNum to 0.
//   3. While the number is greater than 0:
//       - Extract the last digit using n % 10.
//       - Append it to revNum: revNum = revNum * 10 + digit.
//       - Remove the last digit from n using n /= 10.
//   4. If reversed number equals the original, it's a palindrome.
// Time Complexity: O(log₁₀n) → number of digits in n
// Space Complexity: O(1) → only a few integer variables
// Use: This approach avoids string conversions and is efficient for numeric palindromes.
bool isPalindrome(int n) {
    int revNum = 0;
    int dup = n;

    while (n > 0) {
        int ld = n % 10;              // Extract last digit
        revNum = revNum * 10 + ld;    // Build reversed number
        n = n / 10;                   // Remove last digit
    }

    return dup == revNum;
}

int main() {
    int number;
    cin >> number; // Input a number

    if (isPalindrome(number)) {
        cout << number << " is a palindrome." << endl;
    } else {
        cout << number << " is not a palindrome." << endl;
    }

    return 0;
}
