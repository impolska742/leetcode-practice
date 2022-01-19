class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int A[9][9] = {0};
        int B[9][9] = {0};
        int C[3][3][9] = {0};
        
        for(int i = 0; i < 9; i++) {
            for(int j = 0; j < 9; j++) {
                if(board[i][j] != '.') {
                    int num = board[i][j] - '1';
                    if(A[num][i] or B[num][j] or C[i/3][j/3][num])
                        return false;
                    A[num][i]++;
                    B[num][j]++;
                    C[i/3][j/3][num]++;
                }
            }
        }
        return true;
    }
};