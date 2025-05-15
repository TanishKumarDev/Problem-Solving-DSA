#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declare unordered_multimap
    unordered_multimap<string, int> umm;

    // 🔹 Insert key-value pairs
    umm.insert({"apple", 10});
    umm.insert({"banana", 20});
    umm.insert({"apple", 15}); // duplicate key allowed
    umm.insert({"cherry", 25});
    umm.insert({"banana", 30});

    // 🔹 Iterate - may print in any order
    cout << "All elements:\n";
    for (auto &p : umm) {
        cout << p.first << " → " << p.second << "\n";
    }

    // 🔹 Count number of values for a key
    cout << "banana count: " << umm.count("banana") << "\n";

    // 🔹 Find first occurrence
    auto it = umm.find("apple");
    if (it != umm.end())
        cout << "First apple found → " << it->second << "\n";

    // 🔹 Equal Range - to get all values for a key
    auto range = umm.equal_range("banana");
    cout << "All banana values:\n";
    for (auto it = range.first; it != range.second; ++it) {
        cout << it->second << " ";
    }
    cout << "\n";

    return 0;
}
// time complexity: O(1) for insertion, O(n) for search and deletion in the worst case
// space complexity: O(n) for storing n elements