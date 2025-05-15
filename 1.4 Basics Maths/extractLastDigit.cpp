#include <bits/stdc++.h>
using namespace std;

vector<int> extractDigits(int n)
{
    vector<int> digits;
    while (n > 0)
    {
        int lastDigit = n % 10;      // Get the last digit
        digits.push_back(lastDigit); // Store it in the vector
        n /= 10;                     // Remove the last digit from n
    }
    reverse(digits.begin(), digits.end()); // Reverse to get the correct order
    return digits;
}
int main()
{
    int n;
    cin >> n;
    // Extract last digit using modulo operator
    // int lastDigit = n % 10;
    // cout << "Last digit of " << n << " is: " << lastDigit << endl;

    // handle negative numbers
    if (n < 0)
    {
        n = -n; // make it positive
    }

    vector<int> digits = extractDigits(n);

    cout << "Digits of " << n << ": ";
    for (int digit : digits)
    {
        cout << digit << " ";
    }
    cout << endl;

    return 0;
}


// 🔍 Function: extractDigits(int N)
// ✅ Logic Recap
// We repeatedly extract the last digit (N % 10) and divide N by 10.

// Push each digit into a vector.

// Reverse the vector to restore correct order.

// ⏱️ Time Complexity (TC)
// Let's assume N has d digits.
// Loop runs d times (once for each digit).

// Each push_back() is O(1) → Total O(d)

// reverse(ans.begin(), ans.end()) is also O(d)

// 🔹 Total Time Complexity: O(d)
// Where d = number of digits in N, or equivalently, d = floor(log₁₀N) + 1

// 💾 Space Complexity (SC)
// You store d digits in a vector → O(d) space.

// No additional space used apart from the vector.

// 🔹 Total Space Complexity: O(d)