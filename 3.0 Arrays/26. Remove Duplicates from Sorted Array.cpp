#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Brute Force Approach using set
    int removeDuplicatesBrute(vector<int> &nums)
    {
        // Intuition: somehow if we have have something that hold the unique element after make return elements
        // Time Complexity: O(n log n) - because inserting into set takes log n time per element
        // Space Complexity: O(n) - because we're storing all unique elements in a set

        set<int> unique; // Create a set to store unique elements (sets automatically remove duplicates)

        // Step 1: Insert all elements into the set to remove duplicates
        for (int num : nums)
        {
            unique.insert(num); // Duplicates won't be inserted as sets only store unique values
        }

        // Step 2: Copy the unique elements back to the original vector
        int i = 0; // Index for writing back to nums vector
        for (int num : unique)
        {
            nums[i++] = num; // Copy each unique number back to nums
        }

        return unique.size(); // Return the count of unique elements
    }

    // Optimal Two-pointer Approach
    int removeDuplicates(vector<int> &nums)
    {
        // Time Complexity: O(n) - we only pass through the array once
        // Space Complexity: O(1) - we modify the array in-place without extra space

        // Edge case: if array has 0 or 1 elements, it's already unique
        if (nums.size() <= 1)
            return nums.size();

        // Use two pointers:
        // i - slow pointer (points to last unique element)
        // j - fast pointer (scans through the array)
        int i = 0; // Initialize slow pointer

        // Start fast pointer from second element (index 1)
        for (int j = 1; j < nums.size(); j++)
        {
            // When we find a new unique element
            if (nums[j] != nums[i])
            {
                i++;               // Move slow pointer forward
                nums[i] = nums[j]; // Store the new unique element
            }
            // If elements are same, just move j forward (skip duplicates)
        }

        // The number of unique elements is i+1 (since i is 0-based index)
        return i + 1;
    }
};

// Sample test cases to demonstrate the functionality
int main()
{
    Solution sol; // Create an instance of Solution

    // Test case 1: Simple case with duplicates
    vector<int> nums1 = {1, 1, 2};
    int k1 = sol.removeDuplicates(nums1); // Should return 2 (unique elements are [1,2])
    cout << "Test 1: " << k1 << ", [";
    for (int i = 0; i < k1; i++)
        cout << nums1[i] << (i < k1 - 1 ? "," : "");
    cout << "]" << endl;

    // Test case 2: Longer array with multiple duplicates
    vector<int> nums2 = {0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    int k2 = sol.removeDuplicates(nums2); // Should return 5 (unique elements are [0,1,2,3,4])
    cout << "Test 2: " << k2 << ", [";
    for (int i = 0; i < k2; i++)
        cout << nums2[i] << (i < k2 - 1 ? "," : "");
    cout << "]" << endl;

    return 0;
}