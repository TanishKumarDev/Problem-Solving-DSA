#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    set<int> s;

    // Insert elements
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10); // Duplicate, won’t be inserted

    // Iterate (sorted order)
    cout << "Set elements: ";
    for (int x : s) cout << x << " "; // Output: 5 10 20
    cout << "\n";

    // Size
    cout << "Size of set: " << s.size() << "\n"; // Output: 3

    // Find an element
    if (s.find(10) != s.end()) cout << "10 is present\n"; // Output: 10 is present
    else cout << "10 is not found\n";

    // Erase an element
    s.erase(5); // Removes value 5

    // Check if empty
    cout << (s.empty() ? "Empty" : "Not Empty") << "\n"; // Output: Not Empty

    // Lower and Upper Bound
    s.insert(15);
    auto it = s.lower_bound(12); // ≥ 12 → 15
    if (it != s.end()) cout << "Lower bound of 12: " << *it << "\n"; // Output: 15

    it = s.upper_bound(15); // > 15 → 20
    if (it != s.end()) cout << "Upper bound of 15: " << *it << "\n"; // Output: 20

    // Iterator-based iteration
    cout << "Set elements (using iterators): ";
    for (auto it = s.begin(); it != s.end(); ++it) cout << *it << " "; // Output: 10 15 20
    cout << "\n";

    // Clear set
    s.clear();
    cout << "After clearing, size: " << s.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::set Overview
- Purpose: Stores unique elements in sorted order.
- Implementation: Self-balancing binary search tree (e.g., red-black tree).

Properties:
- Elements are unique and sorted (ascending by default).
- Supports dynamic insertion, deletion, and lookup.
- Elements are of type T (no key-value pairs).
- Use Cases: When sorted unique elements are needed, such as deduplication, range queries, or maintaining ordered sets.

# Time Complexities for std::set Operations

## Notes
- n: Number of elements in the set.
- Assumes self-balancing BST (e.g., red-black tree) implementation.
- Logarithmic operations (O(log n)) due to tree balancing.
- Linear operations (O(n)) for processing all elements.

## Operations

1. Insert (insert)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Inserts an element if not already present. Tree balancing ensures logarithmic time.

2. Access (find, count)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: find returns iterator to element; count returns 0 or 1. Logarithmic due to tree traversal.

3. Erase (erase)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Removes an element by value or iterator. Logarithmic due to tree rebalancing.

4. Bounds (lower_bound, upper_bound)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Returns iterators to elements >= or > given value. Logarithmic tree traversal.

5. Iteration (begin, end, range-based loop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Traverses all elements in sorted order.

6. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored as a variable.

7 Ascendingly (ascend)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns true if set is empty, false otherwise.

7. Clear (clear)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements, requiring traversal of the tree.
*/