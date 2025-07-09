#include <bits/stdc++.h>
using namespace std;


// 🔴 Approach 1 
class Solution {
public:
    string reversePrefix(string word, char ch) {
    
        int j = -1; // To store the index of the first occurrence of 'ch'

        // Step 1: Find the first occurrence of character 'ch'
        for (int i = 0; i < word.length(); i++) {
            if (word[i] == ch) {
                j = i;      // Store the index where 'ch' is found
                break;      // No need to go further after first match
            }
        }

        // Step 2: If 'ch' is not found, return the original string
        if (j == -1) return word;

        // Step 3: Reverse the substring from index 0 to j
        int left = 0, right = j;
        while (left < right) {
            swap(word[left], word[right]);
            left++;
            right--;
        }

        // Step 4: Return the modified string
        return word;
    }
};


// 🔵 Approach 2 
string reversePrefixLibrary(string word, char ch) {
    // Use string::find to locate the first occurrence of character 'ch'
    size_t j = word.find(ch); 
    
    // If character not found, return the original word
    if (j == string::npos) return word;

    // Reverse the prefix from start to index j (inclusive)
    reverse(word.begin(), word.begin() + j + 1);

    // Return the updated word
    return word;
}

int main()
{
    
    return 0;
}