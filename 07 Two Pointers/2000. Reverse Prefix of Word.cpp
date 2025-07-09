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
