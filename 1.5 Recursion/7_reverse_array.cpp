#include <bits/stdc++.h>
using namespace std;

// Function to print array
void printArray(const vector<int> &arr) {
    for (int x : arr) cout << x << " ";
    cout << endl;
}

/* 
Approach 1: Brute Force (Using an Extra Array)
Intuition: Copy elements from back to front into a new array.
TC: O(n)
SC: O(n)
*/
vector<int> reverseArrayBrute(const vector<int> &arr) {
    int n = arr.size();
    vector<int> ans(n);
    for (int i = n - 1; i >= 0; i--) {
        ans[n - i - 1] = arr[i];
    }
    return ans;
}

/* 
Approach 2: In-place Iterative Method
Intuition: Use two pointers from start and end, swap until meeting at middle.
TC: O(n)
SC: O(1)
*/
void reverseArrayInPlace(vector<int> &arr) {
    int p1 = 0, p2 = arr.size() - 1;
    while (p1 < p2) {
        swap(arr[p1], arr[p2]);
        p1++;
        p2--;
    }
}

/* 
Approach 3: Recursive Method
Intuition: Swap start and end elements recursively until they meet.
TC: O(n)
SC: O(n) (due to recursion call stack)
*/
void reverseArrayRecursive(vector<int> &arr, int start, int end) {
    if (start >= end) return;
    swap(arr[start], arr[end]);
    reverseArrayRecursive(arr, start + 1, end - 1);
}

/* 
Approach 4: Using STL Reverse Function
Intuition: Use built-in reverse function which internally does two-pointer swap.
TC: O(n)
SC: O(1)
*/
void reverseArraySTL(vector<int> &arr) {
    reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    cin >> n;
    
    vector<int> arr(n);
    for (int &x : arr) cin >> x;

    // Brute Force Approach
    vector<int> resultBrute = reverseArrayBrute(arr);
    cout << "(Brute Force): ";
    printArray(resultBrute);

    // In-place Iterative Approach
    vector<int> arrInPlace = arr;
    reverseArrayInPlace(arrInPlace);
    cout << "(In-place Iterative): ";
    printArray(arrInPlace);

    // Recursive Approach
    vector<int> arrRecursive = arr;
    reverseArrayRecursive(arrRecursive, 0, arrRecursive.size() - 1);
    cout << "(Recursive): ";
    printArray(arrRecursive);

    // STL Reverse Approach
    vector<int> arrSTL = arr;
    reverseArraySTL(arrSTL);
    cout << "(STL): ";
    printArray(arrSTL);

    return 0;
}
