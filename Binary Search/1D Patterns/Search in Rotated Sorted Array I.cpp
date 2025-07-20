#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Given an integer array arr of size N, sorted in ascending order (with distinct values) and a target value k. Now the array is rotated at some pivot point unknown to you. Find the index at which k is present and if k is not present return -1.
// Example :
// Constraint :

// 🔴 Approach 1 Brute Force :

// Intuition :Linear search algorithm.
// Using this method, we will traverse the array to find the location of the target value. If it is found we will simply return the index and otherwise, we will return -1.

// Algo :

// 1. We will traverse the array and check every element if it is equal to k. If we find any element, we will return its index.
// 2. Otherwise, we will return -1.

// TC : O(N), N = size of the given array.
// SC : O(1) We have not used any extra data structures, this makes space complexity, even in the worst case as O(1).
int BruteForce(vector<int> &arr, int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == k)
        {
            return i;
        }
    }
    return -1;
}
// 🔵 Approach 2 Better : Modified Binary Search

// Intuition :
// The array is sorted but rotated at some pivot →
// So although it’s not fully sorted, either the left half or the right half
// will always be sorted at every step of binary search.

// We can use this property to eliminate half the search space in each step.

// Algo :
// 1. Set low = 0, high = n - 1
// 2. While low <= high:
//    - mid = (low + high)/2
//    - If arr[mid] == key → return mid
//    - Check which half is sorted:
//        - If arr[low] <= arr[mid], then left half is sorted
//           - If key lies in left half → high = mid - 1
//           - Else → low = mid + 1
//        - Else → right half is sorted
//           - If key lies in right half → low = mid + 1
//           - Else → high = mid - 1
// 3. If not found, return -1

// TC : O(log n) → because we’re reducing the search space by half each time
// SC : O(1) → iterative binary search uses constant space
int optimal(vector<int> &arr, int n, int k)
{
    int low = 0, high = n - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        // If mid points to the target
        if (arr[mid] == k)
        {
            return mid; // Key found
        }

        // If left part is sorted
        if (arr[low] <= arr[mid])
        {
            if (arr[low] <= k && k <= arr[mid])
            {
                high = mid - 1; // Key lies in left half
            }
            else
            {
                low = mid + 1; // Key lies in right half
            }
        }

        // Else right part must be sorted
        else if (arr[mid] <= arr[high])
        {
            if (arr[mid] <= k && k <= arr[high])
            {
                low = mid + 1; // Key lies in right half
            }
            else
            {
                high = mid - 1; // Key lies in left half
            }
        }
    }

    return -1; // Element not found
}

// 🟢 Approach 3 Optimal:
// Intuition :
// Algo :
// TC :
// SC :

int main()
{
    vector<int> arr = {7, 8, 9, 1, 2, 3, 4, 5, 6};
    int n = arr.size();
    int k = 5;
    cout << "Brute Force: " << endl;
    int ans = BruteForce(arr, n, k);
    if (ans == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index " << ans << endl;
    }

    // Optimal
    cout << "Optimal: " << endl;
    int ans = optimal(arr, n, k);
    if (ans == -1)
    {
        cout << "Element not found" << endl;
    }
    else
    {
        cout << "Element found at index " << ans << endl;
    }
    return 0;
}