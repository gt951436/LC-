class Solution {
public:
    // Helper function for DFS traversal
    bool dfs(vector<vector<char>>& board, string word, int i, int j, int k) {
        // If we have found all characters of the word, return true
        if (k == word.size())
            return true;
        
        // Boundary check and character mismatch check
        if (i < 0 || i >= board.size() || j < 0 || j >= board[0].size() || word[k] != board[i][j])
            return false;
        
        // Temporarily mark the current cell as visited
        char ch = board[i][j];
        board[i][j] = '/';
        
        // Explore the neighbors recursively
        if (dfs(board, word, i + 1, j, k + 1) ||
            dfs(board, word, i, j + 1, k + 1) ||
            dfs(board, word, i - 1, j, k + 1) ||
            dfs(board, word, i, j - 1, k + 1))
            return true; // If any neighbor leads to finding the word, return true
        
        // Backtrack: Restore the original character in the current cell
        board[i][j] = ch;
        return false;
    }
    
    // Main function to check if the word exists on the board
    bool exist(vector<vector<char>>& board, string word) {
        int n = board.size(), m = board[0].size();
        // Iterate through each cell of the board
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                // If the current cell matches the first character of the word, start DFS from here
                if (board[i][j] == word[0]) {
                    if (dfs(board, word, i, j, 0)) // If DFS finds the word, return true
                        return true;
                }
            }
        }
        // If no cell leads to finding the word, return false
        return false;
    }
};