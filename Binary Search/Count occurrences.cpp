#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem :
// Example :
// Constraint :

// 🔴 Approach 1 Brute Force :
// Intuition : The approach is simple. We will linearly search the entire array, and try to increase the counter whenever we get the target value in the array. Using a for loop that runs from 0 to n - 1, containing an if the condition that checks whether the value at that index equals target. If true then increase the counter, at last return the counter.

// Algo :

// TC : O(N), N = size of the given array ; We are traversing the whole array
// SC : O(1) as we are not using any extra space.
int bruteForce(vector<int> &arr, int n, int key)
{
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] == key)
        {
            count++; // If the element is found, increment the count
        }
    }
    return count;
}
// 🔵 Approach 2 Better :
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal:
// Intuition : Total number of occurrences = last occurrence - first occurrence + 1

// Algo :
// 1. Find the first occurrence of the target using the firstOccurrence() function.
// 2. Find the last occurrence of the target using the lastOccurrence() function.
// 3. If the first index is -1, return 0 as the target is not in the array.
// 4. Calculate total occurrences as (last index - first index + 1).
// 5. Return the total occurrences.

// TC: O(log n) for firstOccurrence + O(log n) for lastOccurrence = O(log n)
// SC: O(1) as we are using no extra space.
int firstOccurrence(vector<int> &arr, int n, int key)
{
    int low = 0, high = n - 1;
    int first = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            first = mid;    // possible answer
            high = mid - 1; // Move left for earlier occurrence
        }
        else if (arr[mid] < key)
        {
            low = mid + 1; // Go right
        }
        else
        {
            high = mid - 1; // Go left
        }
    }

    return first;
}
int lastOccurrence(vector<int> &arr, int n, int key)
{
    int low = 0, high = n - 1;
    int last = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key)
        {
            last = mid;    // possible answer
            low = mid + 1; // Move right for later occurrence
        }
        else if (arr[mid] < key)
        {
            low = mid + 1; // Go right
        }
        else
        {
            high = mid - 1; // Go left
        }
    }

    return last;
}

pair<int, int> firstAndLastOccurrence(vector<int> &arr, int n, int key)
{
    int first = firstOccurrence(arr, n, key);
    if(first == -1) return {-1, -1};
    int last = lastOccurrence(arr, n, key);
    return {first, last};
}

int countOccurrences(vector<int> &arr, int n, int key)
{
    pair<int, int> ans = firstAndLastOccurrence(arr, n, key);
    if (ans.first == -1)
        return 0;
    return ans.second - ans.first + 1;
}
int main()
{
    vector<int> arr = {2, 4, 6, 8, 8, 8, 11, 13};
    int n = arr.size();
    int key = 8;

    // Ensure the array is sorted before applying binary search
    sort(arr.begin(), arr.end());

    // Brute Force
    cout << "BruteForce: " << bruteForce(arr, n, key) << endl;
    cout << "countOccurrences: " << countOccurrences(arr, n, key) << endl;
    return 0;
}