#include <bits/stdc++.h>
using namespace std;

int main() {
    vector<int> arr = {1, 3, 2, 1, 4, 2, 2, 3, 3};

    map<int, int> freq;

    // Step 1: Count frequencies
    for (int num : arr) {
        freq[num]++;
    }

    // Step 2: Find max and min frequency
    int maxFreq = 0, minFreq = INT_MAX;

    for (auto it : freq) {
        maxFreq = max(maxFreq, it.second);
        minFreq = min(minFreq, it.second);
    }

    // Step 3: Collect elements with max/min frequency
    vector<int> maxFreqElems, minFreqElems;

    for (auto it : freq) {
        if (it.second == maxFreq) maxFreqElems.push_back(it.first);
        if (it.second == minFreq) minFreqElems.push_back(it.first);
    }

    // Output
    cout << "Max Frequency = " << maxFreq << " → Elements: ";
    for (int x : maxFreqElems) cout << x << " ";
    cout << endl;

    cout << "Min Frequency = " << minFreq << " → Elements: ";
    for (int x : minFreqElems) cout << x << " ";
    cout << endl;

    return 0;
}
