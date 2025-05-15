#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declare multimap
    multimap<string, int> mm;

    // 🔹 Insert key-value pairs
    mm.insert({"apple", 10});
    mm.insert({"banana", 20});
    mm.insert({"apple", 15}); // duplicate key allowed
    mm.insert({"cherry", 25});
    mm.insert({"banana", 30});

    // 🔹 Iterate - sorted by key
    cout << "All elements (sorted):\n";
    for (auto &p : mm) {
        cout << p.first << " → " << p.second << "\n";
    }

    // 🔹 Count number of values for a key
    cout << "banana count: " << mm.count("banana") << "\n";

    // 🔹 Equal Range - to get all values for a key
    auto range = mm.equal_range("apple");
    cout << "All apple values:\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << "\n";

    // 🔹 Erase one occurrence (using iterator)
    auto it = mm.find("banana");
    if (it != mm.end()) mm.erase(it);

    // 🔹 Final state
    cout << "After erasing one 'banana':\n";
    for (auto &p : mm) {
        cout << p.first << " → " << p.second << "\n";
    }

    return 0;
}
// time complexity: O(log n) for insertion, O(n) for search and deletion in the worst case
// space complexity: O(n) for storing n elements