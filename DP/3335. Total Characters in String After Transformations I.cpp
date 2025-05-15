#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
        Approach 1 - Brute Force

        Intuition:
        - Perform transformations as per rules:
            - 'z' → "ab"
            - any other char → next char in alphabet
        - Build the new string at every step

        Time Complexity:
        - After t steps, length ≈ n * 2^t → O(n * 2^t)

        Space Complexity:
        - We recreate the string at each step → O(n * 2^t)
    */
    int lengthAfterTransformations_brute(string s, int t)
    {
        const int MOD = 1e9 + 7;

        while (t--)
        {
            string temp = ""; // temp string to store current transformation

            for (char ch : s)
            {
                if (ch == 'z')
                    temp += "ab"; // 'z' → "ab"
                else
                    temp += (char)(ch + 1); // other → next char
            }

            s = temp; // update s

            // Optional: Early exit if string becomes too large
            if (s.length() > MOD)
                return -1;
        }

        return s.length() % MOD;
    }

    /*
        Approach 2 - Optimal (Recommended)

        Intuition:
        - We only care about final string **length**, not content
        - Track how many of each character exist using frequency count
        - Apply transformation rules on frequencies instead of the actual string

        Transformation Rules:
        - If char == 'z' (i = 25): z → a + b → count[0] += count[25], count[1] += count[25]
        - Else: i → i+1 → count[i+1] += count[i]

        Time Complexity:
        - O(26 * t): 26 characters, processed in each of t steps

        Space Complexity:
        - O(26): fixed-size arrays for frequencies
    */
    int lengthAfterTransformations_optimal(string s, int t)
    {
        const int MOD = 1e9 + 7;

        // Step 1: Frequency array of 26 lowercase letters
        vector<long long> count(26, 0);
        for (char ch : s)
            count[ch - 'a']++;

        // Step 2: Apply t transformations
        while (t--)
        {
            vector<long long> newCount(26, 0); // new frequencies after transformation

            for (int i = 0; i < 26; i++)
            {
                if (i == 25)
                {
                    // 'z' → 'a' and 'b'
                    newCount[0] = (newCount[0] + count[25]) % MOD;
                    newCount[1] = (newCount[1] + count[25]) % MOD;
                }
                else
                {
                    // i-th character → (i+1)-th character
                    newCount[i + 1] = (newCount[i + 1] + count[i]) % MOD;
                }
            }

            count = newCount; // update for next round
        }

        // Step 3: Total length = sum of frequencies
        long long totalLength = 0;
        for (int i = 0; i < 26; i++)
            totalLength = (totalLength + count[i]) % MOD;

        return totalLength;
    }
};

int main()
{
    Solution sol;

    string s = "abc";
    int t = 2;

    cout << "Brute Force Result: " << sol.lengthAfterTransformations_brute(s, t) << endl;
    cout << "Optimal Result: " << sol.lengthAfterTransformations_optimal(s, t) << endl;

    return 0;
}
