/*
Problem Statement: Given a collection of candidate numbers and a target number, find all unique combinations 
where candidate numbers sum to target. Each number may only be used once in the combination.

Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8
Output: [[1,1,6],[1,2,5],[1,7],[2,6]]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5
Output: [[1,2,2],[5]]

Intuition:
- Use recursion and backtracking to try different combinations
- For each number, we can either include it once or skip it
- Need to handle duplicates to avoid duplicate combinations
- Keep track of current sum and combination being built
- When target sum is reached, we've found a valid combination

Algorithm:
1. Sort input array to handle duplicates and optimize
2. Use recursive function that takes current index, remaining target, and current combination
3. Base case: if target becomes 0, we found valid combination
4. For each number from current index:
   - Skip if number > remaining target
   - Skip duplicates at same level to avoid duplicate combinations
   - Include current number and recur with next index
   - Backtrack by removing number
5. Return all valid combinations found

Time & Space Complexity Analysis:

Time Complexity: O(2^n * k) where:
- n is the length of candidates array
- k is average length of combinations
- Each number can be either picked or not picked
- Total recursive calls = O(2^n) for all possible combinations
- Each combination copied takes O(k) time

Space Complexity: O(k*x) where:
- k is average length of each combination
- x is total number of valid combinations found
- Additional O(n) recursion stack space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombinations(int index, int target, vector<int>& arr, vector<vector<int>>& ans, vector<int>& curr) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        // Try all possible numbers from current index
        for (int i = index; i < arr.size(); i++) {
            // Skip if current number is too large
            if (arr[i] > target) break;
            
            // Skip duplicates at same level to avoid duplicate combinations
            if (i > index && arr[i] == arr[i-1]) continue;
            
            // Include current number in our combination
            curr.push_back(arr[i]);

            // Recur with:
            // - Next index i+1 since we can use each number only once
            // - Reduced target by subtracting current number
            findCombinations(i + 1, target - arr[i], arr, ans, curr);

            // Backtrack by removing the number we added
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> curr;
        sort(candidates.begin(), candidates.end()); // Sort to handle duplicates
        findCombinations(0, target, candidates, ans, curr);
        return ans;
    }
};

int main() {
    Solution solution;
    
    // Test Case 1
    vector<int> candidates1 = {10,1,2,7,6,1,5};
    int target1 = 8;
    vector<vector<int>> result1 = solution.combinationSum2(candidates1, target1);
    
    cout << "Test Case 1 Output:" << endl;
    for (const auto& combination : result1) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Test Case 2
    vector<int> candidates2 = {2,5,2,1,2};
    int target2 = 5;
    vector<vector<int>> result2 = solution.combinationSum2(candidates2, target2);
    
    cout << "\nTest Case 2 Output:" << endl;
    for (const auto& combination : result2) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    return 0;
}
