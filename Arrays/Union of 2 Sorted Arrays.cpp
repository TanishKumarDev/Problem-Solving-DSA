#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1: Using Map
vector<int> unionMap(vector<int>& arr1, vector<int>& arr2) {
    map<int, int> mp;
    for (int x : arr1) mp[x]++;
    for (int x : arr2) mp[x]++;
    vector<int> result;
    for (auto& p : mp) {
        result.push_back(p.first);
    }
    return result;
}

// 🟡 Approach 2: Using Set
vector<int> unionSet(vector<int>& arr1, vector<int>& arr2) {
    set<int> s;
    for (int x : arr1) s.insert(x);
    for (int x : arr2) s.insert(x);
    vector<int> result(s.begin(), s.end());
    return result;
}

// 🟢 Approach 3: Two Pointers
vector<int> unionTwoPointers(vector<int>& arr1, vector<int>& arr2) {
    int n = arr1.size(), m = arr2.size();
    vector<int> result;
    int i = 0, j = 0;
    while (i < n && j < m) {
        if (arr1[i] == arr2[j]) {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++; j++;
        } else if (arr1[i] < arr2[j]) {
            if (result.empty() || result.back() != arr1[i]) {
                result.push_back(arr1[i]);
            }
            i++;
        } else {
            if (result.empty() || result.back() != arr2[j]) {
                result.push_back(arr2[j]);
            }
            j++;
        }
    }
    while (i < n) {
        if (result.empty() || result.back() != arr1[i]) {
            result.push_back(arr1[i]);
        }
        i++;
    }
    while (j < m) {
        if (result.empty() || result.back() != arr2[j]) {
            result.push_back(arr2[j]);
        }
        j++;
    }
    return result;
}

int main() {
    vector<int> arr1 = {1,2,3,4,5,6,7,8,9,10};
    vector<int> arr2 = {2,3,4,4,5,11,12};
    auto result = unionTwoPointers(arr1, arr2);
    // Print result (omitted for brevity)
    return 0;
}
