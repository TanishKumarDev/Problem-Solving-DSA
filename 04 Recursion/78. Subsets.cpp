/*
Problem: Given an integer array nums of unique elements, return all possible subsets (the power set).
The solution set must not contain duplicate subsets. Return the solution in any order.

Intuition:
- For each element, we have 2 choices: include it in sum or exclude it
- Use recursion to try all combinations
- Base case: when we reach end of array, add current sum to result

Algorithm:
1. Create recursive function that takes current index, array, and running sum
2. At each step:
   - Include current element in sum and recurse
   - Exclude current element and recurse
3. When reaching end of array, add sum to result
4. Sort final result array

Time Complexity: O(2^n) + O(2^n log(2^n))
- O(2^n) for generating all subsets
- O(2^n log(2^n)) for sorting result array

Space Complexity: O(2^n)
- To store all possible subset sums
*/

#include <bits/stdc++.h>
using namespace std;

// Function to find all subset sums
void findSubsetSums(int index, vector<int>& arr, int n, vector<int>& result, int currentSum) {
    // Base case: when we reach end of array, add current sum to result
    if (index == n) {
        result.push_back(currentSum);
        return;
    }
    
    // Include current element
    findSubsetSums(index + 1, arr, n, result, currentSum + arr[index]);
    
    // Exclude current element
    findSubsetSums(index + 1, arr, n, result, currentSum);
}

// Main function to generate and return sorted subset sums
vector<int> getAllSubsetSums(vector<int>& arr) {
    vector<int> result;
    findSubsetSums(0, arr, arr.size(), result, 0);
    sort(result.begin(), result.end());
    return result;
}

int main() {
    // Test cases
    vector<vector<int>> testCases = {
        {5, 2, 1},
        {3, 1, 2}
    };
    
    // Process each test case
    for (int i = 0; i < testCases.size(); i++) {
        cout << "Test Case " << i + 1 << ":" << endl;
        cout << "Input array: ";
        for (int num : testCases[i]) {
            cout << num << " ";
        }
        cout << endl;
        
        // Get subset sums
        vector<int> sums = getAllSubsetSums(testCases[i]);
        
        // Print results
        cout << "Subset sums: ";
        for (int sum : sums) {
            cout << sum << " ";
        }
        cout << endl << endl;
    }
    
    return 0;
}
