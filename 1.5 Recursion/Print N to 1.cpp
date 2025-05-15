#include <bits/stdc++.h>
using namespace std;

void print_n_to_1_times(int i, int n){
    if(i <1) return;
    cout<<i<<endl;
    print_n_to_1_times(i-1, n);
}

int main()
{
    int n;
    cin>>n;
    print_n_to_1_times(n,n);
    return 0;
}