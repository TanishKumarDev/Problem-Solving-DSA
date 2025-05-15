#include <bits/stdc++.h>
using namespace std;

int main() {
    // 🔹 Declaration
    unordered_map<string, int> umap;

    // 🔹 Insertion
    umap["apple"] = 3;
    umap["banana"] = 5;
    umap["cherry"] = 2;

    // 🔹 Another way to insert
    umap.insert({"dragonfruit", 7});

    // 🔹 Access
    cout << "apple count: " << umap["apple"] << "\n"; // 3

    // 🔹 Update value
    umap["banana"] += 2; // banana = 7

    // 🔹 Check key exists
    if (umap.find("cherry") != umap.end())
        cout << "cherry exists\n";

    // 🔹 Erase key
    umap.erase("dragonfruit");

    // 🔹 Iterate over map
    cout << "Contents:\n";
    for (auto &p : umap) {
        cout << p.first << " → " << p.second << "\n";
    }

    return 0;
}
