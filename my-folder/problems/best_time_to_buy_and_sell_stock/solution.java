class Solution {
    public int maxProfit(int[] prices) {
        int maxProfit = 0;
        int lsf = prices[0];
        
        for(int i = 1; i < prices.length; i++) {
            lsf = Math.min(lsf, prices[i]);
            maxProfit = Math.max(prices[i] - lsf, maxProfit);
        }
        
        return maxProfit;
    }
}