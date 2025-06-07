#include <bits/stdc++.h>
using namespace std;

bool existsSubsequence(int ind, int sum, int K, vector<int>& arr) {
    if (ind == arr.size()) {
        return sum == K;
    }

    // Choice 1: pick the current element
    if (existsSubsequence(ind + 1, sum + arr[ind], K, arr)) {
        return true;
    }

    // Choice 2: skip the current element
    if (existsSubsequence(ind + 1, sum, K, arr)) {
        return true;
    }

    return false;
}

bool hasSubsequenceWithSumK(vector<int>& arr, int K) {
    return existsSubsequence(0, 0, K, arr);
}

int main() {
    vector<int> arr = {1, 2, 3};
    int K = 5;

    if (hasSubsequenceWithSumK(arr, K)) {
        cout << "Yes, there exists a subsequence with sum " << K << endl;
    } else {
        cout << "No subsequence with sum " << K << " found." << endl;
    }

    return 0;
}
