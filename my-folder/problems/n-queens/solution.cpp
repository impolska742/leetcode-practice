class Solution {
public:
    vector<vector<string>> ans;
    vector<bool> ld, rd, col;
    
    void solve(int n, vector<string> &board, int r) {
        if(r == n) {
            ans.push_back(board);
            return;
        }
        
        for(int c = 0; c < n; c++) {
            if(!col[c] and !ld[r + c] and !rd[r - c + n - 1]) {
                board[r][c] = 'Q';
                col[c] = true;
                ld[r + c] = true;
                rd[r - c + n - 1] = true;
                
                solve(n, board, r + 1);
                
                board[r][c] = '.';
                col[c] = false;
                ld[r + c] = false;
                rd[r - c + n - 1] = false;
            }
        }
    }
    
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));

        ld.resize(2 * n, false);
        rd.resize(2 * n, false);
        col.resize(n, false);
        
        solve(n, board, 0);
        
        return ans;
    }
};