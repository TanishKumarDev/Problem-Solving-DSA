#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    map<string, int> mp;

    // Insert values
    mp["apple"] = 4;
    mp["banana"] = 2;
    mp["cherry"] = 5;
    mp.insert({"dragonfruit", 7});

    // Access value
    cout << "Banana count: " << mp["banana"] << "\n";

    // Update
    mp["banana"] += 3;

    // Safe access using at()
    cout << "Cherry count: " << mp.at("cherry") << "\n";

    // Check existence using count
    cout << "Apple exists: " << (mp.count("apple") ? "Yes" : "No") << "\n";

    // Erase key
    mp.erase("dragonfruit");

    // Size of map
    cout << "Map size: " << mp.size() << "\n";

    // Iterate using iterators
    cout << "Contents of map (using iterators):\n";
    for (auto it = mp.begin(); it != mp.end(); ++it) {
        cout << it->first << " -> " << it->second << "\n";
    }

    // Clear map
    mp.clear();
    cout << "Map size after clear: " << mp.size() << "\n";

    return 0;
}
/*
# STL std::map Overview
- Purpose: Stores unique, sorted key-value pairs.
- Implementation: Self-balancing BST (e.g., red-black tree).

Properties:
- Keys are unique and sorted (ascending by default).
- Supports dynamic insertion, deletion, and lookup.
- Elements are pair<const Key, T> (key is immutable).
- Use Cases: When sorted keys or frequent key-based lookups are needed.

# Time Complexities for std::map Operations

## Notes
- n: Number of elements in the map.
- Assumes self-balancing BST (e.g., red-black tree) implementation.
- Logarithmic operations (O(log n)) due to tree balancing.
- Linear operations (O(n)) for processing all elements.

## Operations

1. Insert (mp[key] = value, insert)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Inserts or updates a key-value pair. Tree balancing ensures logarithmic time.

2. Access (mp[key], at)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Retrieves value for a key. mp[key] inserts default value if absent; at() throws if key missing.

3. Erase (erase)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Removes a key-value pair. Tree rebalancing takes logarithmic time.

4. Find (find, count)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Checks if a key exists. find returns iterator; count returns 0 or 1.

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