#include <bits/stdc++.h>
using namespace std;

/*
🔍 Approach 1: Brute Force (Recursive Subsequences)

Intuition:
- Generate all possible subsequences using recursion.
- For each subsequence, check if:
  - Adjacent groups are different (0->1 or 1->0).
  - Adjacent words have Hamming distance exactly 1.
- Keep track of the longest valid subsequence.

Desi Analogy:
- Soch, tu ek party mein guests ko line mein laga raha hai. Har guest ka group (boy/girl) alag hona chahiye, aur unke names mein sirf ek letter ka difference hona chahiye. Tu har possible combination try karega.

Time Complexity: O(2^n * n * L) — 2^n subsequences, n for validation, L (string length) for Hamming distance.
Space Complexity: O(n) — recursion stack and storing subsequence.
*/

class BruteForceSolution
{
private:
    // Helper function to check Hamming distance = 1
    bool hammingDistance(const string &s1, const string &s2)
    {
        if (s1.size() != s2.size())
            return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

    // Recursive function to generate subsequences
    void generateSubsequences(int index, int prevGroup, string prevWord, vector<string> &current, vector<string> &best, const vector<string> &words, const vector<int> &groups)
    {
        // Base case: end of array
        if (index == words.size())
        {
            if (current.size() > best.size())
            {
                best = current;
            }
            return;
        }

        // Skip current word
        generateSubsequences(index + 1, prevGroup, prevWord, current, best, words, groups);

        // Include current word if valid
        if (prevGroup == -1 || (groups[index] != prevGroup && hammingDistance(prevWord, words[index])))
        {
            current.push_back(words[index]);
            generateSubsequences(index + 1, groups[index], words[index], current, best, words, groups);
            current.pop_back();
        }
    }

public:
    vector<string> getLongestSubsequence_brute(vector<string> &words, vector<int> &groups)
    {
        vector<string> current, best;
        generateSubsequences(0, -1, "", current, best, words, groups);
        return best;
    }
};

/*
⚡ Approach 2: Optimal (Dynamic Programming with LIS Pattern)

Observations:
- Problem follows Longest Increasing Subsequence (LIS) pattern.
- Each word can be the end of a valid subsequence if it satisfies:
  - Different group from previous word.
  - Hamming distance = 1 with previous word.
- Use dp[i] to store max length of valid subsequence ending at index i.
- Use parent[i] to reconstruct the subsequence.

Intuition:
- For each index i, check all previous indices j < i.
- If groups[j] != groups[i] and Hamming distance = 1, extend subsequence from j to i.
- Track the previous index using parent array to rebuild the result.

Desi Analogy:
- Soch, tu ek chain bana raha hai jisme har link (word) ke liye previous link se group alag hona chahiye aur name mein ek letter ka difference. Har link ke liye pehle ke sab links check kar, aur sabse lambi chain bana.

Time Complexity: O(n^2 * L) — n^2 pairs, L (string length) for Hamming distance.
Space Complexity: O(n) — dp and parent arrays.
*/

class OptimalSolution
{
private:
    // Helper function to check Hamming distance = 1
    bool hammingDistance(const string &s1, const string &s2)
    {
        if (s1.size() != s2.size())
            return false;
        int diff = 0;
        for (int i = 0; i < s1.size(); ++i)
        {
            if (s1[i] != s2[i])
                diff++;
            if (diff > 1)
                return false;
        }
        return diff == 1;
    }

public:
    vector<string> getLongestSubsequence_optimal(vector<string> &words, vector<int> &groups)
    {
        int n = words.size();
        vector<int> dp(n, 1);      // dp[i] = max length ending at i
        vector<int> parent(n, -1); // parent[i] = prev index in subsequence

        // Initialize: each word is a subsequence of length 1
        for (int i = 0; i < n; ++i)
        {
            dp[i] = 1;
            parent[i] = -1;
        }

        // Fill dp table
        for (int i = 1; i < n; ++i)
        {
            for (int j = 0; j < i; ++j)
            {
                if (groups[j] != groups[i] && hammingDistance(words[j], words[i]))
                {
                    if (dp[j] + 1 > dp[i])
                    {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;
                    }
                }
            }
        }

        // Find max length and end index
        int maxLen = 0, endIdx = 0;
        for (int i = 0; i < n; ++i)
        {
            if (dp[i] > maxLen)
            {
                maxLen = dp[i];
                endIdx = i;
            }
        }

        // Reconstruct subsequence
        vector<string> result;
        while (endIdx != -1)
        {
            result.push_back(words[endIdx]);
            endIdx = parent[endIdx];
        }
        reverse(result.begin(), result.end());
        return result;
    }
};

/*
🧪 Testing both approaches
*/
int main()
{
    vector<string> words = {"aba", "bcb", "ece", "aa", "e"};
    vector<int> groups = {0, 0, 1, 1, 1};

    BruteForceSolution brute;
    OptimalSolution optimal;

    cout << "🔍 Brute Force Result: ";
    for (auto &word : brute.getLongestSubsequence_brute(words, groups))
    {
        cout << word << " ";
    }
    cout << endl;

    cout << "⚡ Optimal Result: ";
    for (auto &word : optimal.getLongestSubsequence_optimal(words, groups))
    {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}