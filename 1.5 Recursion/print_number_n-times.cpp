#include <bits/stdc++.h>
using namespace std;

void print_n_times(int i, int n)
{
    if (i > n)
        return;
    cout << "Hi" << endl;
    // Function call to print till i increments.
    print_n_times(i + 1, n);
}
int main()
{
    int n;
    cin >> n;
    print_n_times(1, n);
    return 0;
}