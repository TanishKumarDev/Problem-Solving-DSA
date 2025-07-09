#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Pow(x, n)
// Example: x = 2.0, n = 3 → 8.0; x = 2.0, n = -2 → 0.25
// Constraint: -100.0 < x < 100.0, -2^31 <= n <= 2^31-1

// 🔴 Naive Recursive (Not safe for INT_MIN)
double myPowNaive(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }
    if (N == 0) return 1.0;
    return x * myPowNaive(x, N - 1);
}

// 🟢 Optimized Recursive (Safe)
double myPowOptimal(double x, int n) {
    if (n == 0) return 1.0;

    long long N = n; // convert to long long to handle INT_MIN
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }

    double half = myPowOptimal(x, N / 2);
    return (N % 2 == 0) ? half * half : x * half * half;
}

// 🟡 Iterative Binary Exponentiation
double myPowIterative(double x, int n) {
    long long N = n;
    if (N < 0) {
        x = 1.0 / x;
        N = -N;
    }

    double result = 1.0;
    while (N > 0) {
        if (N % 2 == 1) result *= x;
        x *= x;
        N /= 2;
    }
    return result;
}

int main() {
    vector<pair<double, int>> tests = {
        {2.0, 3}, {2.0, -2}, {2.0, 0}, {0.0, 1}, {1.0, 5},
        {2.0, 10}, {-1.0, 3}, {2.0, INT_MIN}
    };

    cout << fixed << setprecision(5);
    for (auto [x, n] : tests) {
        cout << "x = " << x << ", n = " << n << endl;
        cout << "Naive:     " << myPowNaive(x, n) << endl;
        cout << "Optimal:   " << myPowOptimal(x, n) << endl;
        cout << "Iterative: " << myPowIterative(x, n) << endl;
        cout << "---------------------------" << endl;
    }

    return 0;
}
