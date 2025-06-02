#include <bits/stdc++.h>
using namespace std;

/*
LeetCode Problem 135: Candy
Link: https://leetcode.com/problems/candy/

Problem Description:
There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
You are giving candies to these children subjected to the following requirements:
1. Each child must have at least one candy.
2. Children with a higher rating get more candies than their neighbors.

Return the minimum number of candies you need to have to distribute the candies to the children.

Example 1:
Input: ratings = [1,0,2]
Output: 5
Explanation: You can allocate to the first, second and third child with 2, 1, 2 candies respectively.

Example 2:
Input: ratings = [1,2,2]
Output: 4
Explanation: You can allocate to the first, second and third child with 1, 2, 1 candies respectively.
The third child gets 1 candy because it satisfies the above two conditions.

Constraints:
- n == ratings.length
- 1 <= n <= 2 * 10^4
- 0 <= ratings[i] <= 2 * 10^4
*/

/*
🔍 Approach 1: Brute Force (Iterative Adjustment)

Intuition:
- Start by giving each child 1 candy
- Keep checking and adjusting until no more changes are needed
- If a child has a higher rating than their neighbor but fewer candies, give them more candies
- This is like fixing things one by one until everything is correct

Time Complexity: O(n²) - in worst case, might need n iterations
Space Complexity: O(n) - for storing candies
*/

class BruteForceSolution {
public:
    int candy_brute(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        bool updated = true;
        
        while (updated) {
            updated = false;
            for (int i = 0; i < n; i++) {
                // Check left neighbor
                if (i > 0 && ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1]) {
                    candies[i] = candies[i - 1] + 1;
                    updated = true;
                }
                // Check right neighbor
                if (i < n - 1 && ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1]) {
                    candies[i] = candies[i + 1] + 1;
                    updated = true;
                }
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

/*
⚡ Approach 2: Single Pass Greedy (Incorrect but Educational)

Intuition:
- Try to solve in one pass from left to right
- If current child has higher rating than previous, give one more candy
- This approach fails because it only looks at left neighbors
- It doesn't handle right neighbors properly, so it's incorrect

Time Complexity: O(n)
Space Complexity: O(n)
*/

class SinglePassSolution {
public:
    int candy_singlePass(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        // Only check left neighbors
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

/*
🎯 Approach 3: Two-Pass Greedy (Optimal)

Intuition:
- Use two passes to handle both neighbors properly
- First pass (left to right): Handle left neighbor condition
- Second pass (right to left): Handle right neighbor condition
- Take maximum of both passes to satisfy all conditions
- This ensures each child gets enough candies compared to both neighbors

Time Complexity: O(n)
Space Complexity: O(n)
*/

class TwoPassSolution {
public:
    int candy_twoPass(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> candies(n, 1);
        
        // First pass: left to right
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {
                candies[i] = candies[i - 1] + 1;
            }
        }
        
        // Second pass: right to left
        for (int i = n - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1]) {
                candies[i] = max(candies[i], candies[i + 1] + 1);
            }
        }
        
        return accumulate(candies.begin(), candies.end(), 0);
    }
};

/*
🚀 Approach 4: Space Optimized (Advanced)

Intuition:
- Count sequences of increasing and decreasing ratings
- Calculate candies based on sequence lengths
- Handle peaks (highest points) and valleys (lowest points) efficiently
- More complex but uses less space
- Instead of storing candies for each child, we calculate total directly

Time Complexity: O(n)
Space Complexity: O(1) - excluding input array
*/

class SpaceOptimizedSolution {
public:
    int candy_optimized(vector<int>& ratings) {
        int n = ratings.size();
        if (n <= 1) return n;
        
        int total = 1;  // First child gets 1 candy
        int up = 0, down = 0;  // Track length of increasing/decreasing sequences
        int peak = 0;  // Track the highest point in current sequence
        
        for (int i = 1; i < n; i++) {
            if (ratings[i] > ratings[i - 1]) {  // Going up
                up++;
                down = 0;
                peak = up;
                total += up + 1;
            } else if (ratings[i] == ratings[i - 1]) {  // Equal ratings
                up = down = peak = 0;
                total += 1;
            } else {  // Going down
                down++;
                up = 0;
                total += down + (down >= peak ? 1 : 0);
            }
        }
        
        return total;
    }
};
