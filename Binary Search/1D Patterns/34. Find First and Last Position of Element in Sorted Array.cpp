#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem : Given an array of integers nums sorted in non-decreasing order, find the starting and ending position of a given target value. If target is not found in the array, return [-1, -1]. You must write an algorithm with $ O(\log n) $ runtime complexity.

// Example : 
// Constraint : 
// 0 <= nums.length <= 10^5
// -10^9 <= nums[i], target <= 10^9
// Array is sorted in non-decreasing order (ascending with duplicates allowed).

// 🔴 Approach 1 Brute Force : 
// Intuition :

// Array ke har element ko check karo, bhai.
// Jab target milta hai:

    // Agar pehli baar mil raha hai → first index set karo.
    // Last baar update hota rahega → last index set karo.

        // lastIndex hamesha target ka latest (rightmost) position store karega.
// End mein {first, last} return karo.

// Desi Analogy: Jaise ek class ke roll number list mein ek number (e.g., 7) ka pehla aur akhri appearance dhundh rahe ho. Har student ko check karo, pehla 7 mile toh note karo, aur last wala update karte jao.

// Algo :
// TC : O(n)
// SC : O(1)
pair<int, int> bruteForce(int n, int key, vector<int>& arr) {
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (first == -1) first = i; // first time milne par set
            last = i; // last occurrence update hoti rahegi
        }
    }
    return {first, last};
}
// 🔵 Approach 2 Better : (Linear Scan with Early Exit)
// Intuition :

// Brute force mein hum pura array scan karte hain, chahe first aur last mil jaye. Thoda optimize kar sakte hain:

// Ek baar first mil jaye, toh uske baad sirf last dhundho.
// Agar target milta hai aur uske baad target nahi milta, toh break kar sakte hain.


// Desi Analogy: Jaise roll number list mein pehla 7 milne ke baad, sirf agle 7s ko check karo, aur jaise hi non-7 aaye, ruk jao kyunki last wala mil chuka hai.
// Algo :
// TC : O(n)
// Worst case mein pura array scan karna pad sakta hai, but early exit thodi optimization deta hai jab target ke baad non-target elements aate hain.
// SC : O(1)
pair<int, int> betterApproach(int n, int key, vector<int>& arr) {
    int first = -1, last = -1;
    for (int i = 0; i < n; i++) {
        if (arr[i] == key) {
            if (first == -1) first = i;
            last = i;
        } else if (first != -1) {
            break; // No more target possible in sorted array
        }
    }
    return {first, last};
}
// 🟢 Approach 3 Optimal: (Binary Search)
// Intuition :

// Array sorted hai — yeh strongly hints at Binary Search, kyunki hum search space ko har step mein half kar sakte hain.
// Par default Binary Search sirf koi bhi occurrence deta hai — hume chahiye:

    // First occurrence: Match milne ke baad bhi left mein jao, shayad aur pehle ho.
    // Last occurrence: Match milne ke baad right mein jao, shayad aur aage ho.


// Toh, modify Binary Search karo:

// Jab arr[mid] == key, mid store karo, aur:

    // First ke liye, left half mein search karo → shayad earlier occurrence mile.
    // Last ke liye, right half mein search karo → shayad later occurrence mile.

// Standard rules:

// If arr[mid] < key → right jao.
// If arr[mid] > key → left jao.


// Desi Analogy: Jaise ek bade register mein roll number 7 dhundh rahe ho. Jab 7 milta hai, toh pehla 7 ke liye peeche (left) dekho, aur akhri 7 ke liye aage (right) dekho. Har step mein aadhi list eliminate karo.

// Algo :
// TC : O(log n)
// SC : O(1)
int firstOccurrence(int n, int key, vector<int>& arr) {
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            res = mid;          // possible answer
            high = mid - 1;     // move left for earlier occurrence
        } else if (key < arr[mid]) {
            high = mid - 1;     // go left
        } else {
            low = mid + 1;      // go right
        }
    }
    return res;
}

int lastOccurrence(int n, int key, vector<int>& arr) {
    int low = 0, high = n - 1;
    int res = -1;
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (arr[mid] == key) {
            res = mid;          // possible answer
            low = mid + 1;      // move right for later occurrence
        } else if (key < arr[mid]) {
            high = mid - 1;     // go left
        } else {
            low = mid + 1;      // go right
        }
    }
    return res;
}

vector<int> searchRange(vector<int>& nums, int target) {
    int n = nums.size();
    return {firstOccurrence(n, target, nums), lastOccurrence(n, target, nums)};
}
// 🟢 Approach 4: Optimal (Recursive Binary Search)
// Intuition:

// Same as iterative, but use recursion to search left/right halves.
// Jab arr[mid] == key, recursively check earlier/later occurrences and pick the best.
// Desi Analogy: Jaise register ke pages ko recursively aadha karte jao, aur jab 7 mile, toh pehla ya akhri 7 confirm karne ke liye left ya right pages check karo.

// Algo:

// TC: O(log n)
// Recursive calls follow binary search logic.
// SC: O(log n)
// Due to recursion stack.

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

vector<int> searchRangeRecursive(vector<int>& nums, int target) {
    int n = nums.size();
    return {firstOccurrenceRecursive(nums, target, 0, n - 1), 
            lastOccurrenceRecursive(nums, target, 0, n - 1)};
}
int main() {
    vector<int> arr = {5, 7, 7, 8, 8, 10};
    int key = 8;
    int n = arr.size();

    // Brute Force
    pair<int, int> brute = bruteForce(n, key, arr);
    cout << "BruteForce: [" << brute.first << ", " << brute.second << "]" << endl;

    // Better Approach
    pair<int, int> better = betterApproach(n, key, arr);
    cout << "Better Approach: [" << better.first << ", " << better.second << "]" << endl;

    // Iterative Binary Search
    vector<int> result = searchRange(arr, key);
    cout << "Iterative Binary Search: [" << result[0] << ", " << result[1] << "]" << endl;

    // Recursive Binary Search
    result = searchRangeRecursive(arr, key);
    cout << "Recursive Binary Search: [" << result[0] << ", " << result[1] << "]" << endl;

    return 0;
}