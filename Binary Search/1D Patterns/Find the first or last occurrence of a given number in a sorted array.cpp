#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Given a sorted array of N integers, write a program to find the index of the last occurrence of the target key. If the target is not found then return -1.
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : Last occurrence in a sorted array

// Intuition :
// As the array is already sorted, start traversing the array from the back using a for loop and check whether the element is present or not.
// If the target element is present, break out of the loop and print the resulting index.
// If the target element is not present inside the array, then print -1

// Algo :

// TC : O(n) 
// SC : O(1) not considering the given array
int BruteForce(int n, int key, vector<int> &arr) {
    int res = -1;
    for (int i=n-1; i>=0; i--){
        if(arr[i] == key){
            res = i;
            break;
        }
    }
    return res;
}
// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: Binary search

// Intuition (Step-by-step):
// 1. The array is sorted — this strongly hints Binary Search.
// 2. But default Binary Search returns any occurrence — we need:

    // First occurrence: go left after match.
    // Last occurrence: go right after match.

// 3. So, modify the Binary Search:
    // When arr[mid] == key, store mid, and continue:
        // For first, search left half → maybe there's another occurrence earlier.
        // For last, search right half → maybe there's another occurrence later.

// 4. Standard rules:
    // If arr[mid] < key → go right
    // If arr[mid] > key → go left

// Algo :

// TC : O(log n) 
// SC : O(1)

int firstOccurrence(int n, int key, vector<int> &arr) {
    int low = 0, high = n - 1;
    int res = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key){
            res = mid;            // possible answer
            high = mid - 1;       // move left for earlier occurrence
        } else if(key < arr[mid]){
            high = mid - 1;       // go left
        } else {
            low = mid + 1;        // go right
        }
    }
    return res;
}
int lastOccurrence(int n, int key, vector<int> &arr) {
    int low = 0, high = n - 1;
    int res = -1;

    while(low <= high){
        int mid = low + (high - low) / 2;
        if(arr[mid] == key){
            res = mid;            // possible answer
            low = mid + 1;        // move right for later occurrence
        } else if(key < arr[mid]){
            high = mid - 1;       // go left
        } else {
            low = mid + 1;        // go right
        }
    }
    return res;
}

int main()
{
    vector<int> arr = {1, 2, 2, 2, 3, 4};
    int key = 2;
    int n = arr.size();

    // Make sure the array is sorted before applying binary search
    sort(arr.begin(), arr.end());


    // Brute Force
    cout << "BruteForce: " << BruteForce(n, key, arr) << endl;
    cout << "firstOccurrence: " << firstOccurrence(n, key, arr) << endl;
    cout << "lastOccurrence: " << lastOccurrence(n, key, arr) << endl;
    return 0;
}