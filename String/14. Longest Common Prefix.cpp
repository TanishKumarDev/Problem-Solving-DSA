#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem :  Find the longest common prefix string amongst an array of strings.
// Example : Input: ["flower","flow","flight"] Output: "fl"
// Constraint : All input strings are lowercase letters a-z.
// Note : If there is no common prefix, return an empty string "".

// 🔴 Approach 1 Brute Force : 

// Intuition : Take the first string as a reference and check each of its characters against the same position in all other strings. If all characters match and no string ends prematurely, add the character to the result. Stop at the first mismatch or when any string is exhausted. Handle edge cases like empty arrays or empty strings separately. This approach is straightforward but involves checking all strings for each character.

// Algo :

// TC : O(n * m) - where n is the number of strings and m is the length of the longest string
// SC : O(1) - no extra space used for strings
string longestCommonPrefixBrute(vector<string>& strs) {
    if (strs.empty()) return "";
    if (strs.size() == 1) return strs[0];
    string result = "";
    for (int i = 0; i < strs[0].length(); i++) {
        for (int j = 1; j < strs.size(); j++) {
            if (i >= strs[j].length() || strs[j][i] != strs[0][i]) {
                return result;
            }
        }
        result += strs[0][i];
    }
    return result;
}
// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: 

// // Intuition : 

// 💡 Why Sorting Helps?
// When we sort the strings lexicographically, strings with common prefixes will naturally appear next to each other.
// So, the first and last strings will be the most different in the array.
// Therefore, their common prefix is the minimum LCP possible among all pairs.
// 🧠 So instead of comparing all strings pairwise (which is costly), we just compare the first and last after sorting — this is enough!

// Algo :

// TC : O(n log n * m) - due to sorting
// SC : O(1) - no extra space used for strings
class Solution {
public:
    string longestCommonPrefixOptimal(vector<string>& strs) {
    if(strs.empty()) return "";

    sort(strs.begin(), strs.end());

    string first = strs.front();
    string last = strs.back();

    int i = 0 ;
    
    while(i < first.size() && i < last.size() && first [i] == last[i]) 
    i++;

    return first.substr(0, i);
    }
};
int main()
{
    
    return 0;
}