// LeetCode Problem: 3467. Transform Array by Parity

/*
Replace each even number with 0.
Replace each odd numbers with 1.
Sort the modified array in non-decreasing order.

Return the resulting array after performing these operations.

--------------------------------------------------------
Read Question twice. 

1. in result even number(which are 0s) should come first, how many times? exactly 'No of even numbers' in nums. similarly 
2. Odd come after all even numbers count, how many times? exactly 'No of odd numbers' in nums.

thus 
3. we can count the number of even numbers in the array and then fill the result array with 0s for even numbers and 1s for odd numbers.
--------------------------------------------------------
Time Complexity: O(n)
Space Complexity: O(n)
*/

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
