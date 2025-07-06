#include <bits/stdc++.h>
using namespace std;

//
// ✅ Problem:
// Find the Second Largest and Second Smallest elements in an array.
//
// Example:
// Input: [4, 2, 7, 7, 3, 1]
// Output: Second Largest = 4, Second Smallest = 2
//

// 🔴 Approach 1: Brute Force
// ---------------------------
// Intuition:
// → Sort the array and pick second unique largest and smallest
//
// Algorithm:
// → Sort the array
// → Second Largest = Traverse from end to find first different from max
// → Second Smallest = Traverse from start to find first different from min
//
// Time: O(n log n)
// Space: O(1)

vector<int> secondOrderBrute(vector<int>& arr, int n) {
    sort(arr.begin(), arr.end());

    int largest = arr[n-1];
    int second_largest = -1;
    for (int i = n-2; i >= 0; i--) {
        if (arr[i] != largest) {
            second_largest = arr[i];
            break;
        }
    }

    int second_smallest = INT_MAX;
    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[0]) {
            second_smallest = arr[i];
            break;
        }
    }

    return {second_largest, second_smallest};
}

// 🔵 Approach 2: Better (Two Pass)
// --------------------------------
// Intuition:
// → Find largest and smallest in 1st pass
// → Find second largest and second smallest in 2nd pass
//
// Time: O(2n) → O(n)
// Space: O(1)

vector<int> secondOrderBetter(vector<int>& arr, int n) {
    int largest = arr[0], smallest = arr[0];

    for (int i = 1; i < n; i++) {
        if (arr[i] > largest) largest = arr[i];
        if (arr[i] < smallest) smallest = arr[i];
    }

    int second_largest = -1;
    int second_smallest = INT_MAX;

    for (int i = 0; i < n; i++) {
        if (arr[i] != largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }
        if (arr[i] != smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
    }

    return {second_largest, second_smallest};
}

// 🟢 Approach 3: Optimal (One Pass)
// ----------------------------------
// Intuition:
// → Find everything in 1 traversal using proper conditions
//
// Time: O(n)
// Space: O(1)

vector<int> secondOrderOptimal(vector<int>& arr, int n) {
    int largest = arr[0], second_largest = -1;
    int smallest = arr[0], second_smallest = INT_MAX;

    for (int i = 1; i < n; i++) {
        // Handle largest and second largest
        if (arr[i] > largest) {
            second_largest = largest;
            largest = arr[i];
        } else if (arr[i] < largest && arr[i] > second_largest) {
            second_largest = arr[i];
        }

        // Handle smallest and second smallest
        if (arr[i] < smallest) {
            second_smallest = smallest;
            smallest = arr[i];
        } else if (arr[i] > smallest && arr[i] < second_smallest) {
            second_smallest = arr[i];
        }
    }

    return {second_largest, second_smallest};
}

//
// 🔍 Main Function: Test All Approaches
//
int main() {
    vector<int> arr = {4, 2, 7, 7, 3, 1};
    int n = arr.size();

    auto brute = secondOrderBrute(arr, n);
    cout << "Brute Force     → Second Largest: " << brute[0] << ", Second Smallest: " << brute[1] << endl;

    auto better = secondOrderBetter(arr, n);
    cout << "Better (2-pass) → Second Largest: " << better[0] << ", Second Smallest: " << better[1] << endl;

    auto optimal = secondOrderOptimal(arr, n);
    cout << "Optimal (1-pass)→ Second Largest: " << optimal[0] << ", Second Smallest: " << optimal[1] << endl;

    return 0;
}
