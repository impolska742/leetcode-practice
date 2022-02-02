class Solution {
public:
    void solve(int r, int c, vector<vector<char>> &board, string word, vector<vector<bool>> &visited, bool &yes, int idx) {
        if(yes || idx == word.size()) {
            yes = true;
            return;
        }
        
        visited[r][c] = true;
        int n = board.size();
        int m = board[0].size();
        int dx[] = {0,1,0,-1};
        int dy[] = {1,0,-1,0};
        
        for(int dir = 0; dir < 4; dir++) {
            int rr = r + dx[dir];
            int cc = c + dy[dir];
            
            if(rr >= 0 and rr < n and cc >= 0 and cc < m) {
                if(!visited[rr][cc] && board[rr][cc] == word[idx])
                    solve(rr, cc, board, word, visited, yes, idx + 1);
            }
        }
        
        visited[r][c] = false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        for(int r = 0; r < board.size(); r++) {
            for(int c = 0; c < board[0].size(); c++) {
                if(board[r][c] == word[0]) {
                    bool yes = false;
                    
                    vector<vector<bool>> visited(board.size(), vector<bool> (board[0].size(), false));
                    
                    solve(r, c, board, word, visited, yes, 1);
                    
                    if(yes)
                        return true;
                }
            }
        }
        
        return false;
    }
};