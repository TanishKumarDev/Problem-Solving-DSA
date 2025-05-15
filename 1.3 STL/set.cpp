#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declaration
    set<int> s;

    // 🔹 Insert elements
    s.insert(10);
    s.insert(5);
    s.insert(20);
    s.insert(10);  // won't be inserted again (unique)

    // 🔹 Iterate (sorted order!)
    cout << "Set elements: ";
    for (int x : s) cout << x << " ";  // Output: 5 10 20
    cout << "\n";

    // 🔹 Find an element
    if (s.find(10) != s.end()) cout << "10 is present\n";
    else cout << "10 is not found\n";

    // 🔹 Erase an element
    s.erase(5);  // removes value 5

    // 🔹 Size
    cout << "Size of set: " << s.size() << "\n";

    // 🔹 Check if empty
    cout << (s.empty() ? "Empty" : "Not Empty") << "\n";

    // 🔹 Lower and Upper Bound
    s.insert(15);
    auto it = s.lower_bound(12);  // ≥ 12 → 15
    if (it != s.end()) cout << "Lower bound of 12: " << *it << "\n";

    it = s.upper_bound(15);       // > 15 → 20
    if (it != s.end()) cout << "Upper bound of 15: " << *it << "\n";

    return 0;
}
