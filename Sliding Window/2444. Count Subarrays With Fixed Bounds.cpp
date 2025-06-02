#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// === Approach 1: Brute Force ===
// Intuition: Check every possible subarray and verify if its min = minK and max = maxK.
// Algorithm:
//   1. Iterate over all possible subarray start indices (i).
//   2. For each start index, iterate over end indices (j >= i).
//   3. Compute min and max of subarray [i,j].
//   4. If min == minK and max == maxK, increment count.
//   5. Return total count.
// Time Complexity: O(n^2 * log n) in worst case, where n is array size (O(n^2) subarrays, O(log n) for min/max via sorting or iteration).
// Space Complexity: O(1), excluding input storage.
// Use: Simple but inefficient for large arrays; useful for understanding the problem.
long long countSubarraysBrute(vector<int>& nums, int minK, int maxK) {
    long long count = 0;
    int n = nums.size();
    
    for (int i = 0; i < n; i++) {
        int min_val = nums[i];
        int max_val = nums[i];
        for (int j = i; j < n; j++) {
            min_val = min(min_val, nums[j]);
            max_val = max(max_val, nums[j]);
            if (min_val == minK && max_val == maxK) {
                count++;
            }
        }
    }
    
    return count;
}

// === Approach 2: Optimal (Sliding Window) ===
// Intuition: Track the most recent positions of minK, maxK, and invalid elements (< minK or > maxK) to count valid subarrays ending at each index.
// Algorithm:
//   1. Initialize:
//      - ans: Total count of valid subarrays (long long).
//      - minK_pos: Last index where nums[i] == minK (-1 initially).
//      - maxK_pos: Last index where nums[i] == maxK (-1 initially).
//      - culprit_idx: Last index of invalid element (< minK or > maxK) (-1 initially).
//   2. Iterate through array (i from 0 to n-1):
//      - If nums[i] < minK or nums[i] > maxK, update culprit_idx = i.
//      - If nums[i] == minK, update minK_pos = i.
//      - If nums[i] == maxK, update maxK_pos = i.
//      - Compute smaller_idx = min(minK_pos, maxK_pos).
//      - Compute temp = smaller_idx - culprit_idx (number of valid subarrays ending at i).
//      - If temp > 0, add temp to ans.
//   3. Return ans.
// Time Complexity: O(n), where n is array size (single pass).
// Space Complexity: O(1), uses only a few variables.
// Use: Efficient for large arrays, handles all edge cases.
long long countSubarraysOptimal(vector<int>& nums, int minK, int maxK) {
    long long ans = 0;
    int minK_pos = -1;   // Last position of minK
    int maxK_pos = -1;   // Last position of maxK
    int culprit_idx = -1; // Last position of invalid element
    
    for (int i = 0; i < nums.size(); i++) {
        // Update culprit_idx for invalid elements
        if (nums[i] < minK || nums[i] > maxK) {
            culprit_idx = i;
        }
        // Update minK position
        if (nums[i] == minK) {
            minK_pos = i;
        }
        // Update maxK position
        if (nums[i] == maxK) {
            maxK_pos = i;
        }
        // Compute smaller index of minK_pos and maxK_pos
        int smaller_idx = min(minK_pos, maxK_pos);
        // Count valid subarrays ending at i
        long long temp = smaller_idx - culprit_idx;
        // Add to answer if valid subarrays exist
        if (temp > 0) {
            ans += temp;
        }
    }
    
    return ans;
}

int main() {
    // Input array size
    cout << "Enter array size: ";
    int n;
    cin >> n;
    
    // Input array elements
    vector<int> nums(n);
    cout << "Enter " << n << " array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> nums[i];
    }
    
    // Input minK and maxK
    cout << "Enter minK: ";
    int minK;
    cin >> minK;
    cout << "Enter maxK: ";
    int maxK;
    cin >> maxK;
    
    // Output results
    cout << "Brute Force: " << countSubarraysBrute(nums, minK, maxK) << endl;
    cout << "Optimal (Sliding Window): " << countSubarraysOptimal(nums, minK, maxK) << endl;
    
    return 0;
}