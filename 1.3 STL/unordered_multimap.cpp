#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    unordered_multimap<string, int> umm;

    // Insert key-value pairs
    umm.insert({"apple", 10});
    umm.insert({"banana", 20});
    umm.insert({"apple", 15}); // Duplicate key allowed
    umm.insert({"cherry", 25});
    umm.insert({"banana", 30});

    // Size
    cout << "Size of unordered_multimap: " << umm.size() << "\n"; // Output: 5

    // Iterate - may print in any order
    cout << "All elements:\n";
    for (auto &p : umm) {
        cout << p.first << " -> " << p.second << "\n"; // Output: (e.g., apple -> 10, apple -> 15, banana -> 20, banana -> 30, cherry -> 25)
    }

    // Count number of values for a key
    cout << "Banana count: " << umm.count("banana") << "\n"; // Output: 2

    // Find first occurrence
    auto it = umm.find("apple");
    if (it != umm.end())
        cout << "First apple found -> " << it->second << "\n"; // Output: (e.g., First apple found -> 10)

    // Equal Range - to get all values for a key
    auto range = umm.equal_range("banana");
    cout << "All banana values: ";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " "; // Output: (e.g., 20 30)
    }
    cout << "\n";

    // Erase first occurrence of a key
    it = umm.find("apple");
    if (it != umm.end()) umm.erase(it); // Removes one apple pair

    cout << "After erasing one apple, size: " << umm.size() << "\n"; // Output: 4

    // Clear unordered_multimap
    umm.clear();
    cout << "After clearing, size: " << umm.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::unordered_multimap Overview
- Purpose: Stores key-value pairs with fast average-case lookup, allowing duplicate keys, without sorting.
- Implementation: Hash table.

Properties:
- Keys can be duplicated, and pairs are unordered.
- Supports dynamic insertion, deletion, and lookup.
- Elements are pair<const Key, T> (key is immutable).
- Use Cases: When fast lookups with multiple values per key are needed, such as grouping data by key or mapping with duplicates.

# Time Complexities for std::unordered_multimap Operations

## Notes
- n: Number of elements (key-value pairs) in the unordered_multimap.
- Assumes hash table implementation with good hash function.
- Constant-time operations (O(1)) in average case with minimal collisions.
- Worst case (O(n)) occurs with many hash collisions (rare with good hashing).

## Operations

1. Insert (insert)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Inserts a key-value pair. Average O(1) with good hashing; O(n) if many collisions.

2. Access (find, count)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: find returns iterator to first matching pair; count returns number of pairs with the key. Average O(1); O(n) with many collisions.

3. Erase (erase)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Removes one (via iterator) or all pairs (via key). Average O(1); O(n) with many collisions.

4. Equal Range (equal_range)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Returns range of iterators for all pairs with a key. Average O(1); O(n) with many collisions.

5. Iteration (begin, end, range-based loop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Traverses all elements in unspecified order.

6. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored as a variable.

7. Clear (clear)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements, requiring traversal of the hash table.

# Space Complexity
- O(n): Stores n key-value pairs, plus additional overhead for hash table buckets.
*/