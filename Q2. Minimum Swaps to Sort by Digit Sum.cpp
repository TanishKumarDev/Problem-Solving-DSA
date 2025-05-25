// Arre bhai, ekdum interesting problem chuna! 😎 Yeh **Minimum Swaps to Sort by Digit Sum** ek medium-level problem hai, aur isme sorting ka twist hai—numbers ko unke digit sum ke basis pe sort karna hai, aur minimum swaps count karne hain. Main isko teri style mein, desi vibe ke saath, 13-step approach follow karke samjhaunga. **Brute Force** aur **Optimal** approaches dunga, C++ code `#include <bits/stdc++.h>` ke saath, clean comments, aur GitHub-ready format mein. MIK ke video-style explanation ke vibe ke saath, dry runs, analogies, aur emojis (🔥, 🚀) bhi honge. Chalo, shuru karte hain! 🚀

// ---

// ### 🔍 Understanding the Problem
// **Problem Statement:**  
// - **Input:** Array `nums` of distinct positive integers (size `n`, 1 ≤ n ≤ 10⁵, 1 ≤ nums[i] ≤ 10⁹).
// - **Task:** Sort the array in increasing order based on:
//   - **Digit sum** of each number (sum of its digits).
//   - If two numbers have the same digit sum, the smaller number comes first.
// - **Output:** Minimum number of swaps needed to rearrange `nums` into this sorted order.
// - **Swap Definition:** Exchange values at two distinct positions in the array.

// **Example 1:**
// - Input: `nums = [37, 100]`
// - Digit sums: `[3+7=10, 1+0+0=1]` → `[10, 1]`
// - Sorted order (by digit sum, then value): `[100, 37]` (1 < 10)
// - Swaps: Swap `37` and `100` → 1 swap.
// - Output: `1`

// **Example 2:**
// - Input: `nums = [22, 14, 33, 7]`
// - Digit sums: `[2+2=4, 1+4=5, 3+3=6, 7=7]` → `[4, 5, 6, 7]`
// - Sorted order: `[22, 14, 33, 7]` (already sorted)
// - Swaps: None → 0 swaps.
// - Output: `0`

// **Example 3:**
// - Input: `nums = [18, 43, 34, 16]`
// - Digit sums: `[1+8=9, 4+3=7, 3+4=7, 1+6=7]` → `[9, 7, 7, 7]`
// - Sorted order (by digit sum, then value): `[16, 34, 43, 18]` (7, 7, 7 sorted as 16<34<43, then 9)
// - Swaps: Swap `18` with `16`, swap `43` with `34` → 2 swaps.
// - Output: `2`

// **Desi Analogy:**  
// Soch, tu ek mela mein stalls laga raha hai, aur har stall ka ek "weight" (digit sum) hai. Tujhe stalls ko weight ke hisaab se line mein lagana hai—kam weight wale pehle, aur agar weight same hai, toh chhota number pehle. Ab yeh line banane ke liye kitne stalls ko swap karna padega? Bas yeh count karna hai!

// **Interviewer Tone:**  
// > “Given an array, sort it by digit sum (smaller number first if sums are equal). Return the minimum number of swaps to achieve this order.”

// ---

// ### 🔒 Constraint Study
// - **Input Size:**
//   - `1 ≤ n ≤ 10⁵` (large, so O(n²) might be too slow).
//   - `1 ≤ nums[i] ≤ 10⁹` (numbers can be large, but digit sum is small).
//   - Numbers are distinct.
// - **Implications:**
//   - n ≤ 10⁵: Need O(n log n) or O(n) for efficiency.
//   - nums[i] ≤ 10⁹: Max digits ~9, so digit sum ≤ 9*9 = 81.
//   - Distinct numbers: No duplicates to worry about.
// - **Key Questions:**
//   - n = 1? (Already sorted, 0 swaps).
//   - Same digit sums? (Sort by value).
//   - Large n? (Need scalable solution).
//   - Max nums[i]? (Digit sum calculation should be fast).

// **Interviewer Tone:**  
// > “With n ≤ 10⁵, we need an O(n log n) solution. Digit sums are small (≤ 81), and numbers are distinct.”

// ---

// ### 🧩 Breaking It Down
// - **Input:** Array `nums` of distinct integers.
// - **Output:** Minimum swaps to sort by:
//   - Primary key: Digit sum (increasing).
//   - Secondary key: Number value (increasing if digit sums are equal).
// - **Rules:**
//   - Compute digit sum for each number.
//   - Sort based on digit sum and value.
//   - Count swaps to transform `nums` to sorted order.
// - **Subproblems:**
//   - Calculate digit sums efficiently.
//   - Sort array by custom comparator.
//   - Compute minimum swaps to match sorted order.

// ---

