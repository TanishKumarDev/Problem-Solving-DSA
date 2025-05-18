#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    list<int> l;

    // Insert at end
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    // Insert at beginning
    l.push_front(5);
    l.push_back(40);

    // Size of the list
    cout << "Size: " << l.size() << "\n"; // Output: 5

    // Display elements
    cout << "List elements: ";
    for (int x : l) cout << x << " "; // Output: 5 10 20 30 40
    cout << "\n";

    // Remove specific element (all occurrences)
    l.remove(20); // Removes all 20s

    // Insert using iterator
    auto it = l.begin();
    advance(it, 1); // Move to second position
    l.insert(it, 15); // Insert 15 before second element

    // Iterator-based iteration
    cout << "After insert/remove: ";
    for (auto it = l.begin(); it != l.end(); ++it) cout << *it << " "; // Output: 5 15 10 30 40
    cout << "\n";

    // Reverse
    l.reverse();
    cout << "Reversed list: ";
    for (int x : l) cout << x << " "; // Output: 40 30 10 15 5
    cout << "\n";

    // Sort
    l.sort();
    cout << "Sorted list: ";
    for (int x : l) cout << x << " "; // Output: 5 10 15 30 40
    cout << "\n";

    // Pop front
    l.pop_front(); // Removes first element (5)
    cout << "After pop_front: ";
    for (int x : l) cout << x << " "; // Output: 10 15 30 40
    cout << "\n";

    // Clear list
    l.clear();
    cout << "After clearing, size: " << l.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::list Overview
- Purpose: Stores a doubly-linked list of elements, supporting efficient insertions and deletions at any position.
- Implementation: Doubly-linked list.

Properties:
- Elements are stored non-contiguously, linked by pointers.
- Supports bidirectional iteration and dynamic insertion/deletion.
- Elements are of type T (no key-value pairs).
- Use Cases: When frequent insertions/deletions at arbitrary positions are needed, such as implementing queues, deques, or maintaining ordered sequences.

# Time Complexities for std::list Operations

## Notes
- n: Number of elements in the list.
- k: Distance from beginning/end or number of elements affected.
- Doubly-linked list enables O(1) operations at known positions (e.g., front, back, or via iterator).
- Linear time for operations requiring traversal or comparison.

## Operations

1. Insert (push_back, push_front, insert)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Inserts an element at front, back, or via iterator. O(1) once position is known; traversal to position (e.g., via advance) may add O(k).

2. Remove (remove)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all occurrences of a value, requiring traversal and comparison.

3. Erase (pop_front, pop_back, erase)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Removes element at front, back, or via iterator. O(1) once position is known; traversal to position may add O(k).

4. Access (via iterator)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Accesses element via iterator. No random access; traversal to position costs O(k).

5. Iteration (begin, end, range-based loop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Traverses all elements sequentially.

6. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored as a variable (C++11 and later).

7. Reverse (reverse)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Reverses the order of elements by swapping pointers.

8. Sort (sort)
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   - Description: Sorts elements using merge sort, optimized for linked lists.

9. Clear (clear)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements, destructing each one.

# Space Complexity
- O(n): Stores n elements, plus O(n) for pointers to next/previous elements in the doubly-linked list.
*/