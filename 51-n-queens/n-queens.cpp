class Solution {
public:
    bool isSafe(int row, int col, vector<vector<string>> &board, int n) {
        // Check left side in the same row
        for(int y = col-1; y >= 0; y--) {
            if(board[row][y] == "Q") return false;
        }
        
        // Check upper-left diagonal
        for(int x = row-1, y = col-1; x >= 0 && y >= 0; x--, y--) {
            if(board[x][y] == "Q") return false;
        }
        
        // Check lower-left diagonal
        for(int x = row+1, y = col-1; x < n && y >= 0; x++, y--) {
            if(board[x][y] == "Q") return false;
        }
        
        return true;
    }

    void addSolution(vector<vector<string>> &ans, vector<vector<string>> &board, int n) {
        vector<string> temp;
        for(int i = 0; i < n; i++) {
            string row = "";
            for(int j = 0; j < n; j++) {
                row += board[i][j];  // Build the row as a single string
            }
            temp.push_back(row);
        }
        ans.push_back(temp);
    }

    void solver(int c, vector<vector<string>> &board, vector<vector<string>> &ans, int n) {
        if(c == n) {
            addSolution(ans, board, n);
            return;
        }
        
        for(int row = 0; row < n; row++) {
            if(isSafe(row, c, board, n)) {
                board[row][c] = "Q";
                solver(c + 1, board, ans, n);
                board[row][c] = ".";  // Backtrack
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        // Correct initialization - n rows, each with n strings of "."
        vector<vector<string>> board(n, vector<string>(n, "."));
        vector<vector<string>> ans;
        solver(0, board, ans, n);
        return ans;
    }
};