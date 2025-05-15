#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declaration
    map<string, int> mp;

    // 🔹 Insert values
    mp["apple"] = 4;
    mp["banana"] = 2;
    mp["cherry"] = 5;

    // 🔹 Another way
    mp.insert({"dragonfruit", 7});

    // 🔹 Access value
    cout << "Banana count: " << mp["banana"] << "\n";

    // 🔹 Update
    mp["banana"] += 3;

    // 🔹 Safe access using at()
    cout << "Cherry count: " << mp.at("cherry") << "\n";

    // 🔹 Check existence
    if (mp.find("apple") != mp.end())
        cout << "Apple exists\n";

    // 🔹 Erase key
    mp.erase("dragonfruit");

    // 🔹 Iterate (ordered by keys)
    cout << "Contents of map:\n";
    for (auto &p : mp) {
        cout << p.first << " → " << p.second << "\n";
    }

    return 0;
}
// time complexity: O(log n) for insertion, deletion, and access
// space complexity: O(n) for storing n elements
// Note: map is ordered by keys, while unordered_map is not. Use unordered_map for faster access if order doesn't matter.
// Also, map stores keys in sorted order, while unordered_map does not guarantee any order.
// This is a simple demonstration of how to use the map data structure in C++.
// The map is a part of the C++ STL (Standard Template Library) and is used to store key-value pairs.
// It is implemented as a balanced binary search tree (usually a Red-Black tree), which allows for efficient searching, insertion, and deletion operations.
// The map is a very useful data structure for many applications, such as counting frequencies, storing configurations, and more.
// The map is a very versatile data structure and is widely used in competitive programming and software development.
// It is important to understand how to use it effectively and efficiently.
// The map is a powerful tool that can help you solve many problems in programming.
