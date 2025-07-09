#include <bits/stdc++.h>
using namespace std;

int main()
{
    // ===================================================
    // Case 1: Hashing for Lowercase Characters Only ('a' to 'z')
    // ===================================================
    {
        cout << "Case 1: Lowercase Characters Only\n";
        
        string s;
        cin >> s;

        int hash_lower[26] = {0}; // 'a' to 'z' --> 26 characters

        // Precompute frequencies
        for (int i = 0; i < s.length(); i++) {
            hash_lower[s[i] - 'a']++;
        }

        // Fetching Queries
        int query;
        cin >> query;
        while (query--) {
            char ch;
            cin >> ch;
            cout << hash_lower[ch - 'a'] << endl;
        }
    }

    // ===================================================
    // Case 2: Hashing for Uppercase Characters Only ('A' to 'Z')
    // ===================================================
    {
        cout << "Case 2: Uppercase Characters Only\n";

        string s;
        cin >> s;

        int hash_upper[26] = {0}; // 'A' to 'Z' --> 26 characters

        // Precompute frequencies
        for (int i = 0; i < s.length(); i++) {
            hash_upper[s[i] - 'A']++;
        }

        // Fetching Queries
        int query;
        cin >> query;
        while (query--) {
            char ch;
            cin >> ch;
            cout << hash_upper[ch - 'A'] << endl;
        }
    }

    // ===================================================
    // Case 3: Hashing for All ASCII Characters (Recommended)
    // ===================================================
    {
        cout << "Case 3: Mixed Characters (Full ASCII)\n";

        string s;
        cin >> s;

        int hash_all[256] = {0}; // All ASCII characters (0 to 255)

        // Precompute frequencies
        for (int i = 0; i < s.size(); i++) {
            hash_all[s[i]]++;
        }

        // Fetching Queries
        int q;
        cin >> q;
        while (q--) {
            char ch;
            cin >> ch;
            cout << hash_all[ch] << endl;
        }
    }

    return 0;
}

 

// Lowercase Hashing ,Uppercase Hashing, Full ASCII Hashing    

// Time Complexity: O(n + q)
// Space Complexity: O(1) for fixed-size hash arrays

/* Test Cases
abacbda
5
a
b
c
d
z

AABBCD
4
A
B
C
Z

AbCabc@123#
6
a
A
@
1
z
#
*/