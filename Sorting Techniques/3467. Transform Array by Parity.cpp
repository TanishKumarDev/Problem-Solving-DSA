#include <bits/stdc++.h>
using namespace std;

// 🟢 Approach 3 Optimal: 

// Intuition : 
// 1. in result even number(which are 0s) should come first, how many times? exactly 'No of even numbers' in nums. similarly 
// 2. Odd come after all even numbers count, how many times? exactly 'No of odd numbers' in nums.
// thus 
// 3. we can count the number of even numbers in the array and then fill the result array with 0s for even numbers and 1s for odd numbers.

// Algo :
// 1. Count the number of even numbers in the array.
// 2. Create a new array of the same size as the input array.
// 3. Fill the new array with 0s for even numbers and 1s for odd numbers.
// 4. Return the new array.

class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
    int n = nums.size();

    
    int evenCount = 0;

    // Count even numbers(0s)
    for(int i=0; i<n; i++){
        if(nums[i] % 2 == 0) {
            evenCount++;
        }
    }

    // create result array same size
    vector<int> res(n);

    int index = 0;
    while(evenCount != 0 ){
        res[index] = 0;
        index++;
        evenCount--;
    }

    // fill remaining with 1s
    for(int i = index; i<n; i++){
        res[i] = 1;
    }
    return res;
    }
};

int main()
{
    
    return 0;
}