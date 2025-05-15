
#include <bits/stdc++.h>
using namespace std;

void sum_Iterative(int n)
{
    // 1. Iterative (Loop) Approach
    // Intuition: Add numbers from 1 to N using a loop.
    // Time Complexity: O(N)
    // Space Complexity: O(1)

    int sum = 0; // base case
    for (int i = 1; i <= n; i++)
    {
        sum += i;
    }
    cout << "sum_Iterative = " << sum << endl;
}
void sum_formula(int n)
{
    // 2. Formula-Based Approach
    // Intuition: Use the formula:
    // Sum = N × (N + 1) / 2
    // Time Complexity: O(N)
    // Space Complexity: O(1)
    int sum = n * (n + 1) / 2;
    cout << "sum_formula = " << sum << endl;
}
void sum_Parameterized(int i, int sum)
{
    // 3. Recursive - Parameterized
    // Intuition: Pass the sum as a parameter to accumulate during recursion.
    // Time Complexity: O(N)
    // Space Complexity: O(N)
    if (i < 1)
    {
        cout << "sum_Parameterized = " << sum << endl;
        return;
    }
    sum_Parameterized(i - 1, sum + i);
}
int sum_Functional(int n)
{
    // 4. Recursive - Functional
    // Intuition: Return the sum of current n and recursive call for n-1.
    // Time Complexity: O(N)
    // Space Complexity: O(N)if (n == 0)
    return 0;
    return n + sum_Functional(n - 1);
}

int main()
{
    int n;
    cin >> n;
    sum_Iterative(n);
    sum_formula(n);
    sum_Parameterized(n, 0);
    cout << "sum_Functional = " << sum_Functional(n) << endl;
    return 0;
}