class Solution {
public:
    bool checkValid(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<bool>> checkRow(n, vector<bool> (n, false));
        vector<vector<bool>> checkCol(n, vector<bool> (n, false));
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(checkRow[matrix[i][j] - 1][i] or checkCol[matrix[i][j] - 1][j])
                    return false;
                checkRow[matrix[i][j] - 1][i] = true;
                checkCol[matrix[i][j] - 1][j] = true;
            }
        }
        
        for(int num = 0; num < n; num++) {
            for(int idx = 0; idx < n; idx++) {
                if(checkRow[num][idx] == false or checkCol[num][idx] == false)
                    return false;
            }
        }
        return true;
    }
};