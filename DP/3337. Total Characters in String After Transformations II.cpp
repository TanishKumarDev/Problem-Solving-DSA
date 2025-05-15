#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    /*
    Approach 1 - Brute Force Simulation

    Intuition:
    - Har transformation step mein har character ko uske `nums[ch - 'a']` next characters se replace karo.
    - Har step ke baad naya string banega.

    Time: O(n * max(nums)^t) → exponential
    Space: O(n * max(nums)^t)
    */
    const int MOD = 1e9 + 7; // Modulo to handle large numbers and prevent overflow

    // Main function to calculate the length of the string after t transformations
    int lengthAfterTransformations(string s, int t, vector<int> &nums)
    {
        // Perform the transformation t times
        for (int step = 0; step < t; ++step)
        {
            string next_str = ""; // String to store the result after this transformation step

            // Loop through each character in the current string
            for (char ch : s)
            {
                int idx = ch - 'a'; // Find the index of the character (0 for 'a', 1 for 'b', ..., 25 for 'z')

                // Loop over the range of characters that the current character will transform to
                for (int i = 1; i <= nums[idx]; ++i)
                {
                    // Calculate the next character based on the transformation rules
                    char next_ch = (ch - 'a' + i) % 26 + 'a'; // The next character in the circular alphabet

                    next_str += next_ch; // Append the transformed character to the result string
                }
            }

            // After processing all characters, set the new string as the current string
            s = next_str;
        }

        // Return the length of the final string after all transformations, modulo 1e9 + 7
        return s.length() % MOD;
    }
    /*
    Approach 2 - Memoized DFS (Top-Down DP)

    Intuition:
    - Har character ko t steps ke baad kitna expand karega, woh calculate karo.
    - Har (char, t) ke liye result store karke reuse karo.
    - Har character independent hai, toh poore string ka answer = sum of all dfs(ch, t)

    Time: O(n + 26 * t)
    Space: O(26 * t)
    */

    // MOD constant to handle large results
    const int MOD = 1e9 + 7;

    // Vector to store the transformation rules for each character ('a' to 'z')
    vector<int> nums;

    // Memoization map to store previously calculated results to avoid recomputation
    // memo[ch][t] will store the length of string obtained by transforming character 'ch' t times
    unordered_map<char, unordered_map<int, long long>> memo;

    // DFS function to calculate the number of characters that a character 'ch' will expand to after 't' transformations
    long long dfs(char ch, int t)
    {
        // Base case: if no more transformations are left, the length is just 1 (the character itself)
        if (t == 0)
            return 1;

        // If we've already calculated the result for this (ch, t), return it
        if (memo[ch].count(t))
            return memo[ch][t];

        long long total = 0;

        // Get the index of character 'ch' (e.g., 'a' = 0, 'b' = 1, ..., 'z' = 25)
        int idx = ch - 'a';

        // Loop over the next `nums[idx]` characters from the current character 'ch' (with wrap-around using modulo 26)
        for (int i = 1; i <= nums[idx]; ++i)
        {
            // Get the next character after i shifts from the current character 'ch' using modulo 26 for wrap-around
            char next_ch = (ch - 'a' + i) % 26 + 'a';

            // Recursively call dfs on this next character for t-1 transformations
            // This is the crucial step where we calculate the expanded length for the next character
            total = (total + dfs(next_ch, t - 1)) % MOD;
        }

        // Store the computed result in the memoization map
        return memo[ch][t] = total;
    }

    // Main function to calculate the total length of the string after t transformations
    int lengthAfterTransformations(string s, int t, vector<int> &nums_input)
    {
        // Store the input 'nums' array globally for use inside dfs
        nums = nums_input;

        // Variable to accumulate the result for the entire string
        long long result = 0;

        // For every character in the input string 's', calculate the total length after t transformations
        for (char ch : s)
        {
            result = (result + dfs(ch, t)) % MOD; // Add the result of each character transformation to the total
        }

        // Return the final result modulo 1e9 + 7 to prevent overflow
        return result;
    }
};
