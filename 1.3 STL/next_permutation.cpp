#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    vector<int> v = {1, 2, 3};

    // Display original sequence
    cout << "Original sequence: ";
    for (int x : v) cout << x << " "; // Output: 1 2 3
    cout << "\n";

    // Generate and display all permutations
    cout << "All permutations:\n";
    do {
        for (int x : v) cout << x << " ";
        cout << "\n";
    } while (next_permutation(v.begin(), v.end())); // Generates next permutation in lexicographical order
    // Output: 
    // 1 2 3
    // 1 3 2
    // 2 1 3
    // 2 3 1
    // 3 1 2
    // 3 2 1

    // Reset vector to sorted order
    v = {3, 1, 2};
    sort(v.begin(), v.end()); // Ensure sorted for permutation generation
    cout << "Sorted sequence: ";
    for (int x : v) cout << x << " "; // Output: 1 2 3
    cout << "\n";

    // Generate first three permutations
    cout << "First three permutations:\n";
    for (int i = 0; i < 3; ++i) {
        for (int x : v) cout << x << " ";
        cout << "\n";
        if (!next_permutation(v.begin(), v.end())) {
            cout << "No more permutations\n";
            break;
        }
    } // Output: 
    // 1 2 3
    // 1 3 2
    // 2 1 3

    // Edge case: Single element
    vector<int> single = {1};
    cout << "Single element permutation: ";
    if (!next_permutation(single.begin(), single.end())) {
        cout << "No next permutation for single element\n";
        for (int x : single) cout << x << " "; // Output: 1
        cout << "\n";
    }

    return 0;
}

/*
# STL std::next_permutation Overview
- Purpose: Generates the next lexicographically greater permutation of a sequence.
- Implementation: Algorithm operating on a range [first, last), modifying it in-place.

Properties:
- Requires the sequence to be sorted or partially sorted for complete permutation generation.
- Returns true if a next permutation exists and modifies the range; false if no next permutation exists (sequence is lexicographically largest).
- Works with any bidirectional iterator range (e.g., vector, array, list).
- Use Cases: Generating all permutations for combinatorial problems, testing all possible arrangements, or solving problems like traveling salesman.

# Time Complexities for std::next_permutation

## Notes
- n: Length of the sequence (number of elements in the range).
- Operates in-place, modifying the sequence to produce the next permutation.
- Time complexity depends on finding the pivot and reversing/swapping elements.
- Assumes comparison-based operations (default: operator<).

## Operations

1. Next Permutation (next_permutation)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Finds the pivot (last pair where a[i] < a[i+1]), swaps with the smallest greater element, and reverses the suffix. Requires O(n) for traversal, comparison, and reversal.

2. Iteration (generating all permutations)
   - Best Case: O(n! * n)
   - Average Case: O(n! * n)
   - Worst Case: O(n! * n)
   - Description: Generating all n! permutations, with each call to next_permutation taking O(n).

# Space Complexity
- O(1): Operates in-place, using only a constant amount of extra space (excluding the input sequence).
*/