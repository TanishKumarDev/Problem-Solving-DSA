#include <bits/stdc++.h>
using namespace std;
// Try all possible divisors from 1 to min(n1, n2) and keep the latest common divisor.
int findGcd_brute(int n1, int n2)
{
    if (n1 == 0 && n2 == 0) return -1; // undefined case
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;
    int gcd = 1;
    for (int i = 1; i <= min(n1, n2); i++)
    {
        if (n1 % i == 0 && n2 % i == 0)
        {
            gcd = i;
        }
    }

    return gcd;
}
int findGcd_better(int n1, int n2)
{

    if (n1 == 0 && n2 == 0) return -1; // undefined case
    if (n1 == 0) return n2;
    if (n2 == 0) return n1;
    while (n1 != n2)
    {
        if (n1 >= n2)
        {
            n1 = n1 % n2;
        }
        else
        {
            n2 = n2 % n1;
        }

        return (n1 == 0) ? n2 : n1;
    }
}
    int main()
    {
        int n1, n2;
        cin >> n1 >> n2;

        int gcd = findGcd_brute(n1, n2);
        cout << "findGcd_brute: " << gcd << endl;
        cout << "findGcd_better: " << gcd << endl;
        return 0;
    }