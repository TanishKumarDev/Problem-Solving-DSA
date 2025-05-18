#include <iostream>
#include <cmath>
#include <string>
using namespace std;

/*
Intuition:
- A digit is a single symbol used to represent numbers
- We can count digits by repeatedly removing digits from the number
*/

// Approach 1: Brute Force (Convert to string)
// Time: O(n) where n is number of digits
// Space: O(n) for string conversion
int countDigitsBrute(int n) {
    string s = to_string(abs(n)); // Handle negative numbers
    return s.length();
}

// Approach 2: Better (Logarithmic approach)
// Time: O(1)
// Space: O(1)
// Note: Doesn't work for n=0, needs special case
int countDigitsBetter(int n) {
    if (n == 0) return 1;
    return floor(log10(abs(n))) + 1;
}

// Approach 3: Optimal (Division method)
// Time: O(n) where n is number of digits
// Space: O(1)
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

int main() {
    int num;
    cin >> num; // Input a number
    
    cout << "Brute: " << countDigitsBrute(num) << endl;
    cout << "Better: " << countDigitsBetter(num) << endl;
    cout << "Optimal: " << countDigitsOptimal(num) << endl;
    return 0;
}