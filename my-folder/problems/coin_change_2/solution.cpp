class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int dp[amount + 1];
        memset(dp, 0, sizeof(dp));
        
        dp[0] = 1;
        
        for(auto coin : coins) {
            for(int amt = 0; amt <= amount; amt++) {
                if(coin <= amt) {
                    dp[amt] += dp[amt - coin];
                }
            }
        }
        
        return dp[amount];
    }
};