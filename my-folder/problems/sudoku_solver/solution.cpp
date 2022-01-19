class Solution {
public:
    void showBoard(vector<vector<char>> board) {
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                cout << board[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }

    bool isValid(vector<vector<char>> &board, int r, int c, char option) {
        // for current row
        for (int col = 0; col < board[0].size(); col++) {
            if (board[r][col] == option) return false;
        }

        // for current column
        for (int row = 0; row < board.size(); row++) {
            if (board[row][c] == option) return false;
        }

        int sub_row = r - r % 3;
        int sub_col = c - c % 3;

        for (int x = 0; x < 3; x++) {
            for (int y = 0; y < 3; y++) {
                if (board[sub_row + x][sub_col + y] == option)
                    return false;
            }
        }

        return true;
    }

    bool solve(vector<vector<char>> &board, int r, int c) {
        // base condition
        if (r == board.size()) {
            showBoard(board);
            return true;
        }

        // calculating upcoming calls
        int next_r = 0, next_c = 0;
        if (c == board[0].size() - 1) {
            next_r = r + 1;
            next_c = 0;
        } else {
            next_r = r;
            next_c = c + 1;
        }

        if (board[r][c] != '.')
            return solve(board, next_r, next_c);
        else {
            for (char option = '1'; option <= '9'; option++) {
                if (isValid(board, r, c, option) == true) {
                    board[r][c] = option;
                    if (solve(board, next_r, next_c)) return true;
                    board[r][c] = '.';
                }
            }
        }
        return false;
    }

    void solveSudoku(vector<vector<char>> &board) {
        solve(board, 0, 0);
    }
};