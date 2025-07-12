#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Remove Element (LeetCode 27)
// Example: nums = [3,2,2,3], val = 3 → k=2, nums = [2,2,_,_]
// Constraints: 0 <= nums.length <= 100, 0 <= nums[i], val <= 100

// 🔴 Brute Force (Using Extra Space)
// TC: O(n), SC: O(n)
int removeElementBrute(vector<int>& nums, int val) {
    vector<int> temp;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            temp.push_back(nums[i]);
        }
    }
    int k = temp.size();
    for (int i = 0; i < k; i++) {
        nums[i] = temp[i];
    }
    return k;
}

// 🟢 Optimized (Two-Pointer Technique)
// TC: O(n), SC: O(1)
int removeElementOptimized(vector<int>& nums, int val) {
    int k = 0;
    for (int i = 0; i < nums.size(); i++) {
        if (nums[i] != val) {
            nums[k] = nums[i];
            k++;
        }
    }
    return k;
}

int main() {
    vector<int> nums = {3,2,2,3};
    int val = 3;
    cout << "Brute Force: k = " << removeElementBrute(nums, val) << ", nums = ";
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;

    nums = {3,2,2,3}; // Reset array
    cout << "Optimized: k = " << removeElementOptimized(nums, val) << ", nums = ";
    for (int i = 0; i < nums.size(); i++) cout << nums[i] << " ";
    cout << endl;
    return 0;
}
