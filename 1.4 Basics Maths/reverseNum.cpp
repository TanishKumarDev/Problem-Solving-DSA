#include <bits/stdc++.h>
using namespace std;

void reverse(int n) {
    int rev = 0;
    while (n > 0) {
        rev = rev * 10 + n % 10;
        n /= 10;
    }
    cout << rev << " " << endl;
}

int main()
{
    
    int n;
    cin >> n; // Input a number

    reverse(n); // Call the reverse function
    return 0;
}