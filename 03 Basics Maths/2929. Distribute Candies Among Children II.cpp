#include <bits/stdc++.h>
using namespace std;

/*
🔍 Approach 1: Recursive (Brute Force)

Intuition:
- Use recursion to try all possible candy assignments for each child
- Base case: when all 3 children are assigned candies
- For each child, try assigning 0 to limit candies

Desi Analogy:
- Soch, tu ek ek karke har bachche ko candy de raha hai, aur har possibility try kar raha hai
- Jaise ek family mein 3 bachche hain, aur tu unhe candy distribute kar raha hai

Time Complexity: O(limit³) - each child can get 0 to limit candies
Space Complexity: O(limit) - recursion stack depth
*/

class RecursiveSolution {
public:
    long long solve(int count, int remaining, int limit) {
        // Base case: all children assigned
        if (count == 3) {
            return (remaining == 0) ? 1 : 0;
        }
        
        long long ways = 0;
        // Try assigning 0 to min(remaining, limit) candies
        for (int i = 0; i <= min(remaining, limit); i++) {
            ways += solve(count + 1, remaining - i, limit);
        }
        return ways;
    }
    
    long long distributeCandies_recursive(int n, int limit) {
        return solve(0, n, limit);
    }
};

/*
⚡ Approach 2: Iterative Brute Force (Three Loops)

Intuition:
- Use three nested loops to try all possible combinations
- For each child, try assigning 0 to min(n, limit) candies
- Check if sum equals n for valid distribution

Desi Analogy:
- Soch, tu ek table pe 3 bachche baithe hain, aur tu har bachche ko ek ek karke candy de raha hai
- Har possibility try karta hai, jaise pehle bachche ko 0-2, fir doosre ko 0-2, fir teesre ko 0-2

Time Complexity: O(m³) where m = min(n, limit)
Space Complexity: O(1)
*/

class ThreeLoopSolution {
public:
    long long distributeCandies_threeLoops(int n, int limit) {
        long long ways = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            for (int j = 0; j <= min(n - i, limit); j++) {
                for (int k = 0; k <= min(n - i - j, limit); k++) {
                    if (i + j + k == n) {
                        ways++;
                    }
                }
            }
        }
        return ways;
    }
};

/*
🎯 Approach 3: Optimized Iterative (Two Loops)

Intuition:
- Reduce to two loops by computing third child's candies directly
- For each valid assignment of first two children, check if third child's candies are valid

Desi Analogy:
- Soch, tu pehle do bachcho ko candy de raha hai, aur teesre bachche ke liye automatically calculate kar raha hai
- Jaise pehle do bachcho ko 0-2 candy de, aur teesre ko bacha hua candy de

Time Complexity: O(m²) where m = min(n, limit)
Space Complexity: O(1)
*/

class TwoLoopSolution {
public:
    long long distributeCandies_twoLoops(int n, int limit) {
        long long ways = 0;
        for (int i = 0; i <= min(n, limit); i++) {
            for (int j = 0; j <= min(n - i, limit); j++) {
                int k = n - i - j;
                if (k >= 0 && k <= limit) {
                    ways++;
                }
            }
        }
        return ways;
    }
};

/*
🚀 Approach 4: Linear (Optimal)

Intuition:
- Use mathematical formula to calculate valid ways in one pass
- For each valid assignment of first child, calculate valid ways for remaining two children
- Use range calculations to find valid assignments efficiently

Desi Analogy:
- Soch, tu ek hi baar mein calculate kar raha hai ki kitne tarike se candy distribute kar sakte hain
- Jaise pehle bachche ko 0-2 candy de, aur bache hue candy ko do bachcho mein distribute karne ke tarike calculate kar

Time Complexity: O(n)
Space Complexity: O(1)
*/

class OptimalSolution {
public:
    long long distributeCandies_optimal(int n, int limit) {
        long long ways = 0;
        // Calculate range for first child
        int minCH1 = max(0, n - 2 * limit);
        int maxCH1 = min(n, limit);
        
        // For each valid assignment of first child
        for (int i = minCH1; i <= maxCH1; i++) {
            int remaining = n - i;
            // Calculate range for second child
            int minCH2 = max(0, remaining - limit);
            int maxCH2 = min(remaining, limit);
            // Add valid ways for second and third child
            ways += (long long)(maxCH2 - minCH2 + 1);
        }
        return ways;
    }
};

/*
🧪 Testing all approaches
*/
int main() {
    // Test cases
    vector<pair<int, int>> testCases = {
        {5, 2},  // Example 1
        {3, 3},  // Example 2
        {10, 5}, // Additional test case
    };
    
    RecursiveSolution recursive;
    ThreeLoopSolution threeLoop;
    TwoLoopSolution twoLoop;
    OptimalSolution optimal;
    
    for (auto& [n, limit] : testCases) {
        cout << "Testing n=" << n << ", limit=" << limit << ":\n";
        
        cout << "Recursive Approach: ";
        cout << recursive.distributeCandies_recursive(n, limit) << "\n";
        
        cout << "Three Loop Approach: ";
        cout << threeLoop.distributeCandies_threeLoops(n, limit) << "\n";
        
        cout << "Two Loop Approach: ";
        cout << twoLoop.distributeCandies_twoLoops(n, limit) << "\n";
        
        cout << "Optimal Approach: ";
        cout << optimal.distributeCandies_optimal(n, limit) << "\n\n";
    }
    
    return 0;
}
