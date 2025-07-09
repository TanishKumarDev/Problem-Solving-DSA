#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    multiset<int> mset;

    // Insertion (duplicates allowed)
    mset.insert(5);
    mset.insert(2);
    mset.insert(5); // duplicate
    mset.insert(8);
    mset.insert(1);

    // Print (sorted + duplicates allowed)
    cout << "Multiset elements: ";
    for (int x : mset) cout << x << " "; // Output: 1 2 5 5 8
    cout << "\n";

    // Size of multiset
    cout << "Multiset size: " << mset.size() << "\n"; // Output: 5

    // Count frequency
    cout << "Count of 5: " << mset.count(5) << "\n"; // Output: 2

    // Erase single occurrence
    auto it = mset.find(5); // Finds first occurrence of 5
    if (it != mset.end()) mset.erase(it);

    cout << "After erasing one 5: ";
    for (int x : mset) cout << x << " "; // Output: 1 2 5 8
    cout << "\n";

    // Erase all occurrences of 5
    mset.erase(5); // Removes all 5s

    cout << "After erasing all 5s: ";
    for (int x : mset) cout << x << " "; // Output: 1 2 8
    cout << "\n";

    // Insert multiple elements
    mset.insert({3, 4, 6});

    // Lower and upper bounds
    cout << "Lower bound of 4: " << *mset.lower_bound(4) << "\n"; // ≥ 4, Output: 4
    cout << "Upper bound of 4: " << *mset.upper_bound(4) << "\n"; // > 4, Output: 6

    return 0;
}

/*
# STL std::multiset Overview
- Purpose: Stores multiple sorted elements, allowing duplicates.
- Implementation: Self-balancing binary search tree (e.g., red-black tree).

Properties:
- Elements are sorted in ascending order (by default).
- Supports duplicate elements.
- Dynamic insertion, deletion, and lookup operations.
- Elements are of type T (no key-value pairs).
- Use Cases: When sorted elements with duplicates are needed, such as frequency counting or range queries.

# Time Complexities for std::multiset Operations

## Notes
- n: Number of elements in the multiset.
- Assumes self-balancing BST (e.g., red-black tree) implementation.
- Logarithmic operations (O(log n)) due to tree balancing.
- Linear operations (O(n)) for processing all elements.

## Operations

1. Insert (insert)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Inserts an element. Tree balancing ensures logarithmic time.

2. Access (find, count)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: find returns iterator to first occurrence; count returns number of occurrences.

3. Erase (erase)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Removes one (via iterator) or all occurrences (via value). Logarithmic due to tree rebalancing.

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

7. Clear (clear)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements, requiring traversal of the tree.
*/