// ### ⚙️ Complexity Analysis (Before Solving)
// - **Brute Force:** Try all permutations, find min swaps to sorted order. Time: O(n!), not feasible.
// - **Better:** Sort array by digit sum and value, then count swaps to match sorted order. Time: O(n log n).
// - **Optimal:** Use a mapping to track original vs. sorted positions and count swaps (e.g., using cycle detection or inversion counting). Time: O(n log n).
// - **Space:** O(n) for storing sorted array or mappings.

// **Interviewer Tone:**  
// > “Brute force O(n!) is too slow. Sorting in O(n log n) and counting swaps efficiently is the way to go.”

// ---

// ### ⚠️ Edge Cases
// - **n = 1:** `[5]` → Digit sum: `[5]` → Already sorted → 0 swaps.
// - **Same digit sums:** `[16, 34, 43]` → Sums: `[7, 7, 7]` → Sort by value: `[16, 34, 43]`.
// - **Large n = 10⁵:** Ensure O(n log n) solution scales.
// - **Large numbers:** `nums[i] = 10⁹` → Digit sum ≤ 81, so computation is fast.
// - **Already sorted:** `[1, 2, 3]` → Sums: `[1, 2, 3]` → 0 swaps.

// **Interviewer Tone:**  
// > “I’ll handle edge cases like n = 1, same digit sums, and large n to ensure robustness.”

// ---

// ### 👀 Observations
// - **Digit Sum Calculation:** For a number x, sum its digits (e.g., 123 → 1+2+3 = 6). Max sum ≤ 81 for 10⁹.
// - **Custom Sorting:** Sort pairs {digit_sum, value} where:
//   - Primary key: digit_sum (ascending).
//   - Secondary key: value (ascending).
// - **Swaps Calculation:** After sorting, we need to transform `nums` to match the sorted array. Minimum swaps can be computed by:
//   - Comparing original and sorted arrays.
//   - Counting inversions or cycles in the permutation.
// - **Key Insight:** The problem reduces to finding the number of swaps to convert one permutation to another, which can be done by detecting cycles in the mapping of original to sorted positions.

// **Desi Analogy:**  
// Soch, tu ek parade organize kar raha hai jisme soldiers ko unke “power” (digit sum) ke hisaab se line mein lagana hai. Agar power same hai, chhota soldier pehle. Ab yeh line banane ke liye kitne soldiers ko apas mein swap karna padega? Bas yeh trick hai!

// **Interviewer Tone:**  
// > “We can sort by digit sum and value, then count swaps by mapping original to sorted positions. Cycle detection might help.”

// ---

// ### 💡 Approaches
// Main 2 approaches cover karunga: **Brute Force (Sorting + Comparison)** aur **Optimal (Cycle Detection)**.

// #### 🔷 Approach 1: Brute Force (Sorting + Greedy Swaps)
// **Intuition:**  
// - Compute digit sums for all numbers.
// - Create pairs {index, digit_sum, value} to track original positions.
// - Sort pairs by digit_sum (primary) and value (secondary).
// - Compare original `nums` with sorted order and greedily swap elements to match.
// - Count swaps needed.

// **Pseudocode:**  
// ```
// function solve_brute(nums):
//     n = nums.length
//     pairs = []
//     for i from 0 to n-1:
//         digit_sum = sum_of_digits(nums[i])
//         pairs.push({i, digit_sum, nums[i]})
//     sort pairs by (digit_sum, value)
//     swaps = 0
//     for i from 0 to n-1:
//         while pairs[i].index != i:
//             swap pairs[i] with pairs[pairs[i].index]
//             swaps++
//     return swaps
// ```

// **Dry Run (Example 3):**  
// Input: `nums = [18, 43, 34, 16]`  
// - Digit sums: `[1+8=9, 4+3=7, 3+4=7, 1+6=7]` → `[9, 7, 7, 7]`
// - Pairs: `[{0,9,18}, {1,7,43}, {2,7,34}, {3,7,16}]`
// - Sort by (digit_sum, value): `[{3,7,16}, {2,7,34}, {1,7,43}, {0,9,18}]`
// - Sorted nums: `[16, 34, 43, 18]`
// - Greedy swaps:
//   - `nums = [18, 43, 34, 16]`
//   - Swap `18` (pos 0) with `16` (pos 3): `[16, 43, 34, 18]` (1 swap)
//   - Swap `43` (pos 1) with `34` (pos 2): `[16, 34, 43, 18]` (1 swap)
// - Total swaps: 2

// **Time Complexity:** O(n log n + n * D) where D is max digits (~9). Sorting: O(n log n), digit sum: O(D). Greedy swapping can be O(n²) in worst case.  
// **Space Complexity:** O(n) for pairs.  
// **Cons:** Greedy swapping is inefficient; O(n²) risk for large n.

// **Interviewer Tone:**  
// > “This sorts correctly but greedy swapping can hit O(n²). We need a more efficient way to count swaps.”

