#include <bits/stdc++.h>
using namespace std;

/*
🔍 Approach 1: Brute Force (Counting)

Intuition:
- Count the frequency of 0s, 1s, and 2s.
- Overwrite the array: first 0s, then 1s, then 2s.
- Simple but requires two passes (counting + overwriting).

Desi Analogy:
- Soch, tu mela mein balloons count kar raha hai—kitne red, white, blue. Fir ek nayi line bana: pehle red, fir white, fir blue.

Time Complexity: O(n) — two passes (counting + overwriting).
Space Complexity: O(1) — only three counters.
*/

class BruteForceSolution {
public:
    void sortColors_brute(vector<int>& nums) {
        int count0 = 0, count1 = 0, count2 = 0;
        // Count frequencies
        for (int num : nums) {
            if (num == 0) count0++;
            else if (num == 1) count1++;
            else count2++;
        }
        // Overwrite array
        int i = 0;
        while (count0--) nums[i++] = 0;
        while (count1--) nums[i++] = 1;
        while (count2--) nums[i++] = 2;
    }
};

/*
⚡ Approach 2: Optimal (Dutch National Flag)

Observations:
- Only three values (0, 1, 2), so we can partition using three pointers.
- low: all elements before low are 0s.
- mid: elements between low and mid are 1s.
- high: all elements after high are 2s.

Intuition:
- Use three pointers (low, mid, high) to partition in one pass.
- If nums[mid] == 0: swap with low, increment both.
- If nums[mid] == 1: increment mid.
- If nums[mid] == 2: swap with high, decrement high.

Desi Analogy:
- Soch, tu balloons ko ek line mein sort kar raha hai. Red balloons left mein, blue right mein, aur white beech mein. Ek hi dafa mein sab adjust kar de!

Time Complexity: O(n) — one pass through the array.
Space Complexity: O(1) — only three pointers.
*/

class OptimalSolution {
public:
    void sortColors_optimal(vector<int>& nums) {
        int low = 0, mid = 0, high = nums.size() - 1; // three pointers (low, mid, high
        while (mid <= high) {
            if (nums[mid] == 0) { // if nums[mid] == 0: swap with low, increment both.
                swap(nums[low], nums[mid]);
                low++;
                mid++;
            } else if (nums[mid] == 1) { // If nums[mid] == 1: increment mid.
                mid++;
            } else { // If nums[mid] == 2: swap with high, decrement high.
                swap(nums[mid], nums[high]);
                high--;
            }
        }
    }
};

/*
🧪 Testing both approaches
*/
int main() {
    vector<int> nums = {2, 0, 2, 1, 1, 0};
    vector<int> nums2 = nums; // Copy for brute force

    BruteForceSolution brute;
    OptimalSolution optimal;

    cout << "Brute Force Result: ";
    brute.sortColors_brute(nums);
    for (int num : nums) {
        cout << num << " ";
    }
    cout << endl;

    cout << "Optimal Result: ";
    optimal.sortColors_optimal(nums2);
    for (int num : nums2) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}