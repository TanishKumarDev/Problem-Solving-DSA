#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    multimap<string, int> mm;

    // Insert key-value pairs
    mm.insert({"apple", 10});
    mm.insert({"banana", 20});
    mm.insert({"apple", 15}); // Duplicate key allowed
    mm.insert({"cherry", 25});
    mm.insert({"banana", 30});

    // Size
    cout << "Size of multimap: " << mm.size() << "\n"; // Output: 5

    // Iterate - sorted by key
    cout << "All elements (sorted):\n";
    for (auto &p : mm) {
        cout << p.first << " -> " << p.second << "\n"; // Output: apple -> 10, apple -> 15, banana -> 20, banana -> 30, cherry -> 25
    }

    // Count number of values for a key
    cout << "Banana count: " << mm.count("banana") << "\n"; // Output: 2

    // Equal Range - to get all values for a key
    auto range = mm.equal_range("apple");
    cout << "All apple values: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " "; // Output: 10 15
    }
    cout << "\n";

    // Erase one occurrence (using iterator)
    auto it = mm.find("banana");
    if (it != mm.end()) mm.erase(it); // Removes one banana pair (e.g., banana -> 20)

    // Iterator-based iteration
    cout << "After erasing one 'banana' (using iterators):\n";
    for (auto it = mm.begin(); it != mm.end(); ++it) {
        cout << it->first << " -> " << it->second << "\n"; // Output: apple -> 10, apple -> 15, banana -> 30, cherry -> 25
    }

    // Clear multimap
    mm.clear();
    cout << "After clearing, size: " << mm.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::multimap Overview
- Purpose: Stores key-value pairs in sorted order, allowing duplicate keys.
- Implementation: Self-balancing binary search tree (e.g., red-black tree).

Properties:
- Keys can be duplicated, and pairs are sorted by key (ascending by default).
- Supports dynamic insertion, deletion, and lookup.
- Elements are pair<const Key, T> (key is immutable).
- Use Cases: When sorted key-value pairs with duplicates are needed, such as grouping data by key or maintaining ordered mappings.

# Time Complexities for std::multimap Operations

## Notes
- n: Number of elements (key-value pairs) in the multimap.
- Assumes self-balancing BST (e.g., red-black tree) implementation.
- Logarithmic operations (O(log n)) due to tree balancing.
- Linear operations (O(n)) for processing all elements.

## Operations

1. Insert (insert)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Inserts a key-value pair. Tree balancing ensures logarithmic time.

2. Access (find, count)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: find returns iterator to first matching pair; count returns number of pairs with the key. Logarithmic due to tree traversal.

3. Erase (erase)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Removes one (via iterator) or all pairs (via key). Logarithmic due to tree rebalancing.

4. Equal Range (equal_range)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Returns range of iterators for all pairs with a key. Logarithmic tree traversal.

5. Iteration (begin, end, range-based loop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Traverses all elements in sorted order by key.

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

# Space Complexity
- O(n): Stores n key-value pairs, plus additional overhead for tree structure.
*/