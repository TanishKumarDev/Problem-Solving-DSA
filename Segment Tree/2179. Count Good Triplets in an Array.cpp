#include <bits/stdc++.h>
using namespace std;

// ✅ Segment Tree class to handle range sum queries and point updates
class SegmentTree {
    vector<int> tree;
    int n;

public:
    SegmentTree(int size) : n(size) {
        // Segment tree size = 4 * n (safe upper bound)
        tree.resize(4 * n, 0);
    }

    // Update function to increment count at a specific index
    void update(int index, int value, int node = 1, int l = 0, int r = 1e5) {
        if (l == r) {
            // Leaf node: add value (increment by 1)
            tree[node] += value;
            return;
        }

        int mid = (l + r) / 2;

        // Go left or right depending on index
        if (index <= mid)
            update(index, value, 2 * node, l, mid);
        else
            update(index, value, 2 * node + 1, mid + 1, r);

        // Update current node based on children
        tree[node] = tree[2 * node] + tree[2 * node + 1];
    }

    // Query function: return count of values in range [ql, qr]
    int query(int ql, int qr, int node = 1, int l = 0, int r = 1e5) {
        if (ql > r || qr < l) return 0; // No overlap
        if (ql <= l && r <= qr) return tree[node]; // Complete overlap

        // Partial overlap
        int mid = (l + r) / 2;
        return query(ql, qr, 2 * node, l, mid) +
               query(ql, qr, 2 * node + 1, mid + 1, r);
    }
};

// ✅ Main function to count good triplets
long long countGoodTriplets(vector<int>& nums1, vector<int>& nums2) {
    int n = nums1.size();

    // Step 1: Map value → index from nums2
    vector<int> pos(n);
    for (int i = 0; i < n; i++) {
        pos[nums2[i]] = i;
    }

    // Step 2: Build a mapped array where each element in nums1
    // is replaced by its position in nums2
    vector<int> mapped(n);
    for (int i = 0; i < n; i++) {
        mapped[i] = pos[nums1[i]];
    }

    // Step 3: Prepare arrays to store left and right counts
    vector<int> leftCount(n, 0), rightCount(n, 0);

    // Step 4: Build segment tree for left pass
    SegmentTree segLeft(1e5 + 1);
    for (int i = 0; i < n; i++) {
        int val = mapped[i];
        // Query how many values < val have been seen so far
        leftCount[i] = segLeft.query(0, val - 1);
        // Mark current value as seen
        segLeft.update(val, 1);
    }

    // Step 5: Build segment tree for right pass
    SegmentTree segRight(1e5 + 1);
    for (int i = n - 1; i >= 0; i--) {
        int val = mapped[i];
        // Query how many values > val exist on the right
        rightCount[i] = segRight.query(val + 1, n - 1);
        // Mark current value as seen
        segRight.update(val, 1);
    }

    // Step 6: Calculate final result using counts
    long long ans = 0;
    for (int i = 0; i < n; i++) {
        ans += 1LL * leftCount[i] * rightCount[i];
    }

    return ans;
}

// ✅Driver Code
int main() {
    // Sample Input
    vector<int> nums1 = {2, 0, 1, 3};
    vector<int> nums2 = {0, 1, 2, 3};

    // Function call
    cout << countGoodTriplets(nums1, nums2) << endl;

    return 0;
}
