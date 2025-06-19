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
    string s;
    cin>>s;

    map<char, int> mp;
    for(int i=0; i<s.size(); i++){
        mp[s[i]]++; // pre compute : the frequency of each character in the string
    }

    int q;
    cin>>q;

    while (q--)
    {
        char c;
        cin>>c;
        cout<<mp[c]<<endl; // fetch : print the frequency of the character
    }
    
    // print map
    for(auto it: mp){
        cout<<it.first<<" --> "<<it.second<<endl;
    }
    return 0;
}