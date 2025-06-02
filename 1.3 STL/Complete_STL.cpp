#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_set>
#include <unordered_map>
#include <algorithm>
#include <functional>
using namespace std;

// === Sequence Containers ===

// Vector: Dynamic array that auto-resizes.
// - Features: Fast random access (O(1)), slow middle insertions/deletions (O(n)).
// - Use: When you need a flexible array with fast indexing.
void demo_vector() {
    cout << "\n=== Vector Demo ===\n";
    vector<int> v = {1, 2, 3};
    v.push_back(4); // Add 4
    for (int x : v) cout << x << " "; // Output: 1 2 3 4
    cout << "\nSize: " << v.size() << endl;
}

// List: Doubly-linked list for non-contiguous storage.
// - Features: Fast insertions/deletions (O(1) once position is known), no random access.
// - Use: When frequent insertions/deletions are needed in the middle.
void demo_list() {
    cout << "\n=== List Demo ===\n";
    list<int> l = {1, 2, 3};
    l.push_front(0); // Add 0 at front
    for (int x : l) cout << x << " "; // Output: 0 1 2 3
    cout << "\nSize: " << l.size() << endl;
}

// Deque: Double-ended queue, fast insertions/deletions at both ends.
// - Features: Random access (O(1)), efficient at both ends (O(1)).
// - Use: When you need to add/remove elements at both ends.
void demo_deque() {
    cout << "\n=== Deque Demo ===\n";
    deque<int> d = {2, 3};
    d.push_front(1); // Add 1 at front
    d.push_back(4); // Add 4 at back
    for (int x : d) cout << x << " "; // Output: 1 2 3 4
    cout << "\nSize: " << d.size() << endl;
}

// === Container Adaptors ===

// Stack: LIFO (Last In, First Out) container.
// - Features: Operations at top only (push, pop), no random access.
// - Use: For scenarios like function call stacks or undo operations.
void demo_stack() {
    cout << "\n=== Stack Demo ===\n";
    stack<int> s;
    s.push(1); s.push(2); // Push 1, 2
    cout << "Top: " << s.top() << endl; // Output: 2
    s.pop();
    cout << "Top after pop: " << s.top() << endl; // Output: 1
}

// Queue: FIFO (First In, First Out) container, uses deque by default.
// - Features: Insert at back, remove from front, no random access.
// - Use: For task scheduling or breadth-first search.
void demo_queue() {
    cout << "\n=== Queue Demo ===\n";
    queue<int> q;
    q.push(1); q.push(2); // Push 1, 2
    cout << "Front: " << q.front() << endl; // Output: 1
    q.pop();
    cout << "Front after pop: " << q.front() << endl; // Output: 2
}

// Priority Queue: Heap-based, highest priority element at top.
// - Features: No FIFO/LIFO, uses vector by default, O(log n) for push/pop.
// - Use: For priority-based scheduling or Dijkstra’s algorithm.
void demo_priority_queue() {
    cout << "\n=== Priority Queue Demo ===\n";
    priority_queue<int> pq;
    pq.push(3); pq.push(1); pq.push(4);
    cout << "Top: " << pq.top() << endl; // Output: 4
    pq.pop();
    cout << "Top after pop: " << pq.top() << endl; // Output: 3
}

// === Associative Containers ===

// Set: Stores unique, sorted elements.
// - Features: No duplicates, sorted order (ascending by default), O(log n) operations.
// - Use: When you need unique elements in sorted order.
void demo_set() {
    cout << "\n=== Set Demo ===\n";
    set<int> s = {1, 2, 3, 1}; // No duplicates
    s.insert(4);
    for (int x : s) cout << x << " "; // Output: 1 2 3 4
    cout << "\nSize: " << s.size() << endl;
}

// Map: Stores sorted key-value pairs with unique keys.
// - Features: Keys sorted, fast lookup (O(log n)).
// - Use: When you need key-value pairs in sorted order.
void demo_map() {
    cout << "\n=== Map Demo ===\n";
    map<string, int> m = {{"a", 1}, {"b", 2}};
    m["c"] = 3;
    for (auto& p : m) cout << p.first << ":" << p.second << " "; // Output: a:1 b:2 c:3
    cout << "\nSize: " << m.size() << endl;
}

// Multiset: Like set, but allows duplicate elements.
// - Features: Sorted, duplicates allowed, O(log n) operations.
// - Use: When you need sorted elements with duplicates.
void demo_multiset() {
    cout << "\n=== Multiset Demo ===\n";
    multiset<int> ms = {1, 2, 2, 3};
    ms.insert(2); // Add another 2
    cout << "Count of 2: " << ms.count(2) << endl; // Output: 3
    for (int x : ms) cout << x << " "; // Output: 1 2 2 2 3
    cout << endl;
}

// Multimap: Like map, but allows duplicate keys.
// - Features: Sorted keys, multiple values per key, O(log n) operations.
// - Use: When you need key-value pairs with duplicate keys in sorted order.
void demo_multimap() {
    cout << "\n=== Multimap Demo ===\n";
    multimap<string, int> mm = {{"a", 1}, {"a", 2}};
    mm.insert({"a", 3});
    cout << "Count of 'a': " << mm.count("a") << endl; // Output: 3
    for (auto& p : mm) cout << p.first << ":" << p.second << " "; // Output: a:1 a:2 a:3
    cout << endl;
}

// === Unordered Associative Containers ===

// Unordered Set: Stores unique elements in a hash table.
// - Features: Fast lookup/insertion/deletion (O(1) average), no order.
// - Use: When you need fast lookups and don’t care about order.
void demo_unordered_set() {
    cout << "\n=== Unordered Set Demo ===\n";
    unordered_set<int> us = {1, 2, 3};
    us.insert(2); // No duplicates
    for (int x : us) cout << x << " "; // Output: (order varies) 3 1 2
    cout << "\nSize: " << us.size() << endl;
}

// Unordered Multiset: Like unordered set, but allows duplicates.
// - Features: Fast operations (O(1) average), duplicates allowed, no order.
// - Use: When you need fast lookups with duplicates.
void demo_unordered_multiset() {
    cout << "\n=== Unordered Multiset Demo ===\n";
    unordered_multiset<int> ums = {1, 2, 2, 3};
    ums.insert(2);
    cout << "Count of 2: " << ums.count(2) << endl; // Output: 3
    for (int x : ums) cout << x << " "; // Output: (order varies) 1 2 2 2 3
    cout << endl;
}

// Unordered Map: Stores key-value pairs with unique keys in a hash table.
// - Features: Fast lookup (O(1) average), no order.
// - Use: When you need fast key-value lookups.
void demo_unordered_map() {
    cout << "\n=== Unordered Map Demo ===\n";
    unordered_map<string, int> um = {{"x", 1}, {"y", 2}};
    um["z"] = 3;
    for (auto& p : um) cout << p.first << ":" << p.second << " "; // Output: (order varies) x:1 y:2 z:3
    cout << "\nSize: " << um.size() << endl;
}

// Unordered Multimap: Like unordered map, but allows duplicate keys.
// - Features: Fast operations (O(1) average), duplicate keys, no order.
// - Use: When you need key-value pairs with duplicate keys.
void demo_unordered_multimap() {
    cout << "\n=== Unordered Multimap Demo ===\n";
    unordered_multimap<string, int> umm = {{"x", 1}, {"x", 2}};
    umm.insert({"x", 3});
    cout << "Count of 'x': " << umm.count("x") << endl; // Output: 3
    for (auto& p : umm) cout << p.first << ":" << p.second << " "; // Output: (order varies) x:1 x:2 x:3
    cout << endl;
}

// === Algorithms ===

// sort: Sorts elements in a range (default: ascending).
// - Features: O(n log n), customizable with comparators.
// - Use: When you need to sort a sequence.
void demo_sort() {
    cout << "\n=== Sort Demo ===\n";
    vector<int> v = {3, 1, 4};
    sort(v.begin(), v.end()); // Ascending
    for (int x : v) cout << x << " "; // Output: 1 3 4
    cout << "\nDescending: ";
    sort(v.begin(), v.end(), greater<int>()); // Descending
    for (int x : v) cout << x << " "; // Output: 4 3 1
    cout << endl;
}

// min_element: Returns iterator to smallest element in a range.
// - Features: O(n), customizable comparator.
// - Use: To find the smallest element.
void demo_min_element() {
    cout << "\n=== Min Element Demo ===\n";
    vector<int> v = {3, 1, 4};
    auto it = min_element(v.begin(), v.end());
    cout << "Min: " << *it << endl; // Output: 1
}

// max_element: Returns iterator to largest element in a range.
// - Features: O(n), customizable comparator.
// - Use: To find the largest element.
void demo_max_element() {
    cout << "\n=== Max Element Demo ===\n";
    vector<int> v = {3, 1, 4};
    auto it = max_element(v.begin(), v.end());
    cout << "Max: " << *it << endl; // Output: 4
}

// next_permutation: Generates next lexicographically greater permutation.
// - Features: Returns false if no next permutation, sorts range in ascending order.
// - Use: To generate all permutations of a sequence.
void demo_next_permutation() {
    cout << "\n=== Next Permutation Demo ===\n";
    vector<int> v = {1, 2, 3};
    do {
        for (int x : v) cout << x << " ";
        cout << endl;
    } while (next_permutation(v.begin(), v.end()));
    // Output: All permutations (1 2 3, 1 3 2, 2 1 3, etc.)
}

// __builtin_popcount: GCC built-in to count set bits (1s) in an integer.
// - Features: Fast bit manipulation, not standard STL.
// - Use: For bit manipulation tasks.
void demo_builtin_popcount() {
    cout << "\n=== __builtin_popcount Demo ===\n";
    int x = 13; // Binary: 1101
    cout << "Set bits in " << x << ": " << __builtin_popcount(x) << endl; // Output: 3
}

// === Iterators ===

// Iterators: Pointer-like objects to traverse containers.
// - Types: Input (read, forward), Output (write, forward), Forward (read/write, forward),
//          Bidirectional (read/write, forward/backward), Random Access (all operations).
// - Use: Connect algorithms to containers.
void demo_iterators() {
    cout << "\n=== Iterators Demo ===\n";
    vector<int> v = {1, 2, 3};
    vector<int>::iterator it = v.begin();
    cout << "First: " << *it << endl; // Output: 1
    it++;
    cout << "Second: " << *it << endl; // Output: 2
}

// === Functors ===

// Functors: Objects that act like functions via operator().
// - Types: Arithmetic (plus, minus), Relational (greater, less), Logical (logical_and), Bitwise (bit_and).
// - Use: For custom algorithm behavior.
void demo_functors() {
    cout << "\n=== Functors Demo ===\n";
    vector<int> v = {1, 2, 3};
    sort(v.begin(), v.end(), greater<int>()); // Use greater functor
    for (int x : v) cout << x << " "; // Output: 3 2 1
    cout << endl;
}

// === Templates ===

// Templates: Enable generic programming for functions and classes.
// - Use: To write reusable code for any data type.
// === Templates ===

// Function Template
template <typename T>
T add(T a, T b) {
    return a + b;
}

// Class Template
template <typename T>
class Box {
public:
    T value;
    Box(T v) : value(v) {}
};

void demo_templates() {
    cout << "\n=== Templates Demo ===\n";

    // Using function template
    cout << "Int sum: " << add(1, 2) << endl;           // Output: 3
    cout << "Double sum: " << add(1.5, 2.5) << endl;     // Output: 4

    // Using class template
    Box<int> b(10);
    cout << "Box value: " << b.value << endl;            // Output: 10
}
/*
❌ Problem:
declared a template inside a function, which is not allowed.
🧠 Cause:
Templates are compile-time constructs. The compiler needs them at global or namespace scope to instantiate them properly.
✅ Solution:
Move the template function or class declaration outside the function.

✅ Fix Example:

// Outside the function
template <typename T>
T add(T a, T b) { return a + b; }
void demo() {
    cout << add(1, 2) << endl; // ✅ OK now
}
	🛠 Templates must be declared globally, not locally.

    */
int main() {
    // Run all demos
    demo_vector();
    demo_list();
    demo_deque();
    demo_stack();
    demo_queue();
    demo_priority_queue();
    demo_set();
    demo_map();
    demo_multiset();
    demo_multimap();
    demo_unordered_set();
    demo_unordered_multiset();
    demo_unordered_map();
    demo_unordered_multimap();
    demo_sort();
    demo_min_element();
    demo_max_element();
    demo_next_permutation();
    demo_builtin_popcount();
    demo_iterators();
    demo_functors();
    demo_templates();
    return 0;
}