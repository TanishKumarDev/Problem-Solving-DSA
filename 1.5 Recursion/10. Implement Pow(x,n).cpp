#include <bits/stdc++.h>
using namespace std;

/*
  Approach 1: Naive Iteration
  Time: O(n)
  Space: O(1)
  Intuition: Multiply x with itself n times. If n is negative, take reciprocal later.
*/
double myPow(double x, int n) {
    long long nn = abs((long long)n); // convert the power to a positive number
    double result = 1.0; // initialize the result to 1

    for(long long i = 0; i < nn; i++) {
        result = result * x; // multiply the result by x
    }

    return (n < 0) ? 1.0 / result : result; // if the power is negative, then we need to divide the result by x
}

/*
 Approach 2:  Naive Recursion
 Time: O( n)
 Space: O( n)
 Intuition: Each call multiplies x and reduces n till base case (n == 0).
*/
double recursivePow(double x, long long n) {
    if(n == 0) return 1.0; // base case when n is 0
    if (n < 0) return 1 / recursivePow(x, -n); // if the power is negative, then we need to divide the result by x  
    return x * recursivePow(x, n - 1); // recursive call
}

/*
 Approach 3: Optimized Recursion
 Time: O(log n)
 Space: O(log n)
 Intuition: Use the property of exponents: x^n = x^(n/2) * x^(n/2) if n is even, x^(n/2) * x^(n/2) * x if n is odd
*/

double optimizedRecursivePow(double x, long long n) {
    if(n == 0) return 1.0; // base case when n is 0
    if (n < 0) return 1 / optimizedRecursivePow(x, -n); // if the power is negative, then we need to divide the result by x  
    double result = optimizedRecursivePow(x, n / 2); // recursive call
    if(n % 2 == 0) return result * result; // if n is even, then we need to multiply the result by itself
    return result * result * x; // if n is odd, then we need to multiply the result by itself and x
}

/*
Approach 4: Using Inbuilt pow() Function
Time: O(log n) internally
Space: O(1)
Intuition: Use the inbuilt pow() function to calculate the power.
*/
double inbuiltPow(double x, long long n) {
    return pow(x, n);
}


int main()
{
    double x;
    long long n;
    // cout << "Enter the base: ";
    cin >> x;
    // cout << "Enter the power: ";
    cin >> n;
    cout << "The result is: " << myPow(x, n) << endl;
    cout << "The result is: " << recursivePow(x, n) << endl;
    cout << "The result is: " << optimizedRecursivePow(x, n) << endl;
    cout << "The result is: " << inbuiltPow(x, n) << endl;
    return 0;
}