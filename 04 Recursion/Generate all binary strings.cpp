#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void solve(int n, string curr, vector<string>& res) {
        if (curr.length() == n) {
            res.push_back(curr);
            return;
        }

        // Always add '0'
        solve(n, curr + '0', res);

        // Add '1' only if last char is not '1'
        if (curr.empty() || curr.back() != '1') {
            solve(n, curr + '1', res);
        }
    }

    vector<string> generateBinaryStrings(int n) {
        vector<string> res;
        solve(n, "", res);
        sort(res.begin(), res.end()); // Sort for lexicographical order
        return res;
    }
};

int main() {
    Solution solution;
    int n;
    // cout << "Enter the length of binary strings: ";
    cin >> n;

    vector<string> result = solution.generateBinaryStrings(n);

    // Print all generated strings
    cout << "\nAll possible binary strings of length " << n << ":\n";
    for(const string &s : result) {
        cout << s << " ";
    }
    cout << endl;

    // Print the total number of strings
    cout << "Total number of strings: " << result.size() << endl;

    return 0;
}
