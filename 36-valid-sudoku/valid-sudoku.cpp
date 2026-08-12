class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_set<char>row[9];
        unordered_set<char>col[9];
        unordered_set<char>boxes[9];
        
        
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                int val=board[i][j];
                if(val=='.') continue;
                int box_idx=(i/3)*3 + (j/3);
                if(row[i].count(val) || col[j].count(val) || boxes[box_idx].count(val)){
                    return false;
                }
                row[i].insert(val);
                col[j].insert(val);
                boxes[box_idx].insert(val);
            }
        }
        return true;
    }
};