#include <bits/stdc++.h>
using namespace std;

// ✅ Approach 1: Iterative Digit Count, Simple se socha — har number ke digits manually count karo while loop se
int findNumbers_Iterative(vector<int> &nums)
{
    int count = 0;
    for (int num : nums)
    {
        int digits = 0;
        while (num > 0)
        {
            num /= 10;
            digits++;
        }
        if (digits % 2 == 0)
            count++;
    }
    return count;
}

// ✅ Approach 2: String Conversion Method, Socha har number string mein convert kar do, uski length hi digits hoti hai
int findNumbers_StringConv(vector<int> &nums)
{
    int count = 0;
    for (int num : nums)
    {
        if (to_string(num).length() % 2 == 0)
            count++;
    }
    return count;
}

// ✅ Approach 3: Logarithmic Method (Optimized), Feel hua ki log10(num) se pata chal sakta hai digit count bina loop ke
int findNumbers_Log(vector<int> &nums)
{
    int count = 0;
    for (int num : nums)
    {
        int digits = floor(log10(num)) + 1;
        if (digits % 2 == 0)
            count++;
    }
    return count;
}

// ✅ Approach 4: Range-Based Check (Super Optimized), constaint ko dekh k Feel hua fixed digit length ke liye ranges banayi ja sakti hai
int findNumbers_RangeBased(vector<int> &nums)
{
    int count = 0;
    for (int num : nums)
    {
        if ((num >= 10 && num <= 99) ||     // 2 digits
            (num >= 1000 && num <= 9999) || // 4 digits
            (num == 100000))
        { // 6 digits
            count++;
        }
    }
    return count;
}

// 🚀 Driver Code to Test All Approaches
int main()
{
    vector<int> nums = {12, 345, 2, 6, 7896};

    cout << "Input: {12, 345, 2, 6, 7896}" << endl;

    cout << "Approach 1 (Iterative): " << findNumbers_Iterative(nums) << endl;
    cout << "Approach 2 (String Conversion): " << findNumbers_StringConv(nums) << endl;
    cout << "Approach 3 (Logarithmic): " << findNumbers_Log(nums) << endl;
    cout << "Approach 4 (Range-Based): " << findNumbers_RangeBased(nums) << endl;

    return 0;
}
