/*
Problem Statement: Given an array of distinct integers and a target, return all unique combinations 
where chosen numbers sum to target. Numbers can be used unlimited times.

Example 1:
Input: array = [2,3,6,7], target = 7
Output: [[2,2,3],[7]]

Example 2: 
Input: array = [2], target = 1
Output: []

Intuition:
- Use recursion and backtracking to try different combinations
- For each number, we can either include it multiple times or skip it
- Keep track of current sum and combination being built
- When target sum is reached, we've found a valid combination

Algorithm:
1. Sort input array to handle duplicates and optimize
2. Use recursive function that takes current index, remaining target, and current combination
3. Base case: if target becomes 0, we found valid combination
4. For each number from current index:
   - Skip if number > remaining target
   - Include current number and recur with reduced target
   - Backtrack by removing number
5. Return all valid combinations found

Time & Space Complexity Analysis:

Time Complexity: O(2^t * k) where:
- t is the target value
- k is average length of combinations
- Each number can be picked multiple times up to target/num
- For target=10 and num=1, we make 10 recursive picks
- Total recursive calls = O(2^t) for all possible combinations
- Each combination copied takes O(k) time

Space Complexity: O(k*x) where:
- k is average length of each combination
- x is total number of valid combinations found
- Additional O(t) recursion stack space
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    void findCombinations(int index, int target, vector<int>& arr, 
                         vector<vector<int>>& ans, vector<int>& curr) {
        // Base case: if target becomes 0, we found a valid combination
        if (target == 0) {
            ans.push_back(curr);
            return;
        }
        
        // Try all possible numbers from current index
        for (int i = index; i < arr.size(); i++) {
            // Skip if current number is too large since we can't reach target with it
            if (arr[i] > target) continue;
            
            // Include current number in our combination
            curr.push_back(arr[i]);

            // Recur with:
            // - Same index i since we can reuse numbers
            // - Reduced target by subtracting current number
            // - Current combination gets passed down
            findCombinations(i, target - arr[i], arr, ans, curr);

            // Backtrack by removing the number we added
            // This is necessary because:
            // 1. We need to try other combinations without this number
            // 2. We're using the same curr vector for all recursive calls
            // 3. Without removing, numbers would accumulate incorrectly
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
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
    vector<int> candidates1 = {2,3,6,7};
    int target1 = 7;
    vector<vector<int>> result1 = solution.combinationSum(candidates1, target1);
    
    cout << "Test Case 1 Output:" << endl;
    for (const auto& combination : result1) {
        for (int num : combination) {
            cout << num << " ";
        }
        cout << endl;
    }
    
    // Test Case 2
    vector<int> candidates2 = {2};
    int target2 = 1;
    vector<vector<int>> result2 = solution.combinationSum(candidates2, target2);
    
    cout << "\nTest Case 2 Output:" << endl;
    if (result2.empty()) {
        cout << "[]" << endl;
    }
    
    return 0;
}
