#include <bits/stdc++.h>
using namespace std;

/*
🤔 Problem Samjho Pehle:
Tere paas ek 2 x n board hai.
Aur tere paas 2 tarah ke tile hain:
1. Ek simple domino (2x1) — ya toh seedha (vertical) ya leta ke (horizontal) laga sakta hai.
2. Ek L-shape tromino — 3 blocks ka piece, jo 4 tarah se rotate ho sakta hai.

💡 Intuition:
1. Chhoti value ka manually count karke pattern dekh:
   - n = 1 → Sirf 1 vertical domino laga sakta hai → 1 tareeka
   - n = 2 → 2 vertical ya 2 horizontal → 2 tareeke
   - n = 3 → 5 tareeke:
        - 3 vertical
        - 1 horizontal + 1 vertical
        - Tromino ke 4 rotation wale combinations

2. Pattern samajh:
   - Agar tu n-1 tak tile kar chuka hai → ab 2 aur tareeke milte hain:
       → ek vertical domino ya ek tromino (jo 2 variations deta hai)
       → isliye 2 * dp[n-1]
   - Agar tu n-3 tak tile kar chuka hai → ek tromino jo pura 3 blocks ka hota hai woh laga de
       → isliye + dp[n-3]

3. Final recurrence banta hai:
   ✅ dp[n] = 2 * dp[n-1] + dp[n-3]

4. Memoization kyun?
   - Same cheez baar baar calculate na ho, ek baar kar ke store kar lo — isliye top-down DP (recursion + memo)

5. Modulo kyun?
   - Bada answer aa sakta hai, toh 10^9 + 7 ka mod lena padta hai — Leetcode ka default pattern

*/

// ✅ Top-down (Recursion + Memoization)
class SolutionMemo {
public:
    const int MOD = 1e9 + 7;
    int dp[1001]; // 0-based indexing ke liye 1001 size

    int solve(int n) {
        // Base cases
        if (n == 0) return 1;    // 1 way — kuch bhi mat karo
        if (n == 1) return 1;    // Sirf ek vertical domino
        if (n == 2) return 2;    // 2 vertical ya 2 horizontal
        if (n == 3) return 5;    // Manually count kiya hua

        // Agar already calculate ho chuka hai
        if (dp[n] != -1) return dp[n];

        // dp[n] = 2 * dp[n-1] + dp[n-3]
        return dp[n] = (2LL * solve(n - 1) % MOD + solve(n - 3) % MOD) % MOD;
    }

    int numTilings(int n) {
        memset(dp, -1, sizeof(dp));  // dp array initialize -1 se
        return solve(n);
    }
};

// ✅ Bottom-up DP (Tabulation)
class SolutionTabu {
public:
    const int MOD = 1e9 + 7;

    int numTilings(int n) {
        if (n == 1) return 1;
        if (n == 2) return 2;
        if (n == 3) return 5;

        vector<int> dp(n + 1, 0);
        dp[0] = 1;       // Important for recurrence
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for (int i = 4; i <= n; i++) {
            dp[i] = (2LL * dp[i - 1] % MOD + dp[i - 3] % MOD) % MOD;
        }

        return dp[n];
    }
};

/*
Time Complexity: O(n)
Chahe memo ho ya tabulation, har value sirf ek baar calculate ho rahi hai.
isliye total time O(n)

Space Complexity:
Memoization: O(n) dp array + O(n) recursion stack = O(n)
Tabulation: O(n) for dp vector
Bonus: Space optimize bhi kar sakte hain using 3 variables only 
*/

int main() {
    SolutionMemo sol1;
    SolutionTabu sol2;

    int n = 5;
    cout << "Memoization: " << sol1.numTilings(n) << endl;
    cout << "Tabulation: " << sol2.numTilings(n) << endl;

    return 0;
}
