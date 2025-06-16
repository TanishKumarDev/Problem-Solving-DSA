#include <bits/stdc++.h>
using namespace std;

int main() {
    // Declaration
    stack<int> s;

    // Insert elements (push to top)
    s.push(10);
    s.push(20);
    s.push(30);

    // Size of stack
    cout << "Size: " << s.size() << "\n"; // Output: 3

    // Access top element
    cout << "Top: " << s.top() << "\n"; // Output: 30

    // Remove element (pop from top)
    s.pop(); // Removes 30

    cout << "After pop, top: " << s.top() << "\n"; // Output: 20

    // Check if empty
    cout << (s.empty() ? "Stack is empty" : "Stack is not empty") << "\n"; // Output: Stack is not empty

    // Insert more elements
    s.push(40);
    s.push(50);

    // Display all elements (using temporary stack to preserve original)
    cout << "Stack elements (from top to bottom): ";
    stack<int> temp = s; // Copy stack for iteration
    while (!temp.empty()) {
        cout << temp.top() << " ";
        temp.pop();
    } // Output: 50 40 20 10
    cout << "\n";

    // Clear stack by popping all elements
    while (!s.empty()) {
        s.pop();
    }
    cout << "After clearing, size: " << s.size() << "\n"; // Output: 0

    return 0;
}

/*
# STL std::stack Overview
- Purpose: Implements a Last-In-First-Out (LIFO) stack, allowing insertions and removals from the top.
- Implementation: Adapter over a container (default: std::deque), providing a restricted interface for LIFO operations.

Properties:
- Supports push (top), pop (top), and access to the top element.
- No random access or direct iteration over elements.
- Elements are of type T (no key-value pairs).
- Use Cases: Function call stacks, undo mechanisms, expression evaluation, or any LIFO-based processing.

# Time Complexities for std::stack Operations

## Notes
- n: Number of elements in the stack.
- Uses underlying container (default: std::deque) for storage.
- Time complexities depend on the underlying container (std::deque provides O(1) for push/pop at the back).
- No direct iteration; requires popping or copying to access all elements.

## Operations

1. Insert (push)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Adds an element to the top. O(1) using std::deque's push_back.

2. Remove (pop)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Removes the top element. O(1) using std::deque's pop_back.

3. Access (top)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Accesses the top element. O(1) using std::deque's back.

4. Size (size)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Returns number of elements, stored by the underlying container.

5. Empty (empty)
   - Best Case: O(1)
   - Average Case: O(1)
   - Worst Case: O(1)
   - Description: Checks if the stack is empty. O(1) via underlying container.

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
- O(n): Stores n elements in the underlying container (e.g., std::deque), plus minimal overhead for the stack adapter.
*/