#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🟢 Approach Optimal: 
// Intuition : We need to find the maximum length of subarray with all 1's
// Algo : We can use a simple linear scan to count the length of consecutive 1's
// TC : O(n)
// SC : O(1)
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int maxi = 0, count = 0;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                count++;
                maxi = max(maxi, count);
            } else {
                count = 0;
            }
        }

        return maxi;
    }
};
int main()
{
    
    return 0;
}