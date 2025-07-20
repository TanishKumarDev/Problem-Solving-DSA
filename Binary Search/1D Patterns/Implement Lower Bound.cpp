#include <bits/stdc++.h>
using namespace std;

// Lower Bound: The index of the first element in the array which is greater than or equal to x.
int lowerBoundBrute(vector<int> &arr, int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (arr[i] >= x)
        {
            return i; // Return index - lower bound found
        }
    }
    return n;
}

int lowerBoundOptimal(vector<int> &arr, int n, int x)
{
    int low = 0, high = n - 1;
    int ans = n;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        // Maybe this is answer but not sure
        if (arr[mid] >= x)
        {
            ans = mid;
            high = mid - 1; // Look for smaller index on left side
        }
        else
        {
            low = mid + 1; // Look for bigger index on right
        }
    }

    return ans;
}

// STL-based approach using std::lower_bound
int lowerBoundSTL(vector<int> &arr, int n, int x)
{
    // lower_bound returns iterator to the first element >= x
    auto it = lower_bound(arr.begin(), arr.end(), x);
    return it - arr.begin(); // Convert iterator to index
}

int main()
{
    vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();
    int x = 9;

    // Ensure elements are in sorted order for binary search
    sort(arr.begin(), arr.end());


    cout << "Lower Bound using Brute Force is at index: " << lowerBoundBrute(arr, n, x) << endl;
    cout << "Lower Bound using Binary Search is at index: " << lowerBoundOptimal(arr, n, x) << endl;
    cout << "Lower Bound using STL is at index: " << lowerBoundSTL(arr, n, x) << endl;
    return 0;
}
