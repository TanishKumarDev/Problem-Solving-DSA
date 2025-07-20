#include <bits/stdc++.h>
using namespace std;

// Upper Bound: The index of the first element in the array which is strictly greater than x.
// Time Complexity: O(N), where N = size of the given array.
// Reason: In the worst case, we have to travel the whole array. This is basically the time complexity of the linear search algorithm.
// Space Complexity: O(1) as we are using no extra space.
int upperBoundBrute(vector<int> &arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] > x)
        {
            return i; // Return index - upper bound found
        }
    }
    return n; // No element > x found
}

// Upper Bound using Binary Search (Optimal)
// Time Complexity: O(logN), where N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.
// Space Complexity: O(1) as we are using no extra space.
int upperBoundOptimal(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (arr[mid] > x)
        {
            ans = mid;        // Possible upper bound found
            high = mid - 1;   // Try to find smaller index on the left
        }
        else
        {
            low = mid + 1;    // Move right to find element > x
        }
    }

    return ans;
}

// Upper Bound using STL (std::upper_bound)
int upperBoundSTL(vector<int> &arr, int n, int x)
{
    // upper_bound returns iterator to the first element > x
    auto it = upper_bound(arr.begin(), arr.end(), x);
    return it - arr.begin(); // Convert iterator to index
}

int main()
{
    vector<int> arr = {3, 5, 8, 9, 15, 19};
    int n = arr.size();
    int x = 9;

    // Make sure the array is sorted before applying binary search or STL upper_bound
    sort(arr.begin(), arr.end());

    cout << "Upper Bound using Brute Force is at index: " << upperBoundBrute(arr, n, x) << endl;
    cout << "Upper Bound using Binary Search is at index: " << upperBoundOptimal(arr, n, x) << endl;
    cout << "Upper Bound using STL is at index: " << upperBoundSTL(arr, n, x) << endl;

    return 0;
}
