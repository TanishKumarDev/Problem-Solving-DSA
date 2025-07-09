#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    deque<int> dq;

    // Insert elements at back
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);

    // Insert elements at front
    dq.push_front(5);
    dq.push_front(0);

    // Size of deque
    cout << "Size: " << dq.size() << "\n"; // Output: 5

    // Access elements
    cout << "Front: " << dq.front() << "\n"; // Output: 0
    cout << "Back: " << dq.back() << "\n"; // Output: 30
    cout << "Element at index 2: " << dq[2] << "\n"; // Output: 10

    // Remove elements
    dq.pop_front(); // Removes 0
    dq.pop_back(); // Removes 30

    // Insert at specific position
    dq.insert(dq.begin() + 1, 15); // Insert 15 at index 1

    // Iterator-based iteration
    cout << "Deque elements: ";
    for (auto it = dq.begin(); it != dq.end(); ++it) {
        cout << *it << " "; // Output: 5 15 10 20
    }
    cout << "\n";

    // Resize deque
    dq.resize(6, 100); // Resize to 6, fill new elements with 100
    cout << "After resize: ";
    for (int x : dq) {
        cout << x << " "; // Output: 5 15 10 20 100 100
    }
    cout << "\n";

    // Check if empty
    cout << (dq.empty() ? "Deque is empty" : "Deque is not empty") << "\n"; // Output: Deque is not empty

    // Clear deque
    dq.clear();
    cout << "After clearing, size: " << dq.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::deque Overview
- Purpose: Implements a double-ended queue, supporting efficient insertions and deletions at both ends.
- Implementation: Array of fixed-size blocks, allowing random access and dynamic resizing.

Properties:
- Elements are stored in non-contiguous blocks, supporting random access.
- Supports efficient push/pop at both front and back.
- Elements are of type T (no key-value pairs).
- Use Cases: When efficient operations at both ends are needed, such as sliding windows, double-ended queues, or as an underlying container for std::queue/std::stack.

# Time Complexities for std::deque Operations

## Notes
- n: Number of elements in the deque.
- k: Number of elements affected or distance from end.
- Block-based structure enables O(1) operations at front/back and O(1) random access.
- Insertions/deletions in the middle are linear due to shifting elements.

## Operations

1. Insert (push_back, push_front)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Adds an element to the front or back. O(1) due to block-based structure; occasional block allocation is amortized.

2. Insert (insert at arbitrary position)
   - Best Case: O(k)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Inserts an element at a position, shifting subsequent elements. O(n) for shifting in the worst case.

3. Remove (pop_back, pop_front)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Removes an element from the front or back. O(1) due to block-based structure.

4. Remove (erase at arbitrary position)
   - Best Case: O(k)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes an element, shifting subsequent elements. O(n) for shifting in the worst case.

5. Access (operator[], front, back, at)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Accesses elements by index or retrieves first/last element. O(1) due to block indexing; at() includes bounds checking.

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

8. Empty (empty)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Checks if the deque is empty. O(1) via size check.

9. Resize (resize)
   - Best Case: O(k)
   - Average Case: O(k)
   - Worst Case: O(k)
   - Description: Changes size to k, adding/removing elements. O(k) for new elements or removals.

10. Clear (clear)
    - Best Case: O(n)
    - Average Case: O(n)
    - Worst Case: O(n)
    - Description: Removes all elements, destructing each one.

# Space Complexity
- O(n): Stores n elements across fixed-size blocks, plus O(1) overhead for block pointers and bookkeeping.
*/