#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declaration
    unordered_multiset<int> ums;

    // 🔹 Insert elements (duplicates allowed)
    ums.insert(10);
    ums.insert(20);
    ums.insert(10); // duplicate will be inserted
    ums.insert(30);

    // 🔹 Iterate (no order guaranteed)
    cout << "Elements in unordered_multiset: ";
    for (int x : ums) cout << x << " "; // Output may be: 10 20 10 30
    cout << "\n";

    // 🔹 Count occurrences
    cout << "Count of 10: " << ums.count(10) << "\n"; // 2

    // 🔹 Erase one occurrence
    auto it = ums.find(10);
    if (it != ums.end()) ums.erase(it); // removes one occurrence of 10

    cout << "After one erase, count of 10: " << ums.count(10) << "\n";

    // 🔹 Erase all occurrences
    ums.erase(10); // all 10s gone

    cout << "After full erase, count of 10: " << ums.count(10) << "\n";

    return 0;
}
