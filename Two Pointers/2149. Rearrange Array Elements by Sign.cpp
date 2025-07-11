#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Rearrange Array Elements by Sign
// Given an array nums of integers, rearrange it such that positive and negative numbers alternate.
// - Variety 1: The array has an equal number of positive and negative numbers. The result should alternate starting with a positive number.
// - Variety 2: The array may have unequal numbers of positive and negative numbers. Alternate as much as possible, then append remaining numbers.

// Example:
// - Variety 1: Input: nums = [3,-2,1,-5,2,-4], n = 6 → Output: [3,-2,1,-5,2,-4]
// - Variety 2: Input: nums = [2,-1,3,-3,4,5], n = 6 → Output: [2,-1,3,-3,4,5]

// Constraints:
// - 1 <= n <= 10^5
// - nums[i] != 0 (no zeros in the array)
// - Variety 1: n is even, equal number of positive and negative numbers.
// - Variety 2: n can be even or odd, number of positives and negatives may differ.

// 🔴 Approach 1 Brute Force (Variety 1: Equal Positives and Negatives)
// Intuition:
// Bhai, yeh toh line mein bithaane jaisa hai! You’ve got equal numbers of positive and negative folks, and you need to arrange them alternately, starting with a positive. So, first collect all positives and negatives in separate groups, like sorting laddoos and samosas, then place them one-by-one in the order: positive, negative, positive, negative.

// Algo:
// 1. Create two vectors: pos for positive numbers, neg for negative numbers.
// 2. Iterate through nums, pushing positives to pos and negatives to neg.
// 3. Create result array ans of size n.
// 4. Fill ans by placing pos[i] at even indices (0, 2, 4, ...) and neg[i] at odd indices (1, 3, 5, ...).
// 5. Return ans.

// TC: O(n) — single pass to separate numbers, single pass to fill result.
// SC: O(n) — two temporary vectors (pos, neg) and result array.

// 📌 Note: Why i < n/2 in the loop?
// - In Variety 1, we have n/2 positives and n/2 negatives (since n is even and equal numbers are guaranteed).
// - The loop `for (int i = 0; i < n/2; i++)` iterates n/2 times because:
//   - ✅ Each iteration places one positive (at 2*i) and one negative (at 2*i+1), filling two positions.
//   - ✅ With n/2 iterations, we fill n positions (n/2 positives + n/2 negatives), covering the entire array.
// - If we used `i < n`, we’d try to place n positives and n negatives, but we only have n/2 of each, causing out-of-bounds access.
// - Final Verdict: `i < n/2` ensures we use exactly n/2 positives and n/2 negatives, perfectly alternating in the result array.

vector<int> rearrangeArrayBrute(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    vector<int> ans(n);
    for (int i = 0; i < n/2; i++) {
        ans[2*i] = pos[i];
        ans[2*i+1] = neg[i];
    }
    return ans;
}

// 🔵 Approach 2 Better (Variety 1: Equal Positives and Negatives)
// Intuition:
// Thodi si akal lagate hain, bhai! Instead of storing all positives and negatives separately, we can scan the array multiple times to pick positives and negatives in order. It’s like arranging people in a queue by calling out “positive, negative” one at a time, but we need extra passes to find the right numbers.

// Algo:
// 1. Create result array ans of size n.
// 2. Iterate through nums to find positives, placing them at even indices (0, 2, 4, ...).
// 3. Iterate through nums again to find negatives, placing them at odd indices (1, 3, 5, ...).
// 4. Return ans.

// TC: O(n^2) — multiple passes through the array to find positives and negatives.
// SC: O(n) — only the result array.

vector<int> rearrangeArrayBetter(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0 && posIndex < n) {
            ans[posIndex] = nums[i];
            posIndex += 2;
        }
    }
    for (int i = 0; i < n; i++) {
        if (nums[i] < 0 && negIndex < n) {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}

// 🟢 Approach 3 Optimal (Variety 1: Equal Positives and Negatives)
// Intuition:
// Yeh hai asli dimaag, bhai! Since we know there are equal positives and negatives, we can place them directly in the result array using two pointers: one for even indices (positives) and one for odd indices (negatives). It’s like telling people exactly where to stand in one go—positive on left, negative on right, no extra storage needed for sorting.

// Algo:
// 1. Create result array ans of size n.
// 2. Initialize posIndex = 0 (for even indices) and negIndex = 1 (for odd indices).
// 3. Iterate through nums:
//    - If nums[i] > 0, place at ans[posIndex], increment posIndex by 2.
//    - If nums[i] < 0, place at ans[negIndex], increment negIndex by 2.
// 4. Return ans.

// TC: O(n) — single pass through the array.
// SC: O(n) — only the result array.

// 📌 Note: Variety 1 Insights
// - Why equal numbers work: The constraint ensures n/2 positives and n/2 negatives, so alternating is always possible.
// - Brute vs Optimal: Brute uses extra vectors (pos, neg), while Optimal directly places numbers, saving temporary storage but still needing O(n) for the result.
// - Why start with positive: The problem specifies starting with a positive number for Variety 1.

vector<int> rearrangeArrayOptimal(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) {
            ans[posIndex] = nums[i];
            posIndex += 2;
        } else {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
    }
    return ans;
}

// 🔴 Approach 1 Brute Force (Variety 2: Unequal Positives and Negatives)
// Intuition:
// Bhai, ab thoda tricky ho gaya! Now positives and negatives might not be equal, so we alternate as much as possible, then dump the leftovers at the end. It’s like arranging a queue but running out of one group, so you let the rest stand at the back.

// Algo:
// 1. Create two vectors: pos for positives, neg for negatives.
// 2. Iterate through nums, pushing positives to pos and negatives to neg.
// 3. Create result array ans of size n.
// 4. Fill ans by alternating pos[i] and neg[i] up to the minimum of their sizes.
// 5. Append remaining positives or negatives to ans.
// 6. Return ans.

// TC: O(n) — single pass to separate, single pass to fill result.
// SC: O(n) — two temporary vectors (pos, neg) and result array.

// 📌 Note: Why i < minSize in Variety 2?
// - minSize = min(pos.size(), neg.size()) ensures we alternate only as long as we have both positives and negatives.
// - The loop `for (int i = 0; i < minSize; i++)` places minSize positives and minSize negatives alternately.
// - After alternating, remaining positives or negatives are appended, handling the unequal counts.

vector<int> rearrangeArrayVariety2(vector<int>& nums) {
    int n = nums.size();
    vector<int> pos, neg;
    for (int i = 0; i < n; i++) {
        if (nums[i] > 0) pos.push_back(nums[i]);
        else neg.push_back(nums[i]);
    }
    vector<int> ans(n);
    int minSize = min(pos.size(), neg.size());
    for (int i = 0; i < minSize; i++) {
        ans[2*i] = pos[i];
        ans[2*i+1] = neg[i];
    }
    int index = minSize * 2;
    if (pos.size() > neg.size()) {
        for (int i = neg.size(); i < pos.size(); i++) {
            ans[index++] = pos[i];
        }
    } else if (neg.size() > pos.size()) {
        for (int i = pos.size(); i < neg.size(); i++) {
            ans[index++] = neg[i];
        }
    }
    return ans;
}

// 🔵 Approach 2 Better (Variety 2: Unequal Positives and Negatives)
// Intuition:
// Thodi optimization karte hain, bhai! Instead of storing all positives and negatives separately, we can use two pointers to place them alternately in one pass until we run out of one type, then append the rest. It’s like arranging the queue but switching to a single line when one group is done.

// Algo:
// 1. Create result array ans of size n.
// 2. Initialize posIndex = 0 (even indices), negIndex = 1 (odd indices), and curr = 0 (current position in nums).
// 3. While posIndex and negIndex are valid and curr < n:
//    - Place a positive at posIndex, increment posIndex by 2.
//    - Place a negative at negIndex, increment negIndex by 2.
// 4. Append remaining positives or negatives to ans.
// 5. Return ans.

// TC: O(n) — single pass to place numbers, plus a pass for remaining elements.
// SC: O(n) — only the result array.

vector<int> rearrangeArrayVariety2Better(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1, curr = 0;
    while (posIndex < n && negIndex < n && curr < n) {
        while (curr < n && nums[curr] <= 0) curr++;
        if (curr < n && posIndex < n) {
            ans[posIndex] = nums[curr];
            posIndex += 2;
            curr++;
        }
        while (curr < n && nums[curr] >= 0) curr++;
        if (curr < n && negIndex < n) {
            ans[negIndex] = nums[curr];
            negIndex += 2;
            curr++;
        }
    }
    while (curr < n) {
        if (nums[curr] > 0 && posIndex < n) {
            ans[posIndex] = nums[curr];
            posIndex += 2;
        } else if (nums[curr] < 0 && negIndex < n) {
            ans[negIndex] = nums[curr];
            negIndex += 2;
        }
        curr++;
    }
    return ans;
}

// 🟢 Approach 3 Optimal (Variety 2: Unequal Positives and Negatives)
// Intuition:
// Yeh hai ultimate trick, bhai! We can optimize further by using two pointers for positives and negatives but handle the leftover elements in the same pass. It’s like arranging the queue dynamically, placing positives and negatives alternately, and immediately appending extras when one group runs out.

// Algo:
// 1. Create result array ans of size n.
// 2. Initialize posIndex = 0 (even indices), negIndex = 1 (odd indices).
// 3. Iterate through nums:
//    - If nums[i] > 0 and posIndex < n, place at ans[posIndex], increment posIndex by 2.
//    - If nums[i] < 0 and negIndex < n, place at ans[negIndex], increment negIndex by 2.
// 4. After the loop, fill remaining indices with any leftover positives or negatives.
// 5. Return ans.

// TC: O(n) — single pass through the array.
// SC: O(n) — only the result array.

// 📌 Note: Variety 2 Insights
// - Why unequal numbers complicate things: We can’t guarantee alternating for the entire array, so we append leftovers after exhausting one type.
// - Brute vs Optimal: Brute uses extra vectors, while Optimal minimizes temporary storage by placing numbers directly, though both need O(n) for the result.
// - Handling leftovers: After alternating, remaining positives or negatives are placed in the next available indices.

vector<int> rearrangeArrayVariety2Optimal(vector<int>& nums) {
    int n = nums.size();
    vector<int> ans(n);
    int posIndex = 0, negIndex = 1, i = 0;
    while (i < n && posIndex < n && negIndex < n) {
        if (nums[i] > 0) {
            ans[posIndex] = nums[i];
            posIndex += 2;
        } else {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        i++;
    }
    while (i < n) {
        if (nums[i] > 0 && posIndex < n) {
            ans[posIndex] = nums[i];
            posIndex += 2;
        } else if (nums[i] < 0 && negIndex < n) {
            ans[negIndex] = nums[i];
            negIndex += 2;
        }
        i++;
    }
    return ans;
}

int main() {
    // Variety 1
    vector<int> nums1 = {3, -2, 1, -5, 2, -4};
    cout << "Variety 1 (Brute): ";
    vector<int> result1 = rearrangeArrayBrute(nums1);
    for (int x : result1) cout << x << " ";
    cout << endl;
    cout << "Variety 1 (Better): ";
    vector<int> result2 = rearrangeArrayBetter(nums1);
    for (int x : result2) cout << x << " ";
    cout << endl;
    cout << "Variety 1 (Optimal): ";
    vector<int> result3 = rearrangeArrayOptimal(nums1);
    for (int x : result3) cout << x << " ";
    cout << endl;
    // Variety 2
    vector<int> nums2 = {2, -1, 3, -3, 4, 5};
    cout << "Variety 2 (Brute): ";
    vector<int> result4 = rearrangeArrayVariety2(nums2);
    for (int x : result4) cout << x << " ";
    cout << endl;
    cout << "Variety 2 (Better): ";
    vector<int> result5 = rearrangeArrayVariety2Better(nums2);
    for (int x : result5) cout << x << " ";
    cout << endl;
    cout << "Variety 2 (Optimal): ";
    vector<int> result6 = rearrangeArrayVariety2Optimal(nums2);
    for (int x : result6) cout << x << " ";
    cout << endl;
    return 0;
}