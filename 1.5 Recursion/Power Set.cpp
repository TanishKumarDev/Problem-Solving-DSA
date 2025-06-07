/**
 * Power Set Generation - Two Approaches
 * This program generates all possible subsequences (power set) of a given string
 * using both Recursive and Bitmasking approaches
 */

#include <iostream>
#include <vector>
#include <string>
using namespace std;

/**
 * ============================================
 * APPROACH 1: RECURSIVE SOLUTION
 * ============================================
 * 
 * Time Complexity: O(2^n * n)
 * - For each character, we make 2 choices (include/exclude)
 * - Total 2^n subsequences
 * - Each subsequence can be up to n characters long
 * 
 * Space Complexity: O(n)
 * - Recursion stack depth is n (length of string)
 * - Additional space for storing results: O(2^n * n)
 * 
 * Intuition:
 * - At each character, we have two choices: include or exclude
 * - This creates a binary decision tree
 * - Each path from root to leaf represents one subsequence
 * - Total paths = 2^n (power set size)
 */

void generateSubsequences(string &s, int i, string curr, vector<string> &res) {
    // Base case: when we've processed all characters
    if (i == s.size()) {
        res.push_back(curr);
        return;
    }

    // Include the current character
    generateSubsequences(s, i + 1, curr + s[i], res);

    // Exclude the current character
    generateSubsequences(s, i + 1, curr, res);
}

vector<string> getAllSubsequencesRecursive(string s) {
    vector<string> res;
    generateSubsequences(s, 0, "", res);
    return res;
}

/**
 * ============================================
 * APPROACH 2: BITMASKING SOLUTION
 * ============================================
 * 
 * Time Complexity: O(2^n * n)
 * - We generate 2^n combinations
 * - For each combination, we process n bits
 * - Each subsequence can be up to n characters long
 * 
 * Space Complexity: O(2^n * n)
 * - Space needed to store all subsequences
 * - No recursion stack needed
 * 
 * Intuition:
 * - Each number from 0 to 2^n-1 represents a unique combination
 * - Each bit position corresponds to a character in the string
 * - 1 means include the character, 0 means exclude
 * - Example: For "abc", 101 (binary) = 5 (decimal) represents "ac"
 */

vector<string> getAllSubsequencesBitmask(string s) {
    int n = s.size();
    int total = 1 << n; // 2^n
    vector<string> res;

    for (int mask = 0; mask < total; mask++) {
        string curr = "";
        for (int j = 0; j < n; j++) {
            if (mask & (1 << j)) {
                curr += s[j];
            }
        }
        res.push_back(curr);
    }

    return res;
}

/**
 * ============================================
 * MAIN FUNCTION
 * ============================================
 */
int main() {
    string input;
    cin >> input;

    // Using Recursive Approach
    cout << "\nUsing Recursive Approach:" << endl;
    vector<string> powerSetRecursive = getAllSubsequencesRecursive(input);
    for (const string &subseq : powerSetRecursive) {
        cout << subseq << " ";
    }
    cout << "\nTotal number of subsequences: " << powerSetRecursive.size() << endl;

    // Using Bitmasking Approach
    cout << "\nUsing Bitmasking Approach:" << endl;
    vector<string> powerSetBitmask = getAllSubsequencesBitmask(input);
    for (const string &subseq : powerSetBitmask) {
        cout << subseq << " ";
    }
    cout << "\nTotal number of subsequences: " << powerSetBitmask.size() << endl;

    return 0;
}

