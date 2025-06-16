#include <bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;
const int MAX = 10010;

vector<vector<int>> comb(MAX, vector<int>(20, 0));

// Precompute combinations using Pascal's Triangle
void precompute() {
    for (int i = 0; i < MAX; ++i) {
        comb[i][0] = 1;
        for (int j = 1; j < 20; ++j) {
            comb[i][j] = (comb[i - 1][j] + comb[i - 1][j - 1]) % MOD;
        }
    }
}

int idealArrays(int n, int maxValue) {
    precompute();
    
    int res = 0;
    for (int x = 1; x <= maxValue; ++x) {
        int num = x;
        map<int, int> factors;

        // Prime factorize
        for (int d = 2; d * d <= num; ++d) {
            while (num % d == 0) {
                factors[d]++;
                num /= d;
            }
        }
        if (num > 1) factors[num]++;

        // Multiply combinations
        long long ways = 1;
        for (auto [prime, exp] : factors) {
            ways = (ways * comb[n + exp - 1][exp]) % MOD;
        }

        res = (res + ways) % MOD;
    }
    return res;
}

int main() {
    int n = 5, maxValue = 3;
    cout << idealArrays(n, maxValue) << endl; // Output: 11
    return 0;
}
