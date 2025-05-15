#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(int num) {
    int original = num, reversed = 0;
    while (num > 0) {
        reversed = reversed * 10 + num % 10;
        num /= 10;
    }
    return original == reversed;
}

int main()
{
    int num;
    cin >> num;

    if(isPalindrome(num == true)){ //by default it is true
        cout<<"Yes, it is a palindrome."<<endl;
    } else {
        cout<<"No, it is not a palindrome."<<endl;
    }
    return 0;
}