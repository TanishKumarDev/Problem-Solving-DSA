#include <bits/stdc++.h>
using namespace std;

void print_1_to_n_times(int i, int n)
{
    if (i > n) // base case
        return;
    cout << i << endl;  // Print current value
    // Function call to print till i increments.
    print_1_to_n_times(i + 1, n); // Recursive call
}
int main()
{
    int n;
    cin >> n;
    print_1_to_n_times(1, n);
    return 0;
}