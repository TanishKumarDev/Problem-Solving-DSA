#include <bits/stdc++.h>
using namespace std;

// 🔴 Approach 1 Sorting Both Strings
class Solution {
public:
    bool isAnagram(string s, string t) {
        // If lengths are not equal, they can't be anagrams
        if (s.length() != t.length())
            return false;

        // Sort both strings
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());

        // If sorted strings are equal, they are anagrams
        return s == t;
    }
};


// 🔵 Approach 2  Frequency Count using Fixed 26-size Vector
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        // Count array for 26 lowercase letters (a-z)
        vector<int> count(26, 0);

        // Increase count for each character in s
        for(char c : s){
            count[c - 'a']++;
        }

        // Decrease count for each character in t
        for(char c : t){
            count[c - 'a']--;
        }

        // Check if all counts are zero
        for(int i = 0; i < 26; i++){
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};


// 🟢 Approach 3 Frequency Count using 128-size Vector (ASCII)
class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length())
            return false;

        // ASCII-based count array (for all characters)
        vector<int> count(128, 0);

        // Increment count for each character in s
        for(char c : s){
            count[c]++;
        }

        // Decrement count for each character in t
        for(char c : t){
            count[c]--;
        }

        // If any count is non-zero, not an anagram
        for(int i = 0; i < 128; i++){
            if(count[i] != 0)
                return false;
        }
        return true;
    }
};


int main()
{
    
    return 0;
}