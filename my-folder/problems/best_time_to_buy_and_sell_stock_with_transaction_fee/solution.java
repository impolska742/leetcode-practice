class Solution {
    public int maxProfit(int[] prices, int fee) {
        int bsp = -prices[0];
        int ssp = 0;
        
        for(int i = 1; i < prices.length; i++) {
            int nbsp = Math.max(bsp, ssp - prices[i]);
            int nssp = Math.max(ssp, prices[i] + bsp - fee);
            
            bsp = nbsp;
            ssp = nssp;
        }
        
        return ssp;
    }
}