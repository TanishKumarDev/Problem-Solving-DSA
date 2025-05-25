#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    /*  
    // Approach 1: Sorting (Sort array and return last element)
    
    Intuition:
    - Sort the array in ascending order.
    - The largest element will be at the last index.

    Time: O(n log n) - due to sorting.
    Space: O(1) - in-place sorting (or O(n) in some implementations).
    */
    int findLargestSorting(vector<int>& arr) {
        // vector<int> temp = arr; // Copy to avoid modifying original array
        sort(arr.begin(), arr.end()); // Sort in ascending order
        return arr[arr.size() - 1]; // Return last element
    }

    /*
    // Approach 2: Max Variable (Track largest element in one pass)
    Intuition:
    - Keep a variable to track the largest number seen.
    - Update it whenever a larger number is found.
    
    Time: O(n) - single pass through the array.
    Space: O(1) - only one variable used.
    */
    int findLargestMaxVar(vector<int>& arr) {
        int max = arr[0]; // Initialize with first element
        for (int i = 0; i < arr.size(); i++) {
            if (arr[i] > max) {
                max = arr[i]; // Update max if current element is larger
            }
        }
        return max;
    }
};

int main() {
    Solution sol;
    // Test cases
    vector<int> arr1 = {2, 5, 1, 3, 0};
    vector<int> arr2 = {8, 10, 5, 7, 9};

    // Test Approach 1: Sorting
    cout << "Array 1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nLargest element (Sorting): " << sol.findLargestSorting(arr1) << endl;

    cout << "Array 2: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nLargest element (Sorting): " << sol.findLargestSorting(arr2) << endl;

    // Test Approach 2: Max Variable
    cout << "\nArray 1: ";
    for (int x : arr1) cout << x << " ";
    cout << "\nLargest element (Max Variable): " << sol.findLargestMaxVar(arr1) << endl;

    cout << "Array 2: ";
    for (int x : arr2) cout << x << " ";
    cout << "\nLargest element (Max Variable): " << sol.findLargestMaxVar(arr2) << endl;

    return 0;
}
