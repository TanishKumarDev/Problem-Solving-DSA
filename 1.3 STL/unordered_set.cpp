#include <bits/stdc++.h>
using namespace std;

int main()
{
    unordered_set<int> uset;

    // 🔹 Insert elements
    uset.insert(10);
    uset.insert(20);
    uset.insert(30);
    uset.insert(10); // duplicate, won’t be added

    // 🔹 Size
    cout << "Size: " << uset.size() << "\n";

    // 🔹 Check if element exists using count
    if (uset.count(20))
        cout << "20 is in the set\n";

    // 🔹 Find element (returns iterator)
    auto it = uset.find(30);
    if (it != uset.end())
        cout << "Found: " << *it << "\n";

    // 🔹 Erase by value
    uset.erase(20);

    // 🔹 Iterate over set (unordered)
    cout << "Elements:\n";
    for (int x : uset)
        cout << x << " ";
    cout << "\n";

    // 🔹 Clear all
    uset.clear();
    cout << "After clearing, size: " << uset.size() << "\n";

    return 0;
}
