#include <bits/stdc++.h>
using namespace std;

/**
  * 3442. Maximum Difference Between Even and Odd Frequency I
  * https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/description/
  * 
  * Problem:
  * Given a string s of lowercase English letters, find the maximum difference between
  * frequencies of two characters where one has odd frequency and one has even frequency.
  * 
  * Example 1:
  * Input: s = "aaaaabbc"
  * Output: 3
  * Explanation: 'a' has odd frequency 5, 'b' has even frequency 2. Difference is 5-2=3
  * 
  * Example 2:
  * Input: s = "abcabcab"
  * Output: 1
  * Explanation: 'a' has odd frequency 3, 'c' has even frequency 2. Difference is 3-2=1
  * 
  * Constraints:
  * - 3 <= s.length <= 100
  * - s consists only of lowercase English letters
  * - s contains at least one character with odd frequency and one with even frequency
  * 
  * Intuition:
  * - Count the frequency of each character in the string.
  * - Track the maximum frequency of characters with odd counts and the minimum frequency of characters with even counts.
  * - Return the difference between the maximum odd frequency and the minimum even frequency.
  * 
  *
  * Algorithm:
  * 1. Initialize a frequency array of size 26 to count occurrences of each character.
  * 2. Iterate through the string and populate the frequency array.
  * 3. Traverse the frequency array to find the maximum odd frequency and the minimum even frequency.
  * 4. If no valid odd or even frequency is found, return 0.
  * 5. Return the difference between the maximum odd frequency and the minimum even frequency.
  * 
  * Time Complexity:
  * O(n), where n is the length of the string s, since we traverse the string and the frequency array.
  * 
  * Space Complexity:
  * O(1), since the frequency array has a fixed size of 26 (for lowercase English letters).
  *
  * 🪴Try this too 3445. Maximum Difference Between Even and Odd Frequency II 
  * https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-ii/
  */
class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);

        // Count the frequency of each character
        for (char c : s) {
            freq[c - 'a']++;
        }

        int maxOdd = INT_MIN, minEven = INT_MAX;

        // Find the maximum odd frequency and the minimum even frequency
        for (int f : freq) {
            if (f > 0) {
                if (f % 2 == 1) {
                    maxOdd = max(maxOdd, f);
                } else {
                    minEven = min(minEven, f);
                }
            }
        }

        // If no valid odd or even frequency is found, return 0
        if (maxOdd == INT_MIN || minEven == INT_MAX) {
            return 0;
        }

        return maxOdd - minEven;
    }
};
int main()
{
    Solution sol;

    // Test case 1
    string s1 = "aaaaabbc"; // Example with odd frequency 5 (a) and even frequency 2 (b)
    // Expected output: 3 (5 - 2)
    cout << sol.maxDifference(s1) << endl;

    // Test case 2
    string s2 = "abcabcab"; // Example with odd frequency 3 (a, b, c) and no even frequency
    // Expected output: 0 (no even frequency)
    cout << sol.maxDifference(s2) << endl;
    return 0;
}