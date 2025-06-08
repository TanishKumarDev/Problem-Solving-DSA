/*

Problem: Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example 1:

Input: digits = "23"
Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]
Example 2:

Input: digits = ""
Output: []
Example 3:

Input: digits = "2"
Output: ["a","b","c"]
 

Constraints:
1. 0 <= digits.length <= 4
2. digits[i] is a digit in the range ['2', '9'].

Algorithm:
1. Create a mapping of digits to their corresponding letters on a phone keypad
2. Use backtracking to generate all possible letter combinations:
   - Base case: when index equals length of input digits, add current combination to result
   - For each letter corresponding to current digit:
     a. Add letter to current combination
     b. Recursively try next digit
     c. Remove letter (backtrack)
3. Return all valid combinations

Time Complexity: O(4^N * N) where N is length of input string
- Each digit can map to 3-4 letters (worst case 4)
- We need to try all combinations
- Each combination takes O(N) to construct

Space Complexity: O(N)
- Recursion stack depth is O(N)
- Current combination string takes O(N) space
- Result vector not counted as per convention
*/

#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    // Map digits to corresponding letters
    unordered_map<char, string> digitToLetters = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}
    };
    
    void backtrack(const string& digits, int index, string& current, vector<string>& result) {
        // If current combination length equals digits length, add to result
        if (index == digits.length()) {
            if (!current.empty()) {
                result.push_back(current);
            }
            return;
        }
        
        // Get letters corresponding to current digit
        string letters = digitToLetters[digits[index]];
        
        // Try each letter for current digit
        for (char letter : letters) {
            current.push_back(letter);
            backtrack(digits, index + 1, current, result);
            current.pop_back();
        }
    }
    
public:
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        
        vector<string> result;
        string current;
        backtrack(digits, 0, current, result);
        return result;
    }
};
int main() {
    Solution solution;
    
    // Test cases
    vector<string> test_cases = {"23", "", "2"};
    
    for(const string& digits : test_cases) {
        cout << "Input: digits = \"" << digits << "\"" << endl;
        vector<string> result = solution.letterCombinations(digits);
        cout << "Output: [";
        for(int i = 0; i < result.size(); i++) {
            cout << "\"" << result[i] << "\"";
            if(i < result.size() - 1) cout << ",";
        }
        cout << "]" << endl << endl;
    }
    
    return 0;
}
