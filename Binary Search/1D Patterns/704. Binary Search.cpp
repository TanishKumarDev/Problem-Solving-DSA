#include <bits/stdc++.h>
using namespace std;

/*
🧠 Binary Search Intuition:
"Divide and Conquer — har baar half elements discard karo."

Sorted array → use this logic:
- If target > mid → go right
- If target < mid → go left
- If target == mid → found!
*/

// 📌 Iterative Approach
int binarySearchIterative(vector<int>& nums, int target) {
    int low = 0, high = nums.size() - 1;

    while (low <= high) {
        int mid = low + (high - low) / 2; // Avoids overflow
        if (nums[mid] == target)
            return mid;
        else if (target > nums[mid])
            low = mid + 1;
        else
            high = mid - 1;
    }

    return -1; // Not found
}

// 📌 Recursive Approach
int binarySearchRecursive(vector<int>& nums, int target, int low, int high) {
    if (low > high) return -1; // Base case

    int mid = low + (high - low) / 2;

    if (nums[mid] == target)
        return mid;
    else if (target > nums[mid])
        return binarySearchRecursive(nums, target, mid + 1, high);
    else
        return binarySearchRecursive(nums, target, low, mid - 1);
}

// Main function to test both versions
int main() {
    vector<int> a = {3, 4, 6, 7, 9, 12, 16, 17};
    int target = 3;

    // Initialize both versions
    int indexRecursive = binarySearchRecursive(a, target, 0, a.size() - 1);
    int indexIterative = binarySearchIterative(a, target);

    cout << "Iterative Result: ";
    if (indexIterative == -1)
        cout << "Not Found" << endl;
    else
        cout << "Found at index: " << indexIterative << endl;

    cout << "Recursive Result: ";
    if (indexRecursive == -1)
        cout << "Not Found" << endl;
    else
        cout << "Found at index: " << indexRecursive << endl;

    return 0;
}
