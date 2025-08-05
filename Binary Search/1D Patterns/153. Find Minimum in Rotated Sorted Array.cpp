#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Given an integer array arr of size N, sorted in ascending order (with distinct values). Now the array is rotated between 1 to N times which is unknown. Find the minimum element in the array. 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :

int BruteForce(vector<int> &arr) {
    int n = arr.size();
    int minVal = INT_MAX;

    for(int i=0; i<n; i++) {
        minVal = min(minVal, arr[i]);
    }
    return minVal;
}

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :
int Optimal(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        
        // if left part is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]); // keep the min
            low = mid + 1; // eliminate left half
        }
        // if right part is sorted
        else
        {
            ans = min(ans, arr[mid]); // keep the min
            high = mid - 1; // eliminate right half
        }
    }
    return ans;
}
// 🟢 Approach 3 Optimal: 
// Intuition :
// Algo :
// TC :
// SC :
int Optimal(vector<int> &arr) {
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if(arr[low] <= arr[high]){
            ans = min(ans, arr[low]); // if the array is not rotated, the first element is the minimum
            break; // exit early since we found the minimum
        }
        
        // if left part is sorted
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]); // keep the min
            low = mid + 1; // eliminate left half
        }
        // if right part is sorted
        else
        {
            ans = min(ans, arr[mid]); // keep the min
            high = mid - 1; // eliminate right half
        }
    }
    return ans;
}
int main()
{
    vector<int> arr = {4, 5, 6, 7, 0, 1, 2, 3, 5};

    int ans = BruteForce(arr);
    cout<<"Brute Force: "<<ans<<endl;

    ans = Optimal(arr);
    cout<<"Optimal: "<<ans<<endl;

    return 0;
}