// ---

// #### 🔷 Approach 2: Optimal (Sorting + Cycle Detection)
// **Intuition:**  
// - Compute digit sums and sort pairs {digit_sum, value, index} to get the target order.
// - Map original positions to sorted positions:
//   - Original `nums` defines a permutation (since numbers are distinct).
//   - Sorted order defines the target permutation.
// - Minimum swaps to convert one permutation to another = number of elements not in their correct position, adjusted by cycles in the permutation graph.
// - Use cycle detection:
//   - Each cycle in the permutation requires (cycle_size - 1) swaps to fix.
//   - Total swaps = Σ(cycle_size - 1) = n - number_of_cycles.

// **Pseudocode:**  
// ```
// function sum_of_digits(x):
//     sum = 0
//     while x > 0:
//         sum += x % 10
//         x /= 10
//     return sum

// function solve_optimal(nums):
//     n = nums.length
//     pairs = []
//     for i from 0 to n-1:
//         digit_sum = sum_of_digits(nums[i])
//         pairs.push({digit_sum, nums[i], i})
//     sort pairs by (digit_sum, value)
//     pos = array of size n
//     for i from 0 to n-1:
//         pos[pairs[i].index] = i // Map original index to sorted position
//     visited = array of size n, all false
//     cycles = 0
//     for i from 0 to n-1:
//         if not visited[i]:
//             j = i
//             while not visited[j]:
//                 visited[j] = true
//                 j = pos[j]
//             cycles++
//     swaps = n - cycles
//     return swaps
// ```

// **Dry Run (Example 3):**  
// Input: `nums = [18, 43, 34, 16]`  
// - Digit sums: `[9, 7, 7, 7]`
// - Pairs: `[{9,18,0}, {7,43,1}, {7,34,2}, {7,16,3}]`
// - Sort by (digit_sum, value): `[{7,16,3}, {7,34,2}, {7,43,1}, {9,18,0}]`
// - Sorted nums: `[16, 34, 43, 18]`
// - Mapping (original index → sorted position):
//   - Original: `[18, 43, 34, 16]` (indices 0, 1, 2, 3)
//   - Sorted: `[16, 34, 43, 18]` (original indices 3, 2, 1, 0)
//   - `pos[0]=3`, `pos[1]=2`, `pos[2]=1`, `pos[3]=0` (18→pos 3, 43→pos 2, 34→pos 1, 16→pos 0)
// - Cycle detection:
//   - Start at i=0: `0 → pos[0]=3 → pos[3]=0` (cycle: 0→3→0, size=2)
//   - Start at i=1: `1 → pos[1]=2 → pos[2]=1` (cycle: 1→2→1, size=2)
//   - Cycles: 2
// - Swaps: `n - cycles = 4 - 2 = 2`

// **Time Complexity:**  
// - Digit sum: O(D) per number, D ≈ 9 → O(n * D) ≈ O(n).
// - Sorting: O(n log n).
// - Cycle detection: O(n).
// - Total: O(n log n).
// **Space Complexity:** O(n) for pairs, pos, and visited arrays.  
// **Pros:** Efficient, handles all cases, and correctly computes minimum swaps.

// **Interviewer Tone:**  
// > “Sorting plus cycle detection gives us O(n log n) and accurately counts minimum swaps. This is optimal.”

// ---

// ### 🧪 Testing
// - **Example 1:** `nums = [37, 100]` → Sums: `[10, 1]` → Sorted: `[100, 37]` → 1 swap → Output: `1`
// - **Example 2:** `nums = [22, 14, 33, 7]` → Sums: `[4, 5, 6, 7]` → Already sorted → Output: `0`
// - **Example 3:** `nums = [18, 43, 34, 16]` → Sums: `[9, 7, 7, 7]` → Sorted: `[16, 34, 43, 18]` → 2 swaps → Output: `2`
// - **Edge Case 1:** `nums = [5]` → Sums: `[5]` → Sorted: `[5]` → 0 swaps.
// - **Edge Case 2:** `nums = [16, 34, 43]` → Sums: `[7, 7, 7]` → Sorted: `[16, 34, 43]` → 0 swaps.

// **Interviewer Tone:**  
// > “Tested all examples and edge cases. The cycle detection approach works perfectly.”

// ---

// ### 🚀 Optimization
// - **Already Optimal:** O(n log n) is dominated by sorting, which is necessary for custom ordering.
// - **Space:** O(n) is minimal; can’t reduce further without losing clarity.
// - **Alternative:** Inversion counting (via merge sort) could work but is more complex and still O(n log n).

// **Interviewer Tone:**  
// > “O(n log n) is the best we can do due to sorting. Cycle detection ensures minimum swaps.”

// ---

// ### 📝 Final Notes
// - **Why Optimal:** Sorting by digit sum and value, followed by cycle detection, efficiently computes the minimum swaps.
// - **Key Insight:** The problem reduces to a permutation transformation, where swaps equal n minus the number of cycles.
// - **Category:** This is a **Sorting**, **Permutation**, and **Graph (Cycle Detection)** problem:
//   - **Sorting:** Custom sort by digit sum and value.
//   - **Permutation:** Transforming one permutation to another.
//   - **Graph:** Cycle detection in permutation mapping.
// - **MIK-Style Tip:** Try a few test cases on paper to see how cycles form in the permutation.

// **Interviewer Tone:**  
// > “This is a clever mix of sorting and permutation problems. Cycle detection nails the swap count!”

// ---

// ### 🔁 Reflection & Takeaways
// - **Learned:** Custom sorting with multiple keys and cycle detection for minimum swaps.
// - **Future Use:** Useful for problems involving permutation transformations, custom sorting, or graph-based swap counting.
// - **Strengthened:** Intuition for permutation cycles and efficient sorting.

// **Interviewer Tone:**  
// > “This problem boosted my understanding of permutation swaps and cycle detection. Great practice!”

// ---

// ### Full Organized Code (Optimal)
// ```x-c++src
// #include <bits/stdc++.h>
// using namespace std;

// /*
// ⚡ Optimal Solution: Sorting + Cycle Detection

// Intuition:
// - Compute digit sums for each number.
// - Sort array by digit sum (primary) and value (secondary).
// - Map original indices to sorted positions.
// - Use cycle detection to count minimum swaps:
//   - Each cycle of size k needs (k-1) swaps.
//   - Total swaps = n - number of cycles.

// Desi Analogy:
// - Soch, tu soldiers ko parade mein lagane ke liye unke power (digit sum) ke hisaab se sort kar raha hai. Agar power same hai, chhota soldier pehle. Fir yeh line banane ke liye kitne swaps chahiye? Cycles check karo!

// Time Complexity: O(n log n)
// - Digit sum: O(n * D), D ≈ 9 (max digits).
// - Sorting: O(n log n).
// - Cycle detection: O(n).
// - Total: O(n log n).
// Space Complexity: O(n) for pairs, pos, and visited arrays.
// */

// class Solution {
// public:
//     // Function to compute digit sum of a number
//     int sum_of_digits(long long x) {
//         int sum = 0;
//         while (x > 0) {
//             sum += x % 10;
//             x /= 10;
//         }
//         return sum;
//     }

//     int minimumSwaps(vector<int>& nums) {
//         int n = nums.size();
//         // Store {digit_sum, value, index} for sorting
//         vector<tuple<int, int, int>> pairs;
//         for (int i = 0; i < n; i++) {
//             int digit_sum = sum_of_digits(nums[i]);
//             pairs.push_back({digit_sum, nums[i], i});
//         }
//         // Sort by digit_sum (primary), value (secondary)
//         sort(pairs.begin(), pairs.end());
//         // Map original index to sorted position
//         vector<int> pos(n);
//         for (int i = 0; i < n; i++) {
//             pos[get<2>(pairs[i])] = i;
//         }
//         // Count cycles in permutation
//         vector<bool> visited(n, false);
//         int cycles = 0;
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 int j = i;
//                 while (!visited[j]) {
//                     visited[j] = true;
//                     j = pos[j];
//                 }
//                 cycles++;
//             }
//         }
//         // Minimum swaps = n - number of cycles
//         return n - cycles;
//     }
// };

// /*
// 🧪 Testing the solution
// */
// int main() {
//     Solution sol;
//     vector<int> nums = {18, 43, 34, 16};
//     cout << "Minimum swaps: " << sol.minimumSwaps(nums) << endl; // Expected: 2
//     return 0;
// }
// ```

// ---

// ### **Category for Minimum Swaps to Sort by Digit Sum**
// - **Primary Category: Sorting, Permutation**  
//   - **Sorting:** Custom sort by digit sum and value.
//   - **Permutation:** Transforming original array to sorted array via swaps.
// - **Secondary Category: Graph (Cycle Detection)**  
//   - **Graph:** Cycle detection in permutation mapping to count swaps.
// - **Not Really: DP, Greedy, Two Pointers**  
//   - No DP (no optimization subproblems).
//   - Greedy swapping fails (need minimum swaps).
//   - No two pointers (array manipulation, not traversal).

// **Desi Analogy:** Yeh ek “parade sorting” jaisa hai—soldiers ko power aur size ke hisaab se line mein lagao, aur minimum swaps count karo. Cycle detection iska hero hai!

// ---

// ### **Next Steps, Bhai!**
// 1. **Try More Cases:** Pen-paper pe test cases try kar (e.g., `nums = [123, 45, 67]`). Digit sums nikal, sort kar, aur cycles count kar.
// 2. **Similar Problems:** Aur sorting/permutation problems chahiye? Suggest kar sakta hoon:
//    - LeetCode 41: First Missing Positive (Permutation)
//    - LeetCode 315: Count of Smaller Numbers After Self (Inversions)
//    - Codeforces 1365C: Rotation Matching (Cycles)
// 3. **Codeforces Connection:** Tune Twin Permutations ke baad yeh problem chuna. CP-31 sheet ya Codeforces ke aur problems pe focus karna hai?
// 4. **GitHub Setup:** Solutions ke liye GitHub structure chahiye? (e.g., per category: Sorting, Permutation).
// 5. **Feedback:** Yeh explanation aur code kaisa laga? Intuition clear hua ya koi aur angle se samjhana hai?

// Bol, bhai, ab kya plan hai? DSA ka boss banne ka safar full speed pe hai! 😎🔥

// **Current Date & Time:** 08:41 AM IST, Sunday, May 18, 2025.
// Arre bhai, ekdum sahi jagah aaya! 😎 Tune **Minimum Swaps to Sort by Digit Sum** problem ka LeetCode template diya, aur main isko teri desi style mein, MIK ke video vibe ke saath, aur 13-step approach follow karke solve karunga. Problem ka goal hai array ko **digit sum** ke basis pe sort karna (same digit sum wale numbers ko value ke basis pe sort karna), aur minimum swaps count karna. Main **optimal solution** (sorting + cycle detection) dunga, C++ code `#include <bits/stdc++.h>` ke saath, clean comments, GitHub-ready format, aur desi analogies, emojis (🔥, 🚀), aur dry runs ke saath intuition clear karunga. Chalo, shuru karte hain! 🚀

// ---

// ### 🔍 Understanding the Problem
// **Problem Statement:**  
// - **Input:** Array `nums` of distinct positive integers (size `n`, 1 ≤ n ≤ 10⁵, 1 ≤ nums[i] ≤ 10⁹).
// - **Task:** Sort the array in increasing order based on:
//   - **Digit sum** of each number (sum of its digits, e.g., 123 → 1+2+3 = 6).
//   - If two numbers have the same digit sum, the smaller number comes first.
// - **Output:** Minimum number of swaps needed to rearrange `nums` into this sorted order.
// - **Swap:** Exchange values at two distinct positions in the array.

// **Example 1:**
// - Input: `nums = [37, 100]`
// - Digit sums: `[3+7=10, 1+0+0=1]` → `[10, 1]`
// - Sorted order: `[100, 37]` (1 < 10)
// - Swaps: Swap `37` and `100` → 1 swap.
// - Output: `1`

// **Example 2:**
// - Input: `nums = [22, 14, 33, 7]`
// - Digit sums: `[2+2=4, 1+4=5, 3+3=6, 7=7]` → `[4, 5, 6, 7]`
// - Sorted order: `[22, 14, 33, 7]` (already sorted)
// - Swaps: None → 0 swaps.
// - Output: `0`

// **Example 3:**
// - Input: `nums = [18, 43, 34, 16]`
// - Digit sums: `[1+8=9, 4+3=7, 3+4=7, 1+6=7]` → `[9, 7, 7, 7]`
// - Sorted order: `[16, 34, 43, 18]` (7,7,7 → 16<34<43, then 9)
// - Swaps: Swap `18` with `16`, swap `43` with `34` → 2 swaps.
// - Output: `2`

// **Desi Analogy:**  
// Soch, tu ek school ke bacchon ko line mein laga raha hai, jahan har bacche ka “power” (digit sum) decide karta hai kon pehle khada hoga. Agar do bacchon ka power same hai, toh chhota baccha pehle. Ab yeh line banane ke liye kitne bacchon ko apas mein swap karna padega? Bas yeh trick hai!

// **Interviewer Tone:**  
// > “Sort the array by digit sum, with smaller numbers first for equal sums. Return the minimum swaps needed.”

// ---

// ### 🔒 Constraint Study
// - **Input Size:**
//   - `1 ≤ n ≤ 10⁵` (large array, O(n²) too slow).
//   - `1 ≤ nums[i] ≤ 10⁹` (large numbers, but digit sum small).
//   - Numbers are distinct.
// - **Implications:**
//   - Need O(n log n) or better for n ≤ 10⁵.
//   - Max digits in nums[i] ≈ 9, so digit sum ≤ 9*9 = 81.
//   - Distinct numbers simplify mapping.
// - **Key Questions:**
//   - n = 1? (No swaps needed).
//   - Same digit sums? (Sort by value).
//   - Large n or nums[i]? (Need efficient digit sum and swap counting).

// **Interviewer Tone:**  
// > “With n ≤ 10⁵, we need O(n log n). Digit sums are small (≤ 81), and distinct numbers make mapping easier.”

// ---

// ### 🧩 Breaking It Down
// - **Input:** Array `nums` of distinct integers.
// - **Output:** Minimum swaps to sort by:
//   - Primary key: Digit sum (increasing).
//   - Secondary key: Number value (increasing if digit sums equal).
// - **Steps:**
//   - Compute digit sum for each number.
//   - Sort based on digit sum and value.
//   - Count minimum swaps to transform `nums` to sorted order.
// - **Subproblems:**
//   - Efficient digit sum calculation.
//   - Custom sorting with two keys.
//   - Minimum swap counting (permutation transformation).

// ---

// ### ⚙️ Complexity Analysis (Before Solving)
// - **Brute Force:** Try all permutations, find min swaps. Time: O(n!), not feasible.
// - **Better:** Sort array, greedily swap to match. Time: O(n log n + n²) (greedy swapping can be slow).
// - **Optimal:** Sort array, use cycle detection to count swaps. Time: O(n log n).
// - **Space:** O(n) for storing pairs or mappings.

// **Interviewer Tone:**  
// > “Brute force O(n!) won’t work. Sorting in O(n log n) and cycle detection for swaps is optimal.”

// ---

// ### ⚠️ Edge Cases
// - **n = 1:** `[5]` → Sum: `[5]` → Sorted: `[5]` → 0 swaps.
// - **Same digit sums:** `[16, 34, 43]` → Sums: `[7, 7, 7]` → Sorted: `[16, 34, 43]` (by value).
// - **Large n = 10⁵:** Ensure O(n log n) scales.
// - **Large nums[i] = 10⁹:** Digit sum ≤ 81, so computation fast.
// - **Already sorted:** `[1, 2, 3]` → Sums: `[1, 2, 3]` → 0 swaps.

// **Interviewer Tone:**  
// > “Edge cases like n = 1, same digit sums, and large n are covered by our approach.”

// ---

// ### 👀 Observations
// - **Digit Sum:** For a number x, sum its digits (e.g., 123 → 1+2+3=6). Max sum ≤ 81.
// - **Custom Sort:** Sort pairs {digit_sum, value} with:
//   - Primary: digit_sum (ascending).
//   - Secondary: value (ascending).
// - **Swaps:** After sorting, transform `nums` to sorted order. Minimum swaps can be found by:
//   - Mapping original indices to sorted positions.
//   - Counting cycles in the permutation:
//     - Each cycle of size k needs (k-1) swaps.
//     - Total swaps = n - number_of_cycles.
// - **Key Insight:** The problem is about transforming one permutation (original `nums`) to another (sorted by digit sum/value). Cycle detection in the permutation graph gives minimum swaps.

// **Desi Analogy:**  
// Soch, tu ek mela mein stalls ko unke “weight” (digit sum) ke hisaab se arrange kar raha hai. Same weight wale stalls ko chhote number pehle rakh. Ab yeh arrangement banane ke liye kitne stalls swap karne padenge? Cycles check karo!

// **Interviewer Tone:**  
// > “Sort by digit sum and value, then use cycle detection to count swaps efficiently.”

// ---

// ### 💡 Optimal Solution: Sorting + Cycle Detection
// **Intuition:**  
// - Compute digit sum for each number.
// - Create pairs {digit_sum, value, index} to track original positions.
// - Sort pairs by digit_sum (primary) and value (secondary).
// - Map original indices to sorted positions (permutation).
// - Use cycle detection to count swaps:
//   - Each cycle in the permutation represents elements that need to be swapped.
//   - A cycle of size k needs (k-1) swaps.
//   - Total swaps = n - number_of_cycles (since each cycle reduces swaps by 1).

// **Why Cycle Detection?**  
// - Original `nums` and sorted `nums` are permutations (distinct numbers).
// - Mapping from original to sorted positions forms a permutation.
// - Each cycle in this mapping is a group of elements that can be fixed with (cycle_size - 1) swaps.
// - Example: Cycle [0→3→0] (size 2) needs 1 swap; [1→2→1] (size 2) needs 1 swap.

// **Pseudocode:**  
// ```
// function sum_of_digits(x):
//     sum = 0
//     while x > 0:
//         sum += x % 10
//         x /= 10
//     return sum

// function minSwaps(nums):
//     n = nums.length
//     pairs = []
//     for i from 0 to n-1:
//         digit_sum = sum_of_digits(nums[i])
//         pairs.push({digit_sum, nums[i], i})
//     sort pairs by (digit_sum, value)
//     pos = array of size n
//     for i from 0 to n-1:
//         pos[pairs[i].index] = i // Map original index to sorted position
//     visited = array of size n, all false
//     cycles = 0
//     for i from 0 to n-1:
//         if not visited[i]:
//             j = i
//             while not visited[j]:
//                 visited[j] = true
//                 j = pos[j]
//             cycles++
//     return n - cycles
// ```

// **Dry Run (Example 3):**  
// Input: `nums = [18, 43, 34, 16]`  
// - Digit sums: `[1+8=9, 4+3=7, 3+4=7, 1+6=7]` → `[9, 7, 7, 7]`
// - Pairs: `[{9,18,0}, {7,43,1}, {7,34,2}, {7,16,3}]`
// - Sort by (digit_sum, value): `[{7,16,3}, {7,34,2}, {7,43,1}, {9,18,0}]`
// - Sorted nums: `[16, 34, 43, 18]`
// - Mapping (original index → sorted position):
//   - Original: `[18, 43, 34, 16]` (indices 0,1,2,3)
//   - Sorted: `[16, 34, 43, 18]` (original indices 3,2,1,0)
//   - `pos[0]=3`, `pos[1]=2`, `pos[2]=1`, `pos[3]=0`
// - Cycle detection:
//   - Start i=0: `0 → pos[0]=3 → pos[3]=0` (cycle: 0→3→0, size=2)
//   - Start i=1: `1 → pos[1]=2 → pos[2]=1` (cycle: 1→2→1, size=2)
//   - Cycles: 2
// - Swaps: `n - cycles = 4 - 2 = 2`
// - Output: `2`

// **Time Complexity:**  
// - Digit sum: O(D) per number, D ≈ 9 → O(n).
// - Sorting: O(n log n).
// - Cycle detection: O(n).
// - Total: O(n log n).
// **Space Complexity:** O(n) for pairs, pos, and visited arrays.  
// **Pros:** Efficient, handles all constraints, and correctly computes minimum swaps.

// **Interviewer Tone:**  
// > “Sorting by digit sum and value, then cycle detection gives O(n log n) and the exact minimum swaps.”

// ---

// ### 🧪 Testing
// - **Example 1:** `nums = [37, 100]` → Sums: `[10, 1]` → Sorted: `[100, 37]` → 1 swap → Output: `1`
// - **Example 2:** `nums = [22, 14, 33, 7]` → Sums: `[4, 5, 6, 7]` → Sorted: `[22, 14, 33, 7]` → 0 swaps → Output: `0`
// - **Example 3:** `nums = [18, 43, 34, 16]` → Sums: `[9, 7, 7, 7]` → Sorted: `[16, 34, 43, 18]` → 2 swaps → Output: `2`
// - **Edge Case 1:** `nums = [5]` → Sum: `[5]` → Sorted: `[5]` → 0 swaps.
// - **Edge Case 2:** `nums = [16, 34, 43]` → Sums: `[7, 7, 7]` → Sorted: `[16, 34, 43]` → 0 swaps.

// **Interviewer Tone:**  
// > “All examples and edge cases pass with cycle detection. Try it on paper to see the cycles!”

// ---

// ### 🚀 Optimization
// - **Already Optimal:** O(n log n) due to sorting, which is necessary for custom ordering.
// - **Space:** O(n) is minimal; can’t reduce without losing clarity.
// - **Alternative:** Inversion counting (merge sort) could count swaps but is more complex and still O(n log n).

// **Interviewer Tone:**  
// > “O(n log n) is optimal for sorting-based problems. Cycle detection is clean and efficient.”

// ---

// ### 📝 Final Notes
// - **Why Optimal:** Sorting by digit sum and value, then using cycle detection, efficiently computes minimum swaps.
// - **Key Insight:** The problem reduces to a permutation transformation, where swaps = n - number_of_cycles.
// - **Category:** **Sorting**, **Permutation**, **Graph (Cycle Detection)**:
//   - **Sorting:** Custom sort by digit sum and value.
//   - **Permutation:** Transforming one permutation to another.
//   - **Graph:** Cycles in permutation mapping.
// - **MIK-Style Tip:** Pause, try a test case on paper, and trace the cycles to see how swaps work.

// **Interviewer Tone:**  
// > “This is a neat sorting and permutation problem. Cycle detection makes swap counting super clean!”

// ---

// ### 🔁 Reflection & Takeaways
// - **Learned:** Custom sorting with multiple keys and cycle detection for permutation swaps.
// - **Future Use:** Applicable to permutation transformation problems, custom sorting, and cycle-based swap counting.
// - **Strengthened:** Intuition for permutation cycles and efficient sorting techniques.

// **Interviewer Tone:**  
// > “This problem sharpened my skills in sorting and cycle detection. Perfect for DSA practice!”

// ---

// ### Full Organized Code (LeetCode Template)
// ```x-c++src
// #include <bits/stdc++.h>
// using namespace std;

// class Solution {
// public:
//     // Function to compute digit sum of a number
//     int sum_of_digits(long long x) {
//         int sum = 0;
//         while (x > 0) {
//             sum += x % 10;
//             x /= 10;
//         }
//         return sum;
//     }

//     int minSwaps(vector<int>& nums) {
//         int n = nums.size();
//         // Store {digit_sum, value, index} for sorting
//         vector<tuple<int, int, int>> pairs;
//         for (int i = 0; i < n; i++) {
//             int digit_sum = sum_of_digits(nums[i]);
//             pairs.push_back({digit_sum, nums[i], i});
//         }
//         // Sort by digit_sum (primary), value (secondary)
//         sort(pairs.begin(), pairs.end());
//         // Map original index to sorted position
//         vector<int> pos(n);
//         for (int i = 0; i < n; i++) {
//             pos[get<2>(pairs[i])] = i;
//         }
//         // Count cycles in permutation
//         vector<bool> visited(n, false);
//         int cycles = 0;
//         for (int i = 0; i < n; i++) {
//             if (!visited[i]) {
//                 int j = i;
//                 while (!visited[j]) {
//                     visited[j] = true;
//                     j = pos[j];
//                 }
//                 cycles++;
//             }
//         }
//         // Minimum swaps = n - number of cycles
//         return n - cycles;
//     }
// };
// ```

// ---

// ### **Intuition Recap (Desi Style)**  
// - **Kya Karna Hai:** Array ko digit sum ke basis pe sort karo (same sum wale ko chhote value pehle). Fir yeh order banane ke liye minimum swaps chahiye.
// - **Kaise Karna Hai:**  
//   - Har number ka digit sum nikal.
//   - Digit sum aur value ke basis pe sort kar.
//   - Original aur sorted array ke indices ka mapping bana.
//   - Cycles count karo—har cycle mein (size-1) swaps chahiye.
//   - Total swaps = n - cycles.
// - **Desi Analogy:** Soch, tu ek dance group ko unke “energy” (digit sum) ke hisaab se line mein laga raha hai. Same energy wale dancers ko chhote number pehle. Ab yeh line banane ke liye kitne dancers swap karne padenge? Cycles check kar, aur ho gaya!

// ---

// ### **Category for Minimum Swaps to Sort by Digit Sum**
// - **Primary Category: Sorting, Permutation**  
//   - **Sorting:** Custom sort by digit sum and value.
//   - **Permutation:** Transform original to sorted permutation.
// - **Secondary Category: Graph (Cycle Detection)**  
//   - **Graph:** Cycles in permutation mapping for swap counting.
// - **Not Really: DP, Greedy, Two Pointers**  
//   - No DP (no subproblem optimization).
//   - Greedy swapping inefficient.
//   - No two pointers (array manipulation).

// **Desi Analogy:** Yeh ek “dance line-up” jaisa hai—dancers ko energy aur size ke hisaab se sort karo, aur minimum swaps count karo. Cycle detection iska hero hai!

// ---

// ### **Next Steps, Bhai!**
// 1. **Try Test Cases:** Pen-paper pe ek test case try kar (e.g., `nums = [123, 45, 67]`). Digit sums nikal, sort kar, cycles count kar, aur swaps verify kar.
// 2. **Similar Problems:** Aur sorting/permutation problems chahiye? Suggest kar sakta hoon:
//    - LeetCode 41: First Missing Positive (Permutation)
//    - LeetCode 315: Count of Smaller Numbers After Self (Inversions)
//    - Codeforces 1365C: Rotation Matching (Cycles)
// 3. **Codeforces Link:** Tune pehle **Twin Permutations** ke liye MIK video diya. Kya CP-31 sheet ya Codeforces ke aur problems pe focus karna hai?
// 4. **GitHub Setup:** DSA solutions ke liye GitHub structure chahiye? (e.g., per category: Sorting, Permutation).
// 5. **Feedback:** Yeh code aur explanation kaisa laga? Twin Permutations ke intuition ke baad kya yeh problem clear hua?

// Bol, bhai, ab kya plan hai? DSA ka safar full-on chal raha hai! 😎🔥

// **Current Date & Time:** 08:44 AM IST, Sunday, May 18, 2025.

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Function to compute digit sum of a number
    int sum_of_digits(long long x) {
        int sum = 0;
        while (x > 0) {
            sum += x % 10;
            x /= 10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        // Store {digit_sum, value, index} for sorting
        vector<tuple<int, int, int>> pairs;
        for (int i = 0; i < n; i++) {
            int digit_sum = sum_of_digits(nums[i]);
            pairs.push_back({digit_sum, nums[i], i});
        }
        // Sort by digit_sum (primary), value (secondary)
        sort(pairs.begin(), pairs.end());
        // Map original index to sorted position
        vector<int> pos(n);
        for (int i = 0; i < n; i++) {
            pos[get<2>(pairs[i])] = i;
        }
        // Count cycles in permutation
        vector<bool> visited(n, false);
        int cycles = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                int j = i;
                while (!visited[j]) {
                    visited[j] = true;
                    j = pos[j];
                }
                cycles++;
            }
        }
        // Minimum swaps = n - number of cycles
        return n - cycles;
    }
};