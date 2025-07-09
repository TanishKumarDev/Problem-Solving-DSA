#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : 
// Example : 
// Constraint : 

// 🔴 Approach 1 Brute Force : 
// Intuition :
// Algo :
// TC :
// SC :

// 🔵 Approach 2 Better : 
// Intuition :
// Algo :
// TC :
// SC :

// 🟢 Approach 3 Optimal: 
// Intuition :

// select minimums and swap them to the front.
// Key Idea: Find the minimum element in the unsorted portion and place it at the beginning.
// Algo :

// Step 1: Find minimum in entire array, swap with first element.
// Step 2: Find minimum in remaining array (excluding first), swap with second element.
// Step 3: Continue until only one element remains (already sorted).

// TC : O(n^2)
// SC : O(1) (in-place) 

void selectionSort(int array[], int n) {
    for (int i = 0; i < n-1; i++) {
        int minIndex = i;
        for (int j = i; j < n; j++) {
            if (array[j] < array[minIndex]) {
                minIndex = j;
            }
        }
        int temp = array[i];
        array[i] = array[minIndex];
        array[minIndex] = temp;
    }
}

int main()
{
    int n;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++) {
        cin >> array[i];
    }
    selectionSort(array, n);
    for (int i = 0; i < n; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
    return 0;
    return 0;
}