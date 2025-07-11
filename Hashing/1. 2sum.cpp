#include <bits/stdc++.h>
using namespace std;

// Variety 1 - Return true/false if any pair exists with sum = target
// Variety 2 - Return the indices of the two elements

// 🔴 Brute Force (Variation 1): Check all pairs (i, j)
// TC: O(n^2), SC: O(1)
bool twoSumBruteV1(vector<int>& arr, long long target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue; // Avoid same element twice
            if ((long long)arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}

// 🔴 Brute Force (Variation 2): 
// TC: O(n^2), SC: O(1)
vector<int> twoSumBruteV2(vector<int>& arr, long long target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i == j) continue;
            if ((long long)arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// 🟡 Better Brute (Variation 1): Start inner loop from i+1 to avoid duplicate and self-pairs
// TC: O(n^2), SC: O(1)
bool twoSumBetterV1(vector<int>& arr, long long target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)arr[i] + arr[j] == target) {
                return true;
            }
        }
    }
    return false;
}

// 🟡 Better Brute (Variation 2): Return indices using improved inner loop
// TC: O(n^2), SC: O(1)
vector<int> twoSumBetterV2(vector<int>& arr, long long target) {
    int n = arr.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((long long)arr[i] + arr[j] == target) {
                return {i, j};
            }
        }
    }
    return {};
}

// 🟢 Optimal Using HashMap (Variation 1): Checks if the complement (target - arr[i]) exists
// TC: O(n) on average, SC: O(n)
bool twoSumHashingV1(vector<int>& arr, long long target) {
    int n = arr.size();
    unordered_map<long long, int> mp;

    for (int i = 0; i < n; i++) {
        long long more = target - arr[i];
        if (mp.find(more) != mp.end()) {
            return true;
        }
        mp[arr[i]] = i;
    }
    return false;
}

// 🟢 Optimal Using HashMap (Variation 2): Return indices of two numbers that sum to target
// TC: O(n) on average, SC: O(n)
vector<int> twoSumHashingV2(vector<int>& arr, long long target) {
    int n = arr.size();
    unordered_map<long long, int> mp;

    for (int i = 0; i < n; i++) {
        long long more = target - arr[i];
        if (mp.find(more) != mp.end()) {
            return {mp[more], i}; // Return previously seen index and current index
        }
        mp[arr[i]] = i;
    }
    return {};
}

// 🟢 Two Pointer Approach (Only if array is sorted or used on a copied sorted array)
// Only tells if such a pair exists — not the original indices
// TC: O(n log n) for sorting + O(n), SC: O(n) (if copy is used)
bool twoSumSortingV1(vector<int>& arr, long long target) {
    int n = arr.size();
    vector<int> temp = arr; // Copy to preserve original order
    sort(temp.begin(), temp.end());

    int left = 0, right = n - 1;

    while (left < right) {
        long long sum = (long long)temp[left] + temp[right];
        if (sum == target) {
            return true;
        }
        else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

// 🔍 Driver Code
int main() {
    vector<int> arr = {2, 6, 5, 8, 11};
    long long target = 14;

    cout << "Brute V1: " << (twoSumBruteV1(arr, target) ? "Yes" : "No") << endl;

    vector<int> res1 = twoSumBruteV2(arr, target);
    cout << "Brute V2: [" << res1[0] << ", " << res1[1] << "]" << endl;

    cout << "Better V1: " << (twoSumBetterV1(arr, target) ? "Yes" : "No") << endl;

    vector<int> res2 = twoSumBetterV2(arr, target);
    cout << "Better V2: [" << res2[0] << ", " << res2[1] << "]" << endl;

    cout << "Hashing V1: " << (twoSumHashingV1(arr, target) ? "Yes" : "No") << endl;

    vector<int> res3 = twoSumHashingV2(arr, target);
    cout << "Hashing V2: [" << res3[0] << ", " << res3[1] << "]" << endl;

    cout << "Sorting V1: " << (twoSumSortingV1(arr, target) ? "Yes" : "No") << endl;

    return 0;
}

// 🚫 Why Two-Pointer Works Only for Variety 1
// ✅ Works perfectly to check if a pair exists. ❌ But you lose the original indices after sorting! So you can’t return [i, j] of original array unless you store index mapping, which complicates things.