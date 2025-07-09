class Solution {
public:
    int scoreOfString(string s) {
        int score = 0;  // Initialize score to 0

        // Loop through the string till the second last character
        for(int i = 0; i < s.size() - 1; i++) {
            // Add the absolute difference between ASCII values of adjacent characters
            score += abs(s[i] - s[i + 1]);
        }

        return score; // Return the final score
    }
};

/*
NOTE:

1. Why?  i < s.size() - 1

    score += abs(s[i] - s[i + 1]);

    So if you looped until i < s.size(), then s[i + 1] on the last iteration would go out of bounds, causing a runtime error (undefined behavior).

    Input: s = "hello" → length = 5
    Indexes:        0   1   2   3   4  
    Characters:     h   e   l   l   o


    abs('h' - 'e') → |104 - 101| = 3  
    abs('e' - 'l') → |101 - 108| = 7  
    abs('l' - 'l') → |108 - 108| = 0  
    abs('l' - 'o') → |108 - 111| = 3

    ✅ These are the 4 adjacent pairs, which means we only need to loop from i = 0 to i = 3.

    That’s exactly what i < s.size() - 1 ensures:

    s.size() = 5

    s.size() - 1 = 4

    So loop runs for i = 0, 1, 2, 3

2. Important Fact:
    In C++ (and most languages), characters are internally stored as integers (ASCII values).
    So, you can directly do math on characters like this:

    char ch = 'h'; // ASCII of 'h' = 104
    cout << (int)ch; // prints 104

    ⚡ s[i] and s[i+1] are chars, but when you do subtraction,
    they are implicitly converted to int, and you get their ASCII difference.

*/