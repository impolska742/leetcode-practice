class Solution {
public:
    void transpose(vector<vector<int>> &matrix) {
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = i + 1; j < matrix[0].size(); j++) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }
    }
    
    void reverse(vector<int> &row) {
        int lo = 0, hi = row.size() - 1;
        while(lo <= hi) {
            swap(row[lo], row[hi]);
            lo++, hi--;
        }
    }
    
    void rotate(vector<vector<int>>& matrix) {
        transpose(matrix);
        for(vector<int> &row : matrix) {
            reverse(row);
        }
    }
};