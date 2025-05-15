#include <bits/stdc++.h>
using namespace std;

/*
Approach 1: Brute Force

Intuition:
- Generate all possible subsequences of indices using bitmasking.
- For each subsequence, check if adjacent `groups` values are different.
- Keep track of the longest valid subsequence.

Time Complexity: O(2^n * n)
Space Complexity: O(n) — for storing the best subsequence
*/

class BruteForceSolution {
public:
    vector<string> getLongestSubsequence_brute(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        int maxLen = 0;
        vector<string> bestSubsequence;

        // Loop through all possible subsequences using bitmasking (2^n)
        for (int mask = 1; mask < (1 << n); ++mask) {
            vector<int> indices;

            // Build the subsequence based on current bitmask
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    indices.push_back(i);
                }
            }

            // Check if adjacent groups differ
            bool isValid = true;
            for (int i = 1; i < indices.size(); ++i) {
                if (groups[indices[i]] == groups[indices[i - 1]]) {
                    isValid = false;
                    break;
                }
            }

            // Update answer if this subsequence is valid and longer
            if (isValid && indices.size() > maxLen) {
                maxLen = indices.size();
                bestSubsequence.clear();
                for (int idx : indices) {
                    bestSubsequence.push_back(words[idx]);
                }
            }
        }

        return bestSubsequence;
    }
};

/*
Approach 2: Optimal (Greedy)

Observations:
- You can include a word if its group is different from the previous one in the subsequence.
- Start from index 0, and whenever the group toggles, include that word.

Intuition:
- Simply iterate from left to right.
- Pick a word only when its group differs from the previous one included.

Time Complexity: O(n)
Space Complexity: O(n)
*/

class OptimalSolution {
public:
    vector<string> getLongestSubsequence_optimal(vector<string>& words, vector<int>& groups) {
        vector<string> result;
        int prev = -1;  // No group has been selected yet

        for (int i = 0; i < words.size(); ++i) {
            if (groups[i] != prev) {
                result.push_back(words[i]);
                prev = groups[i];  // Update last included group
            }
        }

        return result;
    }
};

// 🧪 Testing both approaches
int main() {
    vector<string> words = {"a", "b", "c", "d"};
    vector<int> groups = {1, 0, 1, 1};

    BruteForceSolution brute;
    OptimalSolution optimal;

    cout << "🔍 Brute Force Result: ";
    for (auto& word : brute.getLongestSubsequence_brute(words, groups)) {
        cout << word << " ";
    }
    cout << endl;

    cout << "⚡ Optimal Result: ";
    for (auto& word : optimal.getLongestSubsequence_optimal(words, groups)) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
