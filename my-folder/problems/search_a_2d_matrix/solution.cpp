class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = 0, col = matrix[0].size() - 1;
        while(row <= matrix.size() - 1 and col >= 0) {
            if(matrix[row][col] == target) {
                return true;
            }
            
            else if(matrix[row][col] > target) {
                col = col - 1;
            }
            else {
                row = row + 1;
            }
        }
        
        return false;
    }
};