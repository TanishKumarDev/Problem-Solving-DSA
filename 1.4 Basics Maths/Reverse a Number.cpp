#include <bits/stdc++.h>
using namespace std;
/*
Intuition:
- Extract last digit and build new number
- Handle overflow cases for 32-bit integers
*/

// Approach 1: Brute Force (String reversal)
// Time: O(n)
// Space: O(n)
int reverseBrute(int n) {
    string s = to_string(abs(n));
    std::reverse(s.begin(), s.end());
    try {
        int reversed = stoi(s);
        return n < 0 ? -reversed : reversed;
    } catch (...) {
        return 0; // Overflow case
    }
}

// Approach 2: Better (Long long handling)
// Time: O(n)
// Space: O(1)
int reverseBetter(int n) {
    long long reversed = 0;
    while (n != 0) {
        reversed = reversed * 10 + n % 10;
        n /= 10;
    }
    return (reversed < INT_MIN || reversed > INT_MAX) ? 0 : reversed;
}

// Approach 3: Optimal (Early overflow check)
// Time: O(n)
// Space: O(1)
int reverseOptimal(int n) {
    int reversed = 0;
    while (n != 0) {
        int digit = n % 10;
        // Check for overflow before actually multiplying
        if (reversed > INT_MAX/10 || (reversed == INT_MAX/10 && digit > 7)) return 0;
        if (reversed < INT_MIN/10 || (reversed == INT_MIN/10 && digit < -8)) return 0;
        reversed = reversed * 10 + digit;
        n /= 10;
    }
    return reversed;
}

int main() {
    int num;
    cin >> num; // Input a number
    
    cout << "Brute: " << reverseBrute(num) << endl;
    cout << "Better: " << reverseBetter(num) << endl;
    cout << "Optimal: " << reverseOptimal(num) << endl;
    return 0;
}