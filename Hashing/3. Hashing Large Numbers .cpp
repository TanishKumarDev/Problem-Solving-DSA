#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: 
// Intuition :
// Algo :
// TC :
// SC :

int main()
{
    int n;
    cin>>n;
    
    int arr[n]; // array of size n
    for(int i=0; i<n; i++){
        cin>>arr[i];
    }

    map<long long, int> mp; // key: long long for large numbers
    for(int i=0; i<n;i++){
        mp[arr[i]]++;
    }

    int q;
    cin>>q;
    while (q--)
    {
        long long numbers;
        cin>>numbers;
        cout<<mp[numbers]<<endl;
    }

    // print map
    for(auto it: mp){
        cout<<it.first<<" "<<it.second<<endl;
    }

    
    return 0;
}