#include <bits/stdc++.h>
using namespace std;

// largest element (Brute Force)
int findLargestBruteForce(vector<int>& arr) {
    // tc - O(n^2), sc - O(1)

    // Intuition: Compare every element with every other element to find the maximum
    // Imagine you have a list of numbers with duplicates, like [1, 1, 2, 2, 3].
    // A set automatically removes duplicates because it only stores unique elements.
    // So, we dump all numbers into a set → duplicates disappear!
    // Then, we copy the unique numbers back into the original array.

    // Why it works:
    // ✅ Easy to understand (just filtering duplicates).
    // ❌ Uses extra space (O(n)) and takes more time (O(n log n)) due to set operations.

    // Example:
    // Input: [1, 1, 2, 2, 3]
    // Set stores: {1, 2, 3}
    // Final array (first 3 elements): [1, 2, 3]

    // Why INT_MIN? It's the smallest possible integer, so any number in array will be larger
    int largest = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            // Compare pairs and keep track of maximum
            largest = max(largest, arr[i]);
            largest = max(largest, arr[j]);
        }
    }
    return largest;
}

// largest element (Better Approach)
int findLargestBetter(vector<int>& arr) {
    // tc - O(n), sc - O(1)
    
    // Intuition: Single pass through array, updating largest when we find bigger element
    // Works only on sorted arrays (or if we sort first).

    // Uses two pointers:
    // i → Tracks the position of the last unique element.
    // j → Scans the entire array for new unique elements.
    // Whenever nums[j] is different from nums[i], we move i forward and store the new unique number.

    // Why it works:
    // ✅ No extra space (modifies array in-place).
    // ✅ Super fast (O(n) time) – just one pass through the array.
    // ❌ Requires the array to be sorted first (but sorting can be done in O(n log n) if needed).
    int largest = INT_MIN; // Initialize with smallest possible value
    for (int i = 0; i < arr.size(); i++) {
        if (arr[i] > largest) {
            largest = arr[i]; // Update largest when current element is bigger
        }
    }
    return largest;
}

// largest element (Optimal Approach)
int findLargestOptimal(vector<int>& arr) {
    // tc - O(n log n), sc - O(1)
    // Intuition: After sorting, largest element is always at the end
    sort(arr.begin(), arr.end());
    return arr.back(); // Last element is largest after sorting
}

// second largest element (Brute Force)
int findSecondLargestBruteForce(vector<int>& arr) {
    // tc - O(n^2), sc - O(1)
    // Intuition: Similar to finding largest, but track second largest in comparisons
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] > arr[j]) {
                largest = max(largest, arr[i]);
                // Second largest is max between current secondLargest and the smaller number
                secondLargest = max(secondLargest, arr[j]);
            } else {
                largest = max(largest, arr[j]);
                secondLargest = max(secondLargest, arr[i]);
            }
        }
    }
    return secondLargest;
}

// second largest element (Better Approach)
int findSecondLargestBetter(vector<int>& arr) {
    // tc - O(n), sc - O(1)
    // Intuition: Track both largest and second largest in single pass
    int largest = INT_MIN, secondLargest = INT_MIN;
    for (int num : arr) {
        if (num > largest) {
            // When we find new largest, old largest becomes second largest
            secondLargest = largest;
            largest = num;
        } else if (num > secondLargest && num != largest) {
            // Update secondLargest if number is between largest and current secondLargest
            secondLargest = num;
        }
    }
    return secondLargest;
}

// second largest element (Optimal Approach)
int findSecondLargestOptimal(vector<int>& arr) {
    // tc - O(n log n), sc - O(1)
    // Intuition: After sorting, second last element is second largest
    sort(arr.begin(), arr.end());
    return arr[arr.size() - 2];
}

// smallest element (Brute Force)
int findSmallestBruteForce(vector<int>& arr) {
    // tc - O(n^2), sc - O(1)
    // Intuition: Compare every element with every other element to find minimum
    // Why INT_MAX? It's the largest possible integer, so any number in array will be smaller
    int smallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            smallest = min(smallest, arr[i]);
            smallest = min(smallest, arr[j]);
        }
    }
    return smallest;
}

// smallest element (Better Approach)
int findSmallestBetter(vector<int>& arr) {
    // tc - O(n), sc - O(1)
    // Intuition: Single pass through array, updating smallest when we find smaller element
    int smallest = INT_MAX; // Initialize with largest possible value
    for (int num : arr) {
        if (num < smallest) {
            smallest = num;
        }
    }
    return smallest;
}

// smallest element (Optimal Approach)
int findSmallestOptimal(vector<int>& arr) {
    // tc - O(n log n), sc - O(1)
    // Intuition: After sorting, smallest element is always at the beginning
    sort(arr.begin(), arr.end());
    return arr[0];
}

// second smallest element (Brute Force)
int findSecondSmallestBruteForce(vector<int>& arr) {
    // tc - O(n^2), sc - O(1)
    // Intuition: Similar to finding smallest, but track second smallest in comparisons
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int i = 0; i < arr.size(); i++) {
        for (int j = i + 1; j < arr.size(); j++) {
            if (arr[i] < arr[j]) {
                smallest = min(smallest, arr[i]);
                secondSmallest = min(secondSmallest, arr[j]);
            } else {
                smallest = min(smallest, arr[j]);
                secondSmallest = min(secondSmallest, arr[i]);
            }
        }
    }
    return secondSmallest;
}

// second smallest element (Better Approach)
int findSecondSmallestBetter(vector<int>& arr) {
    // tc - O(n), sc - O(1)
    // Intuition: Track both smallest and second smallest in single pass
    int smallest = INT_MAX, secondSmallest = INT_MAX;
    for (int num : arr) {
        if (num < smallest) {
            // When we find new smallest, old smallest becomes second smallest
            secondSmallest = smallest;
            smallest = num;
        } else if (num < secondSmallest && num != smallest) {
            // Update secondSmallest if number is between smallest and current secondSmallest
            secondSmallest = num;
        }
    }
    return secondSmallest;
}

// second smallest element (Optimal Approach)
int findSecondSmallestOptimal(vector<int>& arr) {
    // tc - O(n log n), sc - O(1)
    // Intuition: After sorting, second element is second smallest
    sort(arr.begin(), arr.end());
    return arr[1];
}

int main() {
    vector<int> arr = {12, 34, 10, 25, 24, 40, 7};

    cout << "=== Largest Element ===" << endl;
    cout << "Brute Force: " << findLargestBruteForce(arr) << endl;
    cout << "Better: " << findLargestBetter(arr) << endl;
    cout << "Optimal: " << findLargestOptimal(arr) << endl << endl;

    cout << "=== Second Largest Element ===" << endl;
    cout << "Brute Force: " << findSecondLargestBruteForce(arr) << endl;
    cout << "Better: " << findSecondLargestBetter(arr) << endl;
    cout << "Optimal: " << findSecondLargestOptimal(arr) << endl << endl;

    cout << "=== Smallest Element ===" << endl;
    cout << "Brute Force: " << findSmallestBruteForce(arr) << endl;
    cout << "Better: " << findSmallestBetter(arr) << endl;
    cout << "Optimal: " << findSmallestOptimal(arr) << endl << endl;

    cout << "=== Second Smallest Element ===" << endl;
    cout << "Brute Force: " << findSecondSmallestBruteForce(arr) << endl;
    cout << "Better: " << findSecondSmallestBetter(arr) << endl;
    cout << "Optimal: " << findSecondSmallestOptimal(arr) << endl;

    return 0;
}


/* 

// Explanations

// INT_MIN/INT_MAX Usage:

- For finding maximums, we initialize with INT_MIN (smallest possible integer) so any array element will be larger

- For finding minimums, we initialize with INT_MAX (largest possible integer) so any array element will be smaller

- This ensures our initial values will always be replaced by actual array values

// Approach Intuitions:

- Brute Force: Compare all possible pairs (nested loops) - simple but inefficient

- Better: Single pass through array, updating target value when found - efficient and straightforward

- Optimal: Use sorting to bring elements in order - clean but has higher time complexity due to sorting

// Second Largest/Smallest Logic:

- When we find a new largest, the previous largest becomes second largest

- We need additional checks to ensure we don't count duplicates as second largest/smallest

// Time Complexities:

- Brute Force: O(n²) - Nested loops

- Better: O(n) - Single pass

- Optimal: O(n log n) - Due to sorting
*/