#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1
// TC : O(n)
// SC : O(n)
class Solution {
public:
    // Helper function for recursion
    void helper(vector<char>& s, int left, int right) {
        // Base case: when pointers meet or cross
        if (left >= right) return;

        // Swap current pair
        swap(s[left], s[right]);

        // Recursive call on the inner substring
        helper(s, left + 1, right - 1);
    }

    void reverseString(vector<char>& s) {
        helper(s, 0, s.size() - 1);
    }
};

// 🔵 Approach 2 
// TC : O(n)
// SC : O(1)
class Solution {
public:
    void reverseString(vector<char>& s) {
        int left = 0;
        int right = s.size() - 1;

        // Move both pointers toward the center
        while (left < right) {
            // Swap the characters at left and right
            swap(s[left], s[right]);

            // Move inward
            left++;
            right--;
        }
    }
};


int main()
{
    
    return 0;
}
/*

NOTE: 

helper(s, left++, right--);

❌ Problem:
Using left++ and right-- passes the original values of left and right to the next recursive call, and then increments/decrements them afterward (because ++ and -- are post-increment/post-decrement).

So the recursive call doesn’t actually receive the updated values, and the recursion gets stuck in an infinite loop (or behaves incorrectly).

✅ Fix:
Use left + 1 and right - 1 instead of left++ and right--.

*/