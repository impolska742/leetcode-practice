class Solution {
    public int f(int[] arr) {
        int maxProfit = 0;
        for (int i = 0; i < arr.length - 1; i++) {
            if (arr[i] < arr[i + 1])
                maxProfit += arr[i + 1] - arr[i];
        }
        return maxProfit;
    }
    public int maxProfit(int k, int[] prices) {
        if(k == 0 || prices.length == 0) return 0;
        if(k > prices.length / 2) return f(prices);
        int[][] dp = new int[prices.length][k + 1];
        
        for(int txn = 1; txn <= k; txn++) {
            int maxDiff = Integer.MIN_VALUE;
            for(int day = 1; day < prices.length; day++) {
                int profitBeforeToday = dp[day - 1][txn];
                maxDiff = Math.max(maxDiff, dp[day - 1][txn - 1] - prices[day - 1]);
                dp[day][txn] = Math.max(profitBeforeToday, maxDiff + prices[day]);
            }
        }
        
        return dp[prices.length - 1][k];
    }
}