#include <bits/stdc++.h>
using namespace std;

// 🧠 Brute Force Approach
// T.C: O(n^3) — Try every subarray, count pairs
// S.C: O(1)
int bruteCountGood(vector<int>& nums, int k) {
    int n = nums.size();
    int res = 0;

    for (int i = 0; i < n; ++i) {
        unordered_map<int, int> freq;
        int pairs = 0;

        for (int j = i; j < n; ++j) {
            pairs += freq[nums[j]];
            freq[nums[j]]++;
            if (pairs >= k) res++;
        }
    }

    return res;
}

// ⚡ Optimal Sliding Window + HashMap
// T.C: O(n)
// S.C: O(n)
long long optimalCountGood(vector<int>& nums, int k) {
    int n = nums.size();
    int i = 0, j = 0;
    long long result = 0, pairs = 0;

    unordered_map<int, int> mp;

    while (j < n) {
        pairs += mp[nums[j]];
        mp[nums[j]]++;

        while (pairs >= k) {
            result += (n - j); // All subarrays ending at j are valid
            mp[nums[i]]--;
            pairs -= mp[nums[i]];
            i++;
        }

        j++;
    }

    return result;
}

// 🧪 Driver Function
int main() {
    vector<int> nums1 = {1,1,1,1,1};
    int k1 = 10;

    vector<int> nums2 = {3,1,4,3,2,2,4};
    int k2 = 2;

    cout << "🧪 Test Case 1:\n";
    cout << "Brute: " << bruteCountGood(nums1, k1) << endl;
    cout << "Optimal: " << optimalCountGood(nums1, k1) << endl;

    cout << "\n🧪 Test Case 2:\n";
    cout << "Brute: " << bruteCountGood(nums2, k2) << endl;
    cout << "Optimal: " << optimalCountGood(nums2, k2) << endl;

    return 0;
}
