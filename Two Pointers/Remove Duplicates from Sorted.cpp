#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Remove Duplicates from Sorted Array
// Example : [1,1,2,2,3] -> [1,2,3]
// Constraint : Must modify the input array in-place, O(1) extra space

// 🔴 Approach 1 Brute Force :
// Intuition : Use set to store unique sorted elements
// Algo : Put unique elements in set, overwrite original array
// TC : O(n log n)
// SC : O(n)
int removeDuplicates_brute(vector<int> &nums)
{
    if (nums.size() == 0)
        return 0;

    set<int> unique(nums.begin(), nums.end());

    int i = 0;
    for (int val : unique)
    {
        nums[i++] = val;
    }

    return unique.size();
}

// 🟢 Approach 2 Optimal:
// Intuition : Two-pointer — compare current and previous unique element
// Algo : Keep one pointer for writing, one for reading
// TC : O(n)
// SC : O(1)
int removeDuplicates_optimal(vector<int> &nums)
{
    int n = nums.size();

    if (n < 1)
        return 0;

    int i = 0; // points to last unique element

    for (int j = 1; j < n; j++)
    {
        if (nums[j] != nums[i])
        {
            i++;               // move to next unique position
            nums[i] = nums[j]; // overwrite duplicate
        }
    }

    return i + 1; // length of array with unique elements
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    // Call the desired function:
    // int newLength = removeDuplicates_brute(arr);
    int newLength = removeDuplicates_optimal(arr);

    cout << newLength << endl;
    cout << "Modified array: ";
    for (int i = 0; i < newLength; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

// Example input:
// 7
// 1 1 2 2 3 3 4
// Example output:
// 4
// Modified array: 1 2 3 4