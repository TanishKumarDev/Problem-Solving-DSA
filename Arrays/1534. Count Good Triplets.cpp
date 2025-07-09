#include <bits/stdc++.h>
using namespace std;

// Brute Force
int countGoodTripletsBrute(vector<int>& arr, int a, int b, int c) {
    int count = 0, n = arr.size();
    for (int i = 0; i <= n-3; i++) {
        for (int j = i+1; j <= n-2; j++) {
            for (int k = j+1; k <= n-1; k++) {
                if (abs(arr[i] - arr[j]) <= a && abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                    count++;
                }
            }
        }
    }
    return count;
}

// Optimized Brute Force (Early Check)
int countGoodTripletsOptimized(vector<int>& arr, int a, int b, int c) {
    int count = 0, n = arr.size();
    for (int i = 0; i <= n-3; i++) {
        for (int j = i+1; j <= n-2; j++) {
            if (abs(arr[i] - arr[j]) <= a) { // Early check for first condition
                for (int k = j+1; k <= n-1; k++) {
                    if (abs(arr[j] - arr[k]) <= b && abs(arr[i] - arr[k]) <= c) {
                        count++;
                    }
                }
            }
        }
    }
    return count;
}

int main() {
    vector<int> arr = {3, 0, 1, 1, 9, 7};
    int a = 7, b = 2, c = 3;

    cout << countGoodTripletsBrute(arr, a, b, c) << endl;
    cout << countGoodTripletsOptimized(arr, a, b, c) << endl;

    return 0;
}
