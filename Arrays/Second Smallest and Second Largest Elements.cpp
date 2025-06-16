#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Approach 1: Sorting (Sort and pick second elements)
    /*
    Intuition:
    - Sort the array in ascending order.
    - Second smallest is at index 1, second largest at index n-2.
    Time: O(n log n) - due to sorting.
    Space: O(n) - for copying the array to avoid modifying original.
    */
    pair<int, int> findSecondElementsSorting(vector<int>& arr) {
        int n = arr.size();
        // Edge case: if n < 2, no second smallest/largest exists
        if(n==0 || n==1)
        cout<<-1<<" "<<-1<<endl;  // edge case when only one element is present in array
        
        vector<int> temp = arr; // Copy to avoid modifying original
        sort(temp.begin(), temp.end()); // Sort in ascending order
        
        // If all elements are same, no second smallest/largest
        if (temp[0] == temp[n-1]) return {-1, -1};
        
        return {temp[1], temp[n-2]}; // Second smallest, second largest
    }

    // Approach 2: Single Pass (Track smallest and largest pairs)
    /*
    Intuition:
    - Use variables to track smallest, second smallest, largest, second largest.
    - Update them in one loop based on comparisons.
    Time: O(n) - single pass through the array.
    Space: O(1) - only four variables used.
    */
    pair<int, int> findSecondElementsSinglePass(vector<int>& arr) {
        int n = arr.size();
        // Edge case: if n < 2, no second smallest/largest exists
        if (n < 2) return {-1, -1};
        
        int smallest = INT_MAX, second_smallest = INT_MAX;
        int largest = INT_MIN, second_largest = INT_MIN;
        
        for (int i = 0; i < n; i++) {
            // Update smallest and second smallest
            if (arr[i] < smallest) {
                second_smallest = smallest;
                smallest = arr[i];
            } else if (arr[i] < second_smallest && arr[i] != smallest) {
                second_smallest = arr[i];
            }
            // Update largest and second largest
            if (arr[i] > largest) {
                second_largest = largest;
                largest = arr[i];
            } else if (arr[i] > second_largest && arr[i] != largest) {
                second_largest = arr[i];
            }
        }
        
        // If no second smallest/largest (e.g., all same elements)
        if (second_smallest == INT_MAX || second_largest == INT_MIN) {
            return {-1, -1};
        }
        
        return {second_smallest, second_largest};
    }
};

int main() {
    Solution sol;
    // Test cases
    vector<int> arr1 = {1, 2, 4, 6, 7, 5};
    vector<int> arr2 = {8, 10, 5, 7, 9};
    vector<int> arr3 = {3, 3, 3}; // Edge case: all same elements

    // Test Approach 1: Sorting
    cout << "Array 1: ";
    for (int x : arr1) cout << x << " ";
    auto result1 = sol.findSecondElementsSorting(arr1);
    cout << "\nSorting - Second smallest: " << result1.first << ", Second largest: " << result1.second << endl;

    cout << "Array 2: ";
    for (int x : arr2) cout << x << " ";
    result1 = sol.findSecondElementsSorting(arr2);
    cout << "\nSorting - Second smallest: " << result1.first << ", Second largest: " << result1.second << endl;

    cout << "Array 3: ";
    for (int x : arr3) cout << x << " ";
    result1 = sol.findSecondElementsSorting(arr3);
    cout << "\nSorting - Second smallest: " << result1.first << ", Second largest: " << result1.second << endl;

    // Test Approach 2: Single Pass
    cout << "\nArray 1: ";
    for (int x : arr1) cout << x << " ";
    auto result2 = sol.findSecondElementsSinglePass(arr1);
    cout << "\nSingle Pass - Second smallest: " << result2.first << ", Second largest: " << result2.second << endl;

    cout << "Array 2: ";
    for (int x : arr2) cout << x << " ";
    result2 = sol.findSecondElementsSinglePass(arr2);
    cout << "\nSingle Pass - Second smallest: " << result2.first << ", Second largest: " << result2.second << endl;

    cout << "Array 3: ";
    for (int x : arr3) cout << x << " ";
    result2 = sol.findSecondElementsSinglePass(arr3);
    cout << "\nSingle Pass - Second smallest: " << result2.first << ", Second largest: " << result2.second << endl;

    return 0;
}
