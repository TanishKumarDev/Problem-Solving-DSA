#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
            unordered_map<int, long long> mp;
            long long result = 0, count = 0;
    
            mp[0] = 1;
    
            for (int i = 0; i < nums.size(); i++) {
                if (nums[i] % modulo == k)
                    count++;
    
                int r1 = count % modulo;
                int r2 = (r1 - k + modulo) % modulo;
    
                result += mp[r2];
                mp[r1]++;
            }
    
            return result;
        }
    };

int main()
{
    
    return 0;
}