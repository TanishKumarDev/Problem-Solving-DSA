#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    vector<int> v;                   // Empty vector
    vector<int> v2(5, 100);          // [100, 100, 100, 100, 100]
    vector<int> v3 = {1, 2, 3, 4};   // Initializer list

    // Insert elements
    v.push_back(10);
    v.push_back(20);
    v.emplace_back(30); // Faster than push_back

    // Access elements
    cout << "First element: " << v[0] << "\n"; // Output: 10
    cout << "At index 1: " << v.at(1) << "\n"; // Output: 20, with bounds check

    // Size and Capacity
    cout << "Size: " << v.size() << "\n"; // Output: 3
    cout << "Capacity: " << v.capacity() << "\n"; // Output: >= 3 (implementation-dependent)

    // Front and Back
    cout << "Front: " << v.front() << "\n"; // Output: 10
    cout << "Back: " << v.back() << "\n"; // Output: 30

    // Insert in middle
    v.insert(v.begin() + 1, 99); // Insert 99 at index 1

    // Remove element
    v.erase(v.begin()); // Remove first element (10)

    // Pop back
    v.pop_back(); // Removes last element (30)

    // Resize vector
    v.resize(5, 0); // Resize to 5, fill new elements with 0

    // Iterate using iterators
    cout << "Elements (using iterators): ";
    for (auto it = v.begin(); it != v.end(); ++it) cout << *it << " "; // Output: 99 20 0 0 0
    cout << "\n";

    // Clear vector
    v.clear();

    // Check empty
    if (v.empty()) cout << "Vector is empty!\n"; // Output: Vector is empty!

    return 0;
}

/*
# STL std::vector Overview
- Purpose: Stores a dynamic array of elements with contiguous memory, supporting random access.
- Implementation: Dynamic array with automatic resizing.

Properties:
- Elements are stored contiguously, allowing random access.
- Supports dynamic resizing (e.g., push_back, insert).
- Elements are of type T (no key-value pairs).
- Use Cases: When dynamic arrays with fast random access are needed, such as lists, stacks, or buffers.

# Time Complexities for std::vector Operations

## Notes
- n: Number of elements in the vector.
- k: Number of elements affected (e.g., inserted, erased).
- Assumes amortized constant time for push_back due to geometric resizing.
- Contiguous memory enables O(1) random access.

## Operations

1. Insert (push_back, emplace_back)
   - Best Case: O(1)
   - Average Case: O(1) (amortized)
   - Worst Case: O(n)
   - Description: Adds element to the end. Amortized O(1) due to resizing; O(n) if reallocation occurs.

2. Insert (insert at arbitrary position)
   - Best Case: O(k)
   - Average Case: O(n + k)
   - Worst Case: O(n + k)
   - Description: Inserts k elements at a position, shifting subsequent elements. O(n) for shifting.

3. Access (operator[], at, front, back)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Accesses elements by index or retrieves first/last element. Contiguous memory ensures O(1).

4. Erase (erase at arbitrary position)
   - Best Case: O(k)
   - Average Case: O(n + k)
   - Worst Case: O(n + k)
   - Description: Removes k elements, shifting subsequent elements. O(n) for shifting.

5. Erase (pop_back)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Removes last element. No shifting required.

6. Iteration (begin, end, range-based loop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Traverses all elements sequentially.

7. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored as a variable.

8. Capacity (capacity)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns allocated storage size, stored as a variable.

9. Clear (clear)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements, destructing each one.

10. Resize (resize)
    - Best Case: O(k)
    - Average Case: O(k)
    - Worst Case: O(n + k)
    - Description: Changes size to k. O(k) for adding/removing elements; O(n) if reallocation needed.
*/