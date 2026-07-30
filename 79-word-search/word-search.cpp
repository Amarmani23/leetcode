class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        for (int r = 0; r < row; ++r) {
            for (int c = 0; c < col; ++c) {
                if (board[r][c] == word[0]) {
                    // Fix 2: Check return value from backtrack
                    if (backtrack(board, word, r, c, 0)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }

private:
    // Direction offsets: Up, Right, Down, Left
    const int dr[4] = {-1, 0, 1, 0};
    const int dc[4] = {0, 1, 0, -1};

    bool backtrack(vector<vector<char>>& board, string& word, int r, int c, int index) {
        // Base case 1: Found the entire word
        if (index == word.size()) {
            return true;
        }

        // Base case 2: Out of bounds or character mismatch
        if (r < 0 || r >= board.size() || c < 0 || c >= board[0].size() || board[r][c] != word[index]) {
            return false;
        }

        char temp = board[r][c];
        board[r][c] = '#'; // Mark visited

        // Fix 1 & 3: Proper direction traversal + early exit on success
        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i];
            int nc = c + dc[i];
            
            if (backtrack(board, word, nr, nc, index + 1)) {
                board[r][c] = temp; // Restore before returning
                return true;
            }
        }

        board[r][c] = temp; // Backtrack / restore state
        return false;
    }
};