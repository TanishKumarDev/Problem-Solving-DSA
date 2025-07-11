#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Best Time to Buy and Sell Stock
// Given an array prices where prices[i] is the price of a stock on day i, find the maximum profit you can achieve by buying on one day and selling on a later day.
// If no profit is possible, return 0.

// Example: 
// Input: prices = [7, 1, 5, 3, 6, 4], n = 6
// Output: 5 (buy at 1 on day 2, sell at 6 on day 5)

// Constraints: 
// - 1 <= n <= 10^5
// - 0 <= prices[i] <= 10^4

// 🔴 Approach 1 Brute Force: Check All Pairs
// Intuition:
// Bhai, yeh toh seedha share market ka tamasha hai! Imagine you’re a trader checking every possible day to buy and every later day to sell. For each buy day, you try selling on all future days, calculate the profit (sell price - buy price), and keep the maximum profit. It’s like trying every combo in a bazaar to get the best deal, but it takes time!

// Algo:
// 1. Loop through all possible buy days i (0 to n-2).
// 2. For each buy day, loop through all possible sell days j (i+1 to n-1).
// 3. Calculate profit = prices[j] - prices[i].
// 4. Update max_profit if the current profit is larger.
// 5. Return max_profit (0 if no profit possible).

// TC: O(n^2) — nested loops for all buy-sell pairs.
// SC: O(1) — only a few variables.

// 📌 Note: Why buy < n-1 but sell < n?
// - buy < n-1: ✅ We stop buying at n-2 because you need at least one later day to sell. If you buy on the last day (n-1), there’s no day left to sell, so no profit is possible.
// - sell < n: ✅ Selling can go up to the last day (n-1) because you can sell on any day after buying. The inner loop starts from buy+1 and goes to n-1.
// - Final Verdict: buy < n-1 ensures a valid sell day exists; sell < n covers all possible sell days after buy. Using buy < n would allow buying on the last day, which is invalid.

int maxProfitBrute(vector<int>& prices) {
    int n = prices.size();
    int max_profit = 0;
    for (int buy = 0; buy < n-1; buy++) {
        for (int sell = buy+1; sell < n; sell++) {
            int profit = prices[sell] - prices[buy];
            max_profit = max(max_profit, profit);
        }
    }
    return max_profit;
}

// 🔵 Approach 2 Better: Track Differences with Sliding Window
// Intuition:
// Thodi si akal lagate hain, bhai! Instead of checking every buy-sell pair, think of a window where you buy at the start and keep extending the sell day. For each buy day, track the maximum profit by comparing with later sell days, but reuse the buy price to avoid redundant checks. It’s like scanning the market for the best sell price after fixing a buy day.

// Algo:
// 1. Loop through each possible buy day i (0 to n-2).
// 2. For each buy day, iterate sell days j (i+1 to n-1), calculating profit = prices[j] - prices[i].
// 3. Update max_profit if the current profit is larger.
// 4. Move to the next buy day and repeat.
// 5. Return max_profit (0 if no profit possible).

// TC: O(n^2) — still two nested loops, but slightly clearer logic than brute force.
// SC: O(1) — only a few variables.

int maxProfitBetter(vector<int>& prices) {
    int n = prices.size();
    int max_profit = 0;
    for (int i = 0; i < n-1; i++) {
        int buy_price = prices[i];
        for (int j = i+1; j < n; j++) {
            int profit = prices[j] - buy_price;
            max_profit = max(max_profit, profit);
        }
    }
    return max_profit;
}

// 🟢 Approach 3 Optimal: Track Minimum Price
// Intuition:
// Ab asli dimaag lagaya, bhai! The key is to buy low and sell high. Instead of checking every pair, track the minimum price seen so far (best buy opportunity). For each day, calculate the profit if you sell at the current price (current price - min price). Update the max profit if it’s better. It’s like spotting the cheapest deal in the market and checking if today’s price gives you a good profit!

// Algo:
// 1. If n <= 1, return 0 (no profit possible).
// 2. Initialize min_price = prices[0] and max_profit = 0.
// 3. Iterate through prices from index 1:
//    - Update min_price if current price is lower.
//    - Calculate profit = current price - min_price.
//    - Update max_profit if profit is larger.
// 4. Return max_profit.

// TC: O(n) — single pass through the array.
// SC: O(1) — only a few variables.

// 📌 Note: Optimal Approach Insights
// - Why min_price works: Since we only need one buy and one sell, the maximum profit comes from the largest difference between a price and the lowest price before it.
// - Edge cases: If prices are in descending order (e.g., [7,6,5,4]), min_price keeps updating, and max_profit stays 0 (no profit possible).
// - Why i starts from 1: We initialize min_price with prices[0], so we start checking from the next day to ensure sell day is after buy day.

int maxProfitOptimal(vector<int>& prices) {
    int n = prices.size();
    if (n <= 1) return 0;
    int min_price = prices[0];
    int max_profit = 0;
    for (int i = 1; i < n; i++) {
        min_price = min(min_price, prices[i]);
        int profit = prices[i] - min_price;
        max_profit = max(max_profit, profit);
    }
    return max_profit;
}

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};
    cout << "Brute: " << maxProfitBrute(prices) << endl;
    cout << "Better: " << maxProfitBetter(prices) << endl;
    cout << "Optimal: " << maxProfitOptimal(prices) << endl;
    return 0;
}