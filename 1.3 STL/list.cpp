#include <bits/stdc++.h>
using namespace std;

int main() {
    // Create an empty list
    list<int> l;

    // Insert at end
    l.push_back(10);
    l.push_back(20);
    l.push_back(30);

    // Insert at beginning
    l.push_front(5);
    l.push_back(40);

    
    // Display elements
    cout << "List elements: ";
    for (int x : l)
        cout << x << " ";
    cout << "\n";

    // Size of the list
    cout << "Size: " << l.size() << "\n";

    // Remove specific element (first occurrence)
    l.remove(20); // removes all 20s

    // Insert using iterator
    auto it = l.begin();
    advance(it, 1); // move to second position
    l.insert(it, 15); // insert 15 before second element

    cout << "After insert/remove: ";
    for (int x : l)
        cout << x << " ";
    cout << "\n";

    // Reverse
    l.reverse();
    cout << "Reversed list: ";
    for (int x : l)
        cout << x << " ";
    cout << "\n";

    // Sort
    l.sort();
    cout << "Sorted list: ";
    for (int x : l)
        cout << x << " ";
    cout << "\n";

    return 0;
}
