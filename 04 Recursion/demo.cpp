#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        if (board.empty() || board[0].empty()) return false;
        
        int m = board.size();
        int n = board[0].size();
        
        // Try each cell as starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (dfs(board, word, i, j, 0)) {
                    return true;
                }
            }
        }
        return false;
    }
    
private:
    bool dfs(vector<vector<char>>& board, string& word, int i, int j, int k) {
        if (k == word.length()) return true;
        
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || 
            board[i][j] != word[k]) {
            return false;
        }
        
        char temp = board[i][j];
        board[i][j] = '#';  // mark as visited
        
        bool found = dfs(board, word, i+1, j, k+1) ||  // down
                     dfs(board, word, i-1, j, k+1) ||  // up
                     dfs(board, word, i, j+1, k+1) ||  // right
                     dfs(board, word, i, j-1, k+1);    // left
        
        board[i][j] = temp;  // restore the cell
        
        return found;
    }
};