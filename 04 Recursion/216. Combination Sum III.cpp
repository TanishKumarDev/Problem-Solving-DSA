/*
Problem: Find all valid combinations of k numbers that sum up to n using numbers 1-9 only once

Intuition:
- Use backtracking to try different combinations
- For each position, try numbers from 1-9 that haven't been used
- Keep track of current sum and number of elements used
- Add valid combinations when k numbers sum to target

Time Complexity: O(C(9,k)) - we need to try all possible combinations of k numbers from 9 numbers
Space Complexity: O(k) - recursion stack depth + temporary vector to store current combination

Approach:
1. Use recursive backtracking with parameters:
   - start: current number to start trying from
   - k: remaining numbers needed
   - n: remaining sum needed
   - current combination vector
   - result vector
2. Base cases:
   - If k==0 and n==0: valid combination found
   - If k==0 or n<=0: invalid combination
3. Try numbers from start to 9, recursively call with:
   - reduced k and n
   - next number as start
*/
#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    void backtrack(int start, int k, int n, vector<int>& curr, vector<vector<int>>& result) {
        // Base cases
        if (k == 0 && n == 0) {
            result.push_back(curr);
            return;
        }
        if (k == 0 || n <= 0) {
            return;
        }
        
        // Try each possible number from start to 9
        for (int i = start; i <= 9; i++) {
            curr.push_back(i);
            backtrack(i + 1, k - 1, n - i, curr, result);
            curr.pop_back();
        }
    }
    
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> result;
        vector<int> curr;
        backtrack(1, k, n, curr, result);
        return result;
    }
};
