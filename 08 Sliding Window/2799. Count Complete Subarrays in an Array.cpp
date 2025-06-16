#include <bits/stdc++.h>
using namespace std;

// Sliding Window Approach
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();

        // Pata karo kitne distinct elements hain poore array mein
        unordered_set<int> uniqueElements(nums.begin(), nums.end());
        int totalUnique = uniqueElements.size(); // Yeh target hoga har subarray ke liye

        int start = 0;
        int end = 0;
        int completeCount = 0;

        unordered_map<int, int> freqMap;

        while (end < n) {
            freqMap[nums[end]]++;

            // Jab window ke andar ke distinct elements == totalUnique ho jaye
            while (freqMap.size() == totalUnique) {
                completeCount += (n - end); // Saare subarrays end se n tak valid hain

                // Window chhoti karo - left se element hatao
                freqMap[nums[start]]--;
                if (freqMap[nums[start]] == 0) {
                    freqMap.erase(nums[start]);
                }
                start++;
            }

            end++;
        }

        return completeCount;
    }
};

int main() {

}
