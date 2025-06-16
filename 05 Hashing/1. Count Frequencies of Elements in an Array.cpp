#include <bits/stdc++.h>
using namespace std;

int main()
{
    // Input: Number of elements in the array
    int n;;
    cin>>n;

    // Input: Elements of the array
    int arr[n];
    for(int i = 0; i < n; i++)
    {
        cin >> arr[i]; 
    }

    // pre compute the frequency of each element
    int hash[13] = {0}; // Assuming elements are in the range 0 to 12
    for(int i = 0; i < n; i++)
    {
        hash[arr[i]]++; // Increment the frequency of arr[i] in the hash array
    }

    // fetch the frequency of each element
    int query;
    cin >> query;
    while(query--)
    {
        int number;
        cin >> number;
        cout << hash[number] << endl; // Output the frequency of element number
    }

    return 0;
}