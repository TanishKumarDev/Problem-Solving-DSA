#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Find the difference between the maximum and minimum numbers formed by replacing at most one digit in the given number
// https://leetcode.com/problems/maximum-difference-by-remapping-a-digit/description/?envType=daily-question&envId=2025-06-14

// Example : 
//    Input: 2736 → Max: 9736 (replace 2 with 9), Min: 0736 (replace 2 with 0) → Output: 9000
//    Input: 9999 → Max: 9999, Min: 0000 → Output: 9999
// Constraint : 0 <= num <= 10^8

// 🔴 Approach 1 Brute Force : Check all possible single-digit replacements
// Intuition : Try replacing every digit with every possible digit (0-9) and find max/min
// Algo :
//    1. Convert number to string
//    2. For each digit, try replacing it with 0-9
//    3. Track maximum and minimum numbers formed
//    4. Return their difference
// TC : O(N * 10 * N) = O(N²) (N = number of digits)
// SC : O(N) for string conversion

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: 
// Intuition : 
// We can compute max and min in single pass
// by replacing the first non-'9' digit with '9' for max and the first digit with '0' for min

// Algo :
//    1. Convert number to string
//    2. While finding max replacement digit, simultaneously track digits for min
//    3. Compute max and min numbers on-the-fly
// TC : O(N)
// SC : O(N) (can be O(1) if we process number digit by digit without string conversion)

class Solution {
public:
    int minMaxDifference(int num) {
        string s = to_string(num);
        
        // Find first non-'9' digit for max replacement
        char maxReplace = ' ';
        for (char c : s) {
            if (c != '9') {
                maxReplace = c;
                break;
            }
        }
        
        // Create max number by replacing maxReplace with '9'
        string maxS = s;
        if (maxReplace != ' ') {
            for (char &c : maxS) {
                if (c == maxReplace) c = '9';
            }
        }
        
        // Create min number by replacing first digit with '0'
        char minReplace = s[0];
        string minS = s;
        for (char &c : minS) {
            if (c == minReplace) c = '0';
        }
        
        return stoi(maxS) - stoi(minS);
    }
};

int main()
{
    Solution sol;
    cout << sol.minMaxDifference(2736) << endl;  // Output: 9000
    cout << sol.minMaxDifference(9999) << endl;   // Output: 9999
    cout << sol.minMaxDifference(0) << endl;      // Output: 0
    return 0;
}