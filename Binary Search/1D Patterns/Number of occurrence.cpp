#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Number of Occurrences
// Given a sorted array arr[] and a number target, you need to find the number of occurrences of target in arr[].

// Example:
// Input: arr = [1, 2, 2, 2, 3, 4], target = 2
// Output: 3
// Input: arr = [5, 7, 7, 8, 8, 10], target = 8
// Output: 2
// Input: arr = [1, 3, 5], target = 4
// Output: 0
// Input: arr = [], target = 0
// Output: 0

// Constraint:
// 0 <= arr.length <= 10^5
// -10^9 <= arr[i], target <= 10^9
// Array is sorted in non-decreasing order.

// 🔴 Approach 1: Brute Force
// Intuition:
// Array ke har element ko check karo.
// Jab target milta hai, count badhao.
// End me count return karo.
// Desi Analogy: Jaise class ke roll number list mein dekho kitne students ka roll number target hai.

// Algo:
// 1. Initialize count = 0.
// 2. Loop through array (i = 0 to n-1):
//    - If arr[i] == target, increment count.
// 3. Return count.

// TC: O(n)
// SC: O(1)

int bruteForce(int n, int key, vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) count++; // Count each occurrence
    }
    return count;
}

// 🔵 Approach 2: Better (Linear Scan with Early Exit)
// Intuition:
// Array sorted hai, toh target ke occurrences consecutive honge.
// Ek baar target shuru ho aur khatam ho jaye, toh aage check karne ki zarurat nahi.
// Desi Analogy: Jaise roll number list mein 7 milne ke baad, jab tak 7 aata hai count karo, aur jaise hi 8 aaye, ruk jao.

// Algo:
// 1. Initialize count = 0.
// 2. Loop through array (i = 0 to n-1):
//    - If arr[i] == target, increment count.
//    - Else if count > 0, break (no more target possible).
// 3. Return count.

// TC: O(n)
// SC: O(1)

int betterApproach(int n, int key, vector<int>& arr) {
    int count = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            count++;
        } else if (count > 0) {
            break; // No more target possible in sorted array
        }
    }
    return count;
}

// 🟢 Approach 3: Optimal (Iterative Binary Search)
// Intuition (Step-by-step):
// 1. Array sorted hai — yeh hints at Binary Search.
// 2. Number of occurrences = last occurrence - first occurrence + 1.
// 3. Modify Binary Search:
//    - First occurrence: When arr[mid] == target, store mid, search left.
//    - Last occurrence: When arr[mid] == target, store mid, search right.
// 4. Standard rules:
//    - If arr[mid] < target → go right
//    - If arr[mid] > target → go left
// Desi Analogy: Jaise register mein roll number 7 ke pehle aur akhri appearance dhundh rahe ho, binary search se aadhe pages eliminate karo.

// Algo:
// 1. Find first occurrence using binary search.
// 2. Find last occurrence using binary search.
// 3. If first == -1, return 0. Else, return last - first + 1.

// TC: O(log n)
// SC: O(1)

pair<int, int> firstAndLastPosition(vector<int>& arr, int target) {
    int n = arr.size();
    int first = -1, last = -1;

    // First occurrence
    int low = 0, high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            first = mid;
            high = mid - 1; // Move left for earlier occurrence
        } else if (arr[mid] < target) {
            low = mid + 1; // Go right
        } else {
            high = mid - 1; // Go left
        }
    }

    // Last occurrence
    low = 0; high = n - 1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == target) {
            last = mid;
            low = mid + 1; // Move right for later occurrence
        } else if (arr[mid] < target) {
            low = mid + 1; // Go right
        } else {
            high = mid - 1; // Go left
        }
    }

    return {first, last};
}

int countFreq(vector<int>& arr, int target) {
    auto ans = firstAndLastPosition(arr, target);
    if (ans.first == -1) return 0; // Not found
    return ans.second - ans.first + 1;
}

// 🟢 Approach 4: Optimal (Recursive Binary Search)
// Intuition:
// Same as iterative, lekin recursion se left/right halves search karo.
// Jab arr[mid] == target, recursively check earlier/later occurrences aur best answer return karo.
// Desi Analogy: Jaise register ke pages ko recursively aadha karte jao, aur jab target mile, toh pehla ya akhri confirm karo.

// Algo:
// 1. Find first occurrence recursively.
// 2. Find last occurrence recursively.
// 3. If first == -1, return 0. Else, return last - first + 1.

// TC: O(log n)
// SC: O(log n)

int firstOccurrenceRecursive(vector<int>& arr, int key, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        int earlier = firstOccurrenceRecursive(arr, key, low, mid - 1);
        return (earlier != -1 && earlier < mid) ? earlier : mid;
    } else if (key < arr[mid]) {
        return firstOccurrenceRecursive(arr, key, low, mid - 1);
    } else {
        return firstOccurrenceRecursive(arr, key, mid + 1, high);
    }
}

int lastOccurrenceRecursive(vector<int>& arr, int key, int low, int high) {
    if (low > high) return -1;
    int mid = low + (high - low) / 2;
    if (arr[mid] == key) {
        int later = lastOccurrenceRecursive(arr, key, mid + 1, high);
        return (later != -1 && later > mid) ? later : mid;
    } else if (key < arr[mid]) {
        return lastOccurrenceRecursive(arr, key, low, mid - 1);
    } else {
        return lastOccurrenceRecursive(arr, key, mid + 1, high);
    }
}

pair<int, int> firstAndLastPositionRecursive(vector<int>& arr, int target) {
    int n = arr.size();
    int first = firstOccurrenceRecursive(arr, target, 0, n - 1);
    int last = lastOccurrenceRecursive(arr, target, 0, n - 1);
    return {first, last};
}

int countFreqRecursive(vector<int>& arr, int target) {
    auto ans = firstAndLastPositionRecursive(arr, target);
    if (ans.first == -1) return 0; // Not found
    return ans.second - ans.first + 1;
}

// Main Function
int main() {
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int target = 2;
    int n = arr.size();

    // Brute Force
    cout << "BruteForce: " << bruteForce(n, target, arr) << endl;

    // Better Approach
    cout << "Better Approach: " << betterApproach(n, target, arr) << endl;

    // Iterative Binary Search
    cout << "Iterative Binary Search: " << countFreq(arr, target) << endl;

    // Recursive Binary Search
    cout << "Recursive Binary Search: " << countFreqRecursive(arr, target) << endl;

    return 0;
}