#include <bits/stdc++.h>
using namespace std;

int main() {
    // Basic usage with vector
    vector<int> v = {5, 2, 9, 1, 3};
    auto it = min_element(v.begin(), v.end());
    cout << "Minimum Element: " << *it << "\n"; // Output: 1

    // With array
    int arr[] = {10, 20, 5, 25, 15};
    auto min_it = min_element(arr, arr + 5);
    cout << "Minimum Element in array: " << *min_it << "\n"; // Output: 5

    // On a string: returns iterator to minimum character
    string str = "cbade";
    auto min_char = min_element(str.begin(), str.end());
    cout << "Minimum character: " << *min_char << "\n"; // Output: a

    // Custom comparator: pair with minimum second
    vector<pair<int, int>> vp = {{1, 4}, {3, 2}, {2, 9}};
    auto min_pair = min_element(vp.begin(), vp.end(), [](auto &a, auto &b) {
        return a.second < b.second;
    });
    cout << "Pair with min second: (" << min_pair->first << ", " << min_pair->second << ")\n"; // Output: (3, 2)

    // Edge case: empty container
    vector<int> empty;
    auto min_empty = min_element(empty.begin(), empty.end());
    if (min_empty == empty.end())
        cout << "Empty container, no minimum element.\n";

    return 0;
}
