#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declaration
    multiset<int> mset;

    // 🔹 Insertion (duplicates allowed)
    mset.insert(5);
    mset.insert(2);
    mset.insert(5); // duplicate
    mset.insert(8);
    mset.insert(1);

    // 🔹 Print (sorted + duplicates allowed)
    cout << "multiset elements: ";
    for (int x : mset) cout << x << " "; // Output: 1 2 5 5 8
    cout << "\n";

    // 🔹 Count frequency
    cout << "Count of 5: " << mset.count(5) << "\n"; // 2

    // 🔹 Erase single occurrence
    auto it = mset.find(5); // only one instance removed
    if (it != mset.end()) mset.erase(it);

    cout << "After erase one 5: ";
    for (int x : mset) cout << x << " "; // Output: 1 2 5 8
    cout << "\n";

    // 🔹 Erase all 5s
    mset.erase(5); // all 5s gone

    cout << "After erasing all 5s: ";
    for (int x : mset) cout << x << " ";
    cout << "\n";

    // 🔹 Lower and upper bounds
    mset.insert({3, 4, 6});
    cout << "Lower bound of 4: " << *mset.lower_bound(4) << "\n"; // ≥ 4
    cout << "Upper bound of 4: " << *mset.upper_bound(4) << "\n"; // > 4

    return 0;
}
