class Solution {
    public int maxProfit(int[] prices) {
        int bsp, ssp, csp;
        bsp = -prices[0];
        ssp = csp = 0;
        
        for(int i = 1; i < prices.length; i++) {
            int nssp, ncsp, nbsp;
            nbsp = csp - prices[i];
            ncsp = Math.max(ssp, csp);
            nssp = prices[i] + bsp;
            
            bsp = Math.max(bsp, nbsp);
            csp = Math.max(csp, ncsp);
            ssp = Math.max(ssp, nssp);
        }
        
        csp = Math.max(csp, ssp);
        
        return csp;
    }
}