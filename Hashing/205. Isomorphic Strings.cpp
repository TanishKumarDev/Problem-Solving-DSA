class Solution {
public:
    bool isIsomorphic(string s, string t) {
        // Step 1: If lengths mismatch, not isomorphic
        if (s.length() != t.length()) return false;

        unordered_map<char, char> map1; // Map from s → t
        unordered_map<char, char> map2; // Map from t → s (for reverse check)

        // Step 2: Traverse both strings
        for (int i = 0; i < s.length(); i++) {
            char ch1 = s[i];
            char ch2 = t[i];

            // If ch1 is already mapped
            if (map1.find(ch1) != map1.end()) {
                // Check if it maps correctly to ch2
                if (map1[ch1] != ch2) return false;
            } 
            else {
                // If ch2 is already mapped to someone else in reverse map
                if (map2.find(ch2) != map2.end() && map2[ch2] != ch1) 
                    return false;

                // Create both mappings
                map1[ch1] = ch2;
                map2[ch2] = ch1;
            }
        }

        // All characters mapped correctly
        return true;
    }
};
