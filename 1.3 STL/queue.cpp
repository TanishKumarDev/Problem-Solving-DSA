#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    queue<int> q;

    // Insert elements (push to back)
    q.push(10);
    q.push(20);
    q.push(30);

    // Size of queue
    cout << "Size: " << q.size() << "\n"; // Output: 3

    // Access front and back
    cout << "Front: " << q.front() << "\n"; // Output: 10
    cout << "Back: " << q.back() << "\n"; // Output: 30

    // Remove element (pop from front)
    q.pop(); // Removes 10

    cout << "After pop, front: " << q.front() << "\n"; // Output: 20

    // Check if empty
    cout << (q.empty() ? "Queue is empty" : "Queue is not empty") << "\n"; // Output: Queue is not empty

    // Insert more elements
    q.push(40);
    q.push(50);

    // Display all elements (using temporary queue to preserve original)
    cout << "Queue elements: ";
    queue<int> temp = q; // Copy queue for iteration
    while (!temp.empty()) {
        cout << temp.front() << " ";
        temp.pop();
    } // Output: 20 30 40 50
    cout << "\n";

    // Clear queue by popping all elements
    while (!q.empty()) {
        q.pop();
    }
    cout << "After clearing, size: " << q.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::queue Overview
- Purpose: Implements a First-In-First-Out (FIFO) queue, allowing insertions at the back and removals from the front.
- Implementation: Adapter over a container (default: std::deque), providing a restricted interface for FIFO operations.

Properties:
- Supports push (back), pop (front), and access to front/back elements.
- No random access or direct iteration over elements.
- Elements are of type T (no key-value pairs).
- Use Cases: Task scheduling, breadth-first search, or any FIFO-based processing (e.g., print queues, event handling).

# Time Complexities for std::queue Operations

## Notes
- n: Number of elements in the queue.
- Uses underlying container (default: std::deque) for storage.
- Time complexities depend on the underlying container (std::deque provides O(1) for push/pop at ends).
- No direct iteration; requires popping or copying to access all elements.

## Operations

1. Insert (push)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Adds an element to the back. O(1) using std::deque's push_back.

2. Remove (pop)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Removes the front element. O(1) using std::deque's pop_front.

3. Access (front, back)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Accesses the front or back element. O(1) using std::deque's front/back.

4. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored by the underlying container.

5. Empty (empty)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Checks if the queue is empty. O(1) via underlying container.

6. Iteration (manual via pop or copy)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: No direct iteration; requires popping or copying to access all elements, taking O(n).

7. Clear (manual via pop)
   - Best Case: O(n)
   - Average Case: O(n)
   - Worst Case: O(n)
   - Description: Removes all elements by repeated pop operations, taking O(n).

# Space Complexity
- O(n): Stores n elements in the underlying container (e.g., std::deque), plus minimal overhead for the queue adapter.
*/