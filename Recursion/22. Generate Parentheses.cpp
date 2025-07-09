#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void backtrack(int n, int open, int close, string curr, vector<string>& res) {
        if (curr.length() == n * 2) {
            res.push_back(curr);
            return;
        }

        if (open < n) {
            backtrack(n, open + 1, close, curr + '(', res);
        }

        if (close < open) {
            backtrack(n, open, close + 1, curr + ')', res);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        backtrack(n, 0, 0, "", res);
        return res;
    }
};

int main() {
    Solution solution;
    int n;
    cout << "Enter number of pairs of parentheses: ";
    cin >> n;

    vector<string> result = solution.generateParenthesis(n);

    cout << "All combinations of well-formed parentheses:\n";
    for (const string& s : result) {
        cout << s << endl;
    }

    cout << "Total combinations: " << result.size() << endl;
    return 0;
}
