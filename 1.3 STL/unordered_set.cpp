#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    unordered_set<int> uset;

    // Insert elements
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(10); // Duplicate, won’t be added

    // Insert multiple elements
    uset.insert({40, 50}); // Adds 40 and 50

    // Size
    cout << "Size: " << uset.size() << "\n"; // Output: 5

    // Check if element exists using count
    if (uset.count(20))
        cout << "20 is in the set\n"; // Output: 20 is in the set

    // Find element (returns iterator)
    auto it = uset.find(30);
    if (it != uset.end())
        cout << "Found: " << *it << "\n"; // Output: Found: 30

    // Erase by value
    uset.erase(20);

    // Iterate over set (unordered)
    cout << "Elements: ";
    for (int x : uset) cout << x << " "; // Output: (e.g., 10 30 40 50)
    cout << "\n";

    // Clear all
    uset.clear();
    cout << "After clearing, size: " << uset.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::unordered_set Overview
- Purpose: Stores unique elements with fast average-case lookup, without sorting.
- Implementation: Hash table.

Properties:
- Elements are unique and unordered.
- Supports dynamic insertion, deletion, and lookup.
- Elements are of type T (no key-value pairs).
- Use Cases: When fast lookups for unique elements are needed, such as deduplication, membership testing, or set operations.

# Time Complexities for std::unordered_set Operations

## Notes
- n: Number of elements in the unordered_set.
- Assumes hash table implementation with good hash function.
- Constant-time operations (O(1)) in average case with minimal collisions.
- Worst case (O(n)) occurs with many hash collisions (rare with good hashing).

## Operations

1. Insert (insert)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Inserts an element if not already present. Average O(1) with good hashing; O(n) if many collisions.

2. Access (find, count)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: find returns iterator to element; count returns 0 or 1. Average O(1); O(n) with many collisions.

3. Erase (erase)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Removes an element by value or iterator. Average O(1); O(n) with many collisions.

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