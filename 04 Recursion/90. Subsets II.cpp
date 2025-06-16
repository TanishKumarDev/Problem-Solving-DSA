/*
Problem: Given an integer array nums that may contain duplicates, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Approach:
1. Sort the array first to handle duplicates
2. Use recursion with backtracking to generate all subsets
3. Skip duplicate elements at same level to avoid duplicate subsets
4. For each element, we have two choices:
   - Include it in current subset
   - Skip it and move to next element

Time Complexity: O(2^n * k)
- 2^n for generating all possible subsets
- k average length of each subset for copying to result

Space Complexity: O(2^n * k)
- To store all subsets of average length k
- O(n) auxiliary space for recursion depth
*/

#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void findSubsets(int ind, vector<int> &nums, vector<int> &curr,vector<vector<int>> &result)
    {
        // Add current subset to result
        result.push_back(curr);

        // Try all possible elements that can be added to current subset
        for (int i = ind; i < nums.size(); i++)
        {
            // Skip duplicates at same level
            if (i > ind && nums[i] == nums[i - 1])
                continue;

            // Include current element
            curr.push_back(nums[i]);

            // Recur for next elements
            findSubsets(i + 1, nums, curr, result);

            // Backtrack by removing current element
            curr.pop_back();
        }
    }

public:
    vector<vector<int>> subsetsWithDup(vector<int> &nums)
    {
        vector<vector<int>> result;
        vector<int> curr;

        // Sort to handle duplicates
        sort(nums.begin(), nums.end());

        findSubsets(0, nums, curr, result);
        return result;
    }
};

// Driver code
int main()
{
    Solution sol;
    vector<int> nums = {1, 2, 2};

    vector<vector<int>> ans = sol.subsetsWithDup(nums);

    // Print results
    cout << "All unique subsets are:\n";
    cout << "[ ";
    for (const auto &subset : ans)
    {
        cout << "[ ";
        for (int num : subset)
        {
            cout << num << " ";
        }
        cout << "] ";
    }
    cout << "]";

    return 0;
}
