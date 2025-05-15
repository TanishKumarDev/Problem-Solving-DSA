#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 🔍 Helper: Check if we can make all values in one row equal to target
    int check(int target, vector<int>& tops, vector<int>& bottoms) {
        int rotateTop = 0, rotateBottom = 0;
        for (int i = 0; i < tops.size(); ++i) {
            if (tops[i] != target && bottoms[i] != target) return -1; // ❌ not possible
            else if (tops[i] != target) rotateTop++;      // ✅ need to rotate top
            else if (bottoms[i] != target) rotateBottom++; // ✅ need to rotate bottom
        }
        return min(rotateTop, rotateBottom); // 🧠 minimum of both
    }

    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        // 🧠 Check using tops[0] as target
        int ans = check(tops[0], tops, bottoms);

        // ✅ If valid or both first top and bottom are same
        if (ans != -1 || tops[0] == bottoms[0]) return ans;

        // 🧠 Else check using bottoms[0] as target
        return check(bottoms[0], tops, bottoms);
    }
};

// 1️⃣ Your Thought Process
// “Count using hash the number of times every number (1–6) occurs in tops and bottoms. The number with the maximum total count (say 2) — making other entries equal to it would need fewer operations.”

// 2️⃣ My Thought Process Summary = initially I thought of using a hash map to count occurrences of each number in both tops and bottoms. But then I realized that we can just use the first element of tops and bottoms as the target and check if we can make all elements equal to it. If not, we can check the other element as the target.
// This way we can avoid using extra space for counting occurrences. The check function will return the minimum number of rotations needed to make all elements equal to the target. If it's not possible, it will return -1.

// 1. Count occurrences of elements in tops.
// 2. Find max occurring number, say x, in tops.
// 3. Identify indices where tops[i] != x → mismatches.
// 4. Check if at those indices bottoms[i] == x → if yes, then we can rotate/swaps to bring x on top.
// 5. If not, then making top all x is not possible.
// Do same logic for bottoms to check if we can make bottom all x.

// ✅ Time, Space Complexity
// Count occurrences: O(n)
// Check mismatches: O(n)
// Rotate check: O(n)
// tc = O(n) + O(n) + O(n) = O(3n) = O(n)
// sc = O(1) + O(1) + O(1) = O(3) = O(1)
