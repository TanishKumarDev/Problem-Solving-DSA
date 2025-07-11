#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Sort Colors
// Given an array nums with n objects colored red (0), white (1), or blue (2),
// sort them in-place so that objects of the same color are adjacent, with the order red, white, and blue.

// Example : 
// Input: nums = [2,0,2,1,1,0]
// Output: [0,0,1,1,2,2]

// Constraint : 
// - n == nums.length
// - 1 <= n <= 300
// - nums[i] is either 0, 1, or 2.

// 🔴 Approach 1 Brute Force : Sorting
// Intuition :
// Use the built-in sort function to arrange the array in ascending order, which naturally groups 0s, 1s, and 2s.

// Algo :
// 1. Call the sort function on the array from begin to end.

// TC : O(n log n) — due to the sorting algorithm.
// SC : O(n) or O(log n) — depends on the sort implementation (e.g., temporary space or recursion stack).

void sortColorsBrute(vector<int>& arr) {
    sort(arr.begin(), arr.end());
}

// 🔵 Approach 2 Better : Counting
// Intuition :
// Count the frequency of 0s, 1s, and 2s, then overwrite the array with 0s, 1s, and 2s in order.
// Requires two passes but is more efficient than sorting for this specific problem.

// Algo :
// 1. Initialize counters for 0s, 1s, and 2s.
// 2. Iterate through the array to count frequencies.
// 3. Overwrite the array: first all 0s, then all 1s, then all 2s.

// TC : O(n) — two passes through the array (counting + overwriting).
// SC : O(1) — only three counters used.

void sortColorsBetter(vector<int>& nums) {
    int count0 = 0, count1 = 0, count2 = 0;
    for (int num : nums) {
        if (num == 0) count0++;
        else if (num == 1) count1++;
        else count2++;
    }
    int i = 0;
    while (count0--) nums[i++] = 0;
    while (count1--) nums[i++] = 1;
    while (count2--) nums[i++] = 2;
}

// 🟢 Approach 3 Optimal: Dutch National Flag
// Intuition :
// Use three pointers to partition the array in one pass. Elements before 'low' are 0s, between 'low' and 'mid' are 1s, and after 'high' are 2s.

// Algo :
// 1. Initialize low = 0, mid = 0, high = n-1.
// 2. While mid <= high:
//    - If nums[mid] == 0: swap with nums[low], increment low and mid.
//    - If nums[mid] == 1: increment mid.
//    - If nums[mid] == 2: swap with nums[high], decrement high.

// TC : O(n) — single pass through the array.
// SC : O(1) — only three pointers used.

void sortColorsOptimal(vector<int>& nums) {
    int low = 0, mid = 0, high = nums.size() - 1;
    while (mid <= high) {
        if (nums[mid] == 0) {
            swap(nums[low], nums[mid]);
            low++;
            mid++;
        } else if (nums[mid] == 1) {
            mid++;
        } else {
            swap(nums[mid], nums[high]);
            high--;
        }
    }
}

int main()
{
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = nums; // Copy for testing counting approach
    vector<int> nums3 = nums; // Copy for testing optimal approach

    cout << "Brute Force (Sorting) Result: ";
    sortArrayBrute(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Better (Counting) Result: ";
    sortColorsCounting(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Optimal (Dutch National Flag) Result: ";
    sortColorsOptimal(nums3);
    for (int num : nums3) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}