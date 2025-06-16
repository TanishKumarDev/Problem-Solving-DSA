#include <bits/stdc++.h>
using namespace std;

/*
Intuition:
- Divisors appear in pairs (i, n/i)
- Only need to check up to sqrt(n)
*/

// Approach 1: Brute Force (Full scan)
// Time: O(n)
// Space: O(1)
void printDivisorsBrute(int n) {
    for (int i = 1; i <= n; i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
}

// Approach 2: Better (Store and sort)
// Time: O(sqrt(n) + klogk) where k is number of divisors
// Space: O(k)
void printDivisorsBetter(int n) {
    vector<int> divisors;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            divisors.push_back(i);
            if (i != n/i) divisors.push_back(n/i);
        }
    }
    sort(divisors.begin(), divisors.end());
    for (int d : divisors) cout << d << " ";
}

// Approach 3: Optimal (Two loops)
// Time: O(sqrt(n))
// Space: O(1)
void printDivisorsOptimal(int n) {
    // First loop for divisors <= sqrt(n)
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            cout << i << " ";
        }
    }
    // Second loop for divisors > sqrt(n)
    for (int i = sqrt(n); i >= 1; i--) {
        if (n % i == 0 && i != n/i) {
            cout << n/i << " ";
        }
    }
}

int main() {
    int num;
    cin >> num; // Input a number

    cout << "Brute: "; printDivisorsBrute(num); cout << endl;
    cout << "Better: "; printDivisorsBetter(num); cout << endl;
    cout << "Optimal: "; printDivisorsOptimal(num); cout << endl;
    return 0;
}