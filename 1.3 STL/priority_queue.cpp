#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration (max-heap by default)
    priority_queue<int> pq;

    // Insert elements
    pq.push(10);
    pq.push(30);
    pq.push(20);
    pq.push(5);

    // Size of priority_queue
    cout << "Size: " << pq.size() << "\n"; // Output: 4

    // Access top element (highest priority)
    cout << "Top: " << pq.top() << "\n"; // Output: 30

    // Remove top element
    pq.pop(); // Removes 30

    cout << "After pop, top: " << pq.top() << "\n"; // Output: 20

    // Check if empty
    cout << (pq.empty() ? "Priority queue is empty" : "Priority queue is not empty") << "\n"; // Output: Priority queue is not empty

    // Insert more elements
    pq.push(40);
    pq.push(15);

    // Display all elements (using temporary priority_queue to preserve original)
    cout << "Priority queue elements (from highest to lowest): ";
    priority_queue<int> temp = pq; // Copy priority_queue
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    } // Output: 40 20 15 10 5
    cout << "\n";

    // Declaration (min-heap using greater<int>)
    priority_queue<int, vector<int>, greater<int>> min_pq;
    min_pq.push(10);
    min_pq.push(30);
    min_pq.push(20);
    cout << "Min-heap top: " << min_pq.top() << "\n"; // Output: 10

    // Clear priority_queue by popping all elements
    while (!pq.empty()) {
        pq.pop();
    }
    cout << "After clearing, size: " << pq.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::priority_queue Overview
- Purpose: Implements a priority queue, where the highest (or lowest) priority element is always at the top.
- Implementation: Adapter over a container (default: std::vector), using a heap (default: max-heap).

Properties:
- Supports push, pop, and access to the top element.
- No random access or direct iteration over elements.
- Elements are of type T (no key-value pairs).
- Use Cases: Task scheduling with priorities, Dijkstra’s algorithm, Huffman coding, or any scenario requiring prioritized processing.

# Time Complexities for std::priority_queue Operations

## Notes
- n: Number of elements in the priority_queue.
- Uses underlying container (default: std::vector) and maintains heap property.
- Time complexities depend on heap operations (O(log n) for heap adjustments, O(1) for top access).
- No direct iteration; requires popping or copying to access all elements.

## Operations

1. Insert (push)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Adds an element and restores heap property. O(log n) for heapification.

2. Remove (pop)
   - Best Case: O(log n)
   - Average Case: O(log n)
   - Worst Case: O(log n)
   - Description: Removes the top element and restores heap property. O(log n) for heapification.

3. Access (top)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Accesses the top element (highest/lowest priority). O(1) via underlying container.

4. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored by the underlying container.

5. Empty (empty)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Checks if the priority_queue is empty. O(1) via underlying container.

6. Iteration (manual via pop or copy)
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   - Description: No direct iteration; requires popping or copying, with each pop taking O(log n), totaling O(n log n).

7. Clear (manual via pop)
   - Best Case: O(n log n)
   - Average Case: O(n log n)
   - Worst Case: O(n log n)
   - Description: Removes all elements by repeated pop operations, each taking O(log n), totaling O(n log n).

# Space Complexity
- O(n): Stores n elements in the underlying container (e.g., std::vector), plus minimal overhead for the priority_queue adapter.
*/