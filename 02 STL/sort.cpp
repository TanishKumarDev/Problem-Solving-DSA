#include <bits/stdc++.h>
using namespace std;

int main() {
    // Sorting integers in ascending order
    vector<int> v1 = {5, 2, 9, 1, 3}; // Original: {5, 2, 9, 1, 3}
    sort(v1.begin(), v1.end()); // Default: ascending
    cout << "Sorted (Ascending): ";
    for (int x : v1) cout << x << " ";
    cout << "\n"; // Output: 1 2 3 5 9

    // Sorting in descending order using greater<>
    vector<int> v2 = {5, 2, 9, 1, 3}; // Original: {5, 2, 9, 1, 3}
    sort(v2.begin(), v2.end(), greater<int>());
    cout << "Sorted (Descending): ";
    for (int x : v2) cout << x << " ";
    cout << "\n"; // Output: 9 5 3 2 1

    // Sorting pairs by second value using lambda
    vector<pair<int, int>> vp = {{1, 4}, {3, 2}, {2, 9}}; // (key, value)
    sort(vp.begin(), vp.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
    });
    cout << "\nSorted Pairs by Second Value:\n";
    for (auto p : vp) {
        cout << "(" << p.first << ", " << p.second << ") ";
    }
    cout << "\n"; // Output: (3, 2) (1, 4) (2, 9)

    // Use Case: Sort string characters
    string str = "cbade";
    sort(str.begin(), str.end());
    cout << "\nSorted String: " << str << "\n"; // Output: abcde

    return 0;
}

/*
# C++ STL `sort()` Overview

- `std::sort()` is a built-in function from `<algorithm>` used to sort elements in a given range.
- Purpose: Arrange elements in ascending (default) or custom order.
- Internally uses **Introsort**: hybrid of quicksort, heapsort, and insertion sort.

# Properties:
- Works on containers with **RandomAccessIterator** (e.g., `vector`, array).
- Can take a **custom comparator** as third argument.
- Stable: ❌ No (does not preserve original order for equal elements).

# Variants:
- `sort(start, end)` – Ascending
- `sort(start, end, greater<int>())` – Descending
- `sort(start, end, lambda/functor)` – Custom rule

# Use Cases:
- Competitive programming sorting
- Sorting objects/pairs/strings
- Custom sort logic using lambda
- Preprocessing before binary search / greedy logic

# Time Complexities for `std::sort`

## Notes
- n: Number of elements in the container.
- Hybrid design ensures worst-case O(n log n).

## Operations

1. `sort()`
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   - Description: Introsort (quicksort + heapsort fallback to avoid O(n²)).

# Space Complexity
- O(log n): Due to function recursion stack (quicksort part).

*/
