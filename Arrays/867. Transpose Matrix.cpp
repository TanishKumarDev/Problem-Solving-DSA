#include <bits/stdc++.h>
using namespace std;

// 🧠 Problem: Transpose Matrix (LeetCode 867)
// Example: matrix = [[1,2,3],[4,5,6],[7,8,9]] → [[1,4,7],[2,5,8],[3,6,9]]
// Constraints: 1 <= m, n <= 1000, -10^9 <= matrix[i][j] <= 10^9

// 🔴 Brute Force (Works for any matrix: m x n)
// Create a new matrix and copy the transpose into it.
// Time Complexity: O(m * n)
// Space Complexity: O(n * m)
vector<vector<int>> transposeBrute(vector<vector<int>>& matrix) {
    int m = matrix.size();        // Number of rows in original matrix
    int n = matrix[0].size();     // Number of columns in original matrix

    // Create result matrix of size n x m (transpose)
    vector<vector<int>> result(n, vector<int>(m, 0));

    // Copy element at (i, j) to (j, i)
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            result[j][i] = matrix[i][j];
        }
    }

    return result;
}

// 🟢 Optimized In-Place Transpose (Only works for square matrices)
// This swaps matrix[i][j] with matrix[j][i] for i < j
// Time Complexity: O(n²)
// Space Complexity: O(1) — In-place
void transposeInPlace(vector<vector<int>>& matrix) {
    int n = matrix.size(); // Only valid if matrix is square (n x n)

    // Only upper triangle (excluding diagonal) is processed
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            // Swap symmetric elements across the diagonal
            swap(matrix[i][j], matrix[j][i]);
        }
    }
}

int main() {
   
    return 0;
}
