#include <bits/stdc++.h>
using namespace std;

// TC - O(n), SC - O(1)
class Solution {
public:
    int countSubarrays(vector<int>& nums) {
        int n = nums.size(); // Size of the array
        int count = 0;       // To store the count of valid subarrays
    
        // Loop to check each valid triplet
        for (int i = 1; i < n - 1; i++) {
            // Check if the middle element is even and sum of first and third element is half of middle element
            if (nums[i] % 2 == 0 && (nums[i-1] + nums[i+1]) == (nums[i]/2)) {
                count++;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 1, 4, 1}; // Example input
    cout << sol.countSubarrays(nums) << endl; // Output the result
    return 0;
}
