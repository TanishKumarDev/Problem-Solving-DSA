#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declaration
    vector<int> v;                   // empty
    vector<int> v2(5, 100);          // [100, 100, 100, 100, 100]
    vector<int> v3 = {1, 2, 3, 4};   // initializer list

    // 🔹 Insert elements
    v.push_back(10);
    v.push_back(20);
    v.emplace_back(30); // faster than push_back

    // 🔹 Access elements
    cout << "First element: " << v[0] << "\n";
    cout << "At index 1: " << v.at(1) << "\n"; // with bounds check

    // 🔹 Size and Capacity
    cout << "Size: " << v.size() << "\n";
    cout << "Capacity: " << v.capacity() << "\n";

    // 🔹 Front and Back
    cout << "Front: " << v.front() << "\n";
    cout << "Back: " << v.back() << "\n";

    // 🔹 Insert in middle
    v.insert(v.begin() + 1, 99); // insert 99 at index 1

    // 🔹 Remove element
    v.erase(v.begin());          // remove first element

    // 🔹 Pop back
    v.pop_back();                // removes last element

    // 🔹 Iterate
    for (int x : v) cout << x << " ";
    cout << "\n";

    // 🔹 Clear vector
    v.clear();

    // 🔹 Check empty
    if (v.empty()) cout << "Vector is empty!\n";

    return 0;
}
