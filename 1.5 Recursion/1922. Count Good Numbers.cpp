const int kMod = 1e9 + 7;

class Solution {
public:
    int countGoodNumbers(long long n) {
        // Calculate count of even and odd indexed positions
        long long evenPos = (n + 1) / 2;
        long long oddPos = n / 2;

        // 5 choices for even indices, 4 for odd indices
        long long evenCount = myPow(5, evenPos);
        long long oddCount = myPow(4, oddPos);

        return (evenCount * oddCount) % kMod;
    }

private:
    // Fast modular exponentiation: x^n % kMod
    long long myPow(long long x, long long n) {
        long long res = 1;
        x %= kMod;

        while (n > 0) {
            if (n % 2 == 1) {
                res = (res * x) % kMod;
            }
            x = (x * x) % kMod;
            n /= 2;
        }

        return res;
    }
};
