class Solution {
public:
    int inf = INT_MAX - 1;
    int coinChange(vector<int>& coins, int sum) {
        int n = coins.size();
        int dp[n + 1][sum + 1];
        // Initialization
        for (int i = 0 ; i < n + 1; i++) {
            for (int j = 0 ; j < sum + 1 ; j++) {
                if (j == 0)
                    dp[i][j] = 0;
                if (i == 0)
                    dp[i][j] = inf;
            }
        }

        // Twist
        for (int j = 1; j < sum + 1; j++) {
            if (j % coins[0] == 0) {
                dp[1][j] = j / coins[0];
            }
            else {
                dp[1][j] = inf;
            }
        }

        // Code
        for (int i = 2 ; i < n + 1; i++) {
            for (int j = 1 ; j < sum + 1 ; j++) {
                if (coins[i - 1] <= j) {
                    dp[i][j] = min(dp[i - 1][j], dp[i][j - coins[i - 1]] + 1);
                }

                else {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        
        if(dp[n][sum] == inf) return -1;
        return dp[n][sum];
    }
};