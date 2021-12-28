class Solution {
public:
    int maxProfit(int k, vector<int>& arr) {
        if(k == 0 or arr.size() == 0) return 0;
        
        int dp[arr.size()][k + 1];
        memset(dp, 0, sizeof(dp));

        for (int txn = 1; txn < k + 1; txn++) {
            int maxDiff = INT_MIN;
            for (int day = 1; day < arr.size(); day++) {
                int profitBeforeToday = dp[day - 1][txn];
                maxDiff = max(maxDiff, dp[day - 1][txn - 1] - arr[day - 1]);
                dp[day][txn] = max(profitBeforeToday, maxDiff + arr[day]);
            }
        }

        return dp[arr.size() - 1][k];
    }
};