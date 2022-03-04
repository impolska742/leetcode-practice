class Solution {
public:
    double champagneTower(int poured, int query_row, int query_glass) {
        double dp[102][102] = {0.00};
        dp[0][0] = poured;
        
        for(int row = 0; row <= query_row; row++) {
            for(int col = 0; col <= row; col++) {
                if(dp[row][col] >= 1) {
                    dp[row + 1][col] += (dp[row][col] - 1)/2.00;
                    dp[row + 1][col + 1] += (dp[row][col] - 1)/2.00;
                    dp[row][col] = 1;
                } 
            }
        }
        
        return dp[query_row][query_glass];
    }
};