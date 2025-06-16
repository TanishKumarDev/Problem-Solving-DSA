#include <bits/stdc++.h>
using namespace std;

int main() {
    // Basic usage with vector
    vector<int> v = {5, 2, 9, 1, 3};
    auto it = max_element(v.begin(), v.end());
    cout << "Maximum Element: " << *it << "\n"; // Output: 9

    // With array
    int arr[] = {10, 20, 5, 25, 15};
    auto max_it = max_element(arr, arr + 5);
    cout << "Maximum Element in array: " << *max_it << "\n"; // Output: 25

    // On a string: returns iterator to maximum character
    string str = "cbade";
    auto max_char = max_element(str.begin(), str.end());
    cout << "Maximum character: " << *max_char << "\n"; // Output: e

    // Custom comparator: pair with maximum second
    vector<pair<int, int>> vp = {{1, 4}, {3, 2}, {2, 9}};
    auto max_pair = max_element(vp.begin(), vp.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    cout << "Pair with max second: (" << max_pair->first << ", " << max_pair->second << ")\n"; // Output: (2, 9)

    // Edge case: empty container
    vector<int> empty;
    auto max_empty = max_element(empty.begin(), empty.end());
    if (max_empty == empty.end())
        cout << "Empty container, no maximum element.\n";

    return 0;
}

/*
# C++ STL `max_element()` Overview

- `std::max_element()` is from `<algorithm>`.
- Purpose: Finds **iterator to the maximum element** in a given range.
- Works on **iterators** (vector, array, string, etc.)

# Syntax:
```cpp
auto it = max_element(start, end);
auto it = max_element(start, end, comparator);
*/