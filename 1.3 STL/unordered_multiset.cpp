#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    unordered_multiset<int> ums;

    // Insert elements (duplicates allowed)
    ums.insert(10);
    ums.insert(20);
    ums.insert(10); // duplicate will be inserted
    ums.insert(30);

    // Size of unordered_multiset
    cout << "Unordered_multiset size: " << ums.size() << "\n"; // Output: 4

    // Iterate (no order guaranteed)
    cout << "Elements in unordered_multiset: ";
    for (int x : ums) cout << x << " "; // Output may be: 10 10 20 30
    cout << "\n";

    // Count occurrences
    cout << "Count of 10: " << ums.count(10) << "\n"; // Output: 2

    // Erase one occurrence
    auto it = ums.find(10);
    if (it != ums.end()) ums.erase(it); // Removes one occurrence of 10

    cout << "After one erase, count of 10: " << ums.count(10) << "\n"; // Output: 1

    // Erase all occurrences
    ums.erase(10); // All 10s removed

    cout << "After full erase, count of 10: " << ums.count(10) << "\n"; // Output: 0

    // Insert multiple elements
    ums.insert({15, 15, 25});

    cout << "After inserting 15, 15, 25, elements: ";
    for (int x : ums) cout << x << " "; // Output may be: 20 30 15 15 25
    cout << "\n";

    // Clear unordered_multiset
    ums.clear();
    cout << "Size after clear: " << ums.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::unordered_multiset Overview
- Purpose: Stores multiple elements with fast average-case lookup, allowing duplicates, without sorting.
- Implementation: Hash table.

Properties:
- Elements are unordered and can have duplicates.
- Supports dynamic insertion, deletion, and lookup.
- Elements are of type T (no key-value pairs).
- Use Cases: When fast lookups with duplicates are needed, such as frequency counting or tracking multiple occurrences without sorting.

# Time Complexities for std::unordered_multiset Operations

## Notes
- n: Number of elements in the unordered_multiset.
- Assumes hash table implementation with good hash function.
- Constant-time operations (O(1)) in average case with minimal collisions.
- Worst case (O(n)) occurs with many hash collisions (rare with good hashing).

## Operations

1. Insert (insert)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Inserts an element. Average O(1) with good hashing; O(n) if many collisions.

2. Access (find, count)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: find returns iterator to first occurrence; count returns number of occurrences.

3. Erase (erase)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Removes one (via iterator) or all occurrences (via value). Average O(1); O(n) with many collisions.

4. Iteration (begin, end, range-based loop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Traverses all elements in unspecified order.

5. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored as a variable.

6. Clear (clear)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements, requiring traversal of the hash table.
*/