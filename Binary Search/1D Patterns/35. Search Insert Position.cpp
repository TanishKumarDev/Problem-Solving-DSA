#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: : Lower Bound
/*
👉 Why Lower Bound?

Lower Bound gives you:
    - The first index where element is ≥ target
    - So even if the target is not found, it gives the correct insertion position
    - That’s exactly what the problem asks for.
*/
// Intuition : Use lower_bound() to get the first index where target could go (or already exists) while maintaining order.

// Algo :

// TC : O(logN), where N = size of the given array.
// Reason: We are basically using the Binary Search algorithm.

// SC : O(1) as we are using no extra space.
int insertPosition_LB(vector<int> &arr, int n, int x)
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
int main()
{
     vector<int> arr = {3, 5, 8, 15, 19};
    int n = arr.size();
    int x = 9;

    // Make sure the array is sorted before applying binary search or STL upper_bound
    sort(arr.begin(), arr.end());

    cout << "Upper Bound using Brute Force is at index: " << insertPosition_LB(arr, n, x) << endl;
    
    return 0;
}