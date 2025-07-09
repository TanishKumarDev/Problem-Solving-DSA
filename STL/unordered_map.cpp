#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    unordered_map<string, int> umap;

    // Insertion
    umap["apple"] = 3;
    umap["banana"] = 5;
    umap["cherry"] = 2;

    // Another way to insert
    umap.insert({"dragonfruit", 7});

    // Access
    cout << "Apple count: " << umap["apple"] << "\n"; // Output: 3

    // Safe access using at()
    cout << "Cherry count: " << umap.at("cherry") << "\n"; // Output: 2

    // Update value
    umap["banana"] += 2; // banana = 7

    // Check key exists
    if (umap.find("cherry") != umap.end())
        cout << "Cherry exists\n"; // Output: Cherry exists

    // Size of unordered_map
    cout << "Map size: " << umap.size() << "\n"; // Output: 4

    // Erase key
    umap.erase("dragonfruit");

    // Iterate over map
    cout << "Contents:\n";
    for (auto &p : umap) {
        cout << p.first << " -> " << p.second << "\n";
    } // Output: (unordered, e.g., apple -> 3, banana -> 7, cherry -> 2)

    // Clear map
    umap.clear();
    cout << "Map size after clear: " << umap.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::unordered_map Overview
- Purpose: Stores unique key-value pairs with fast average-case lookup, without sorting.
- Implementation: Hash table.

Properties:
- Keys are unique and unordered.
- Supports dynamic insertion, deletion, and lookup.
- Elements are pair<const Key, T> (key is immutable).
- Use Cases: When fast key-based lookups are needed, such as caching, frequency counting, or mapping without sorting.

# Time Complexities for std::unordered_map Operations

## Notes
- n: Number of elements in the unordered_map.
- Assumes hash table implementation with good hash function.
- Constant-time operations (O(1)) in average case with minimal collisions.
- Worst case (O(n)) occurs with many hash collisions (rare with good hashing).

## Operations

1. Insert (insert, umap[key] = value)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Inserts or updates a key-value pair. Average O(1) with good hashing; O(n) if many collisions.

2. Access (umap[key], at)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Retrieves value for a key. umap[key] inserts default value if absent; at() throws if key missing.

3. Erase (erase)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Removes a key-value pair. Average O(1); O(n) with many collisions.

4. Find (find, count)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(n)
   - Description: Checks if a key exists. find returns iterator; count returns 0 or 1.

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
*/