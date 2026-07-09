class Solution {
public:
    bool isSafe(int row,int col,vector<vector<char>>& sudoku,int val){
        for(int i=0;i<sudoku.size();i++){
            if(sudoku[row][i]==(val+'0')){
                return false;
            }
            if(sudoku[i][col]==(val+'0')){
                return false;
            }
            if(sudoku[3*(row/3)+i/3][3*(col/3)+i%3]== (val+'0')){
                return false;
            }

        }
        return true;
    }
    bool solver(vector<vector<char>>& sudoku){
        int n=sudoku.size();
        for(int r=0;r<n;r++){
            for(int c=0;c<n;c++){
                if(sudoku[r][c]=='.'){
                    for(int val=1;val<=9;val++){
                        if(isSafe(r,c,sudoku,val)){
                            sudoku[r][c]=(val+'0');
                            bool isSolPossible=solver(sudoku);
                            if(isSolPossible){
                                return true;
                            }else{
                                sudoku[r][c]='.';
                            }
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solver(board);
    }
};