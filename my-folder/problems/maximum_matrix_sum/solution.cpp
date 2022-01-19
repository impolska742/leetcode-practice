class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int mini = INT_MAX;
        int n = matrix.size();
        int count_neg = 0;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                if(matrix[i][j] < 0) count_neg++;
                mini = min(mini, abs(matrix[i][j]));
                ans += abs(matrix[i][j]);
            }
        }
        
        if(count_neg % 2 == 0) return ans;
        
        return ans - 2*mini;
    }
};