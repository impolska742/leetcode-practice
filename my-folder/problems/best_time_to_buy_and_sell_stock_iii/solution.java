class Solution {
    public int maxProfit(int[] prices) {
        int[] dpLeft = new int[prices.length];
        int leastSoFar = prices[0];
        
        for(int i = 1; i < prices.length; i++) {
            leastSoFar = Math.min(leastSoFar, prices[i]);
            int currProfit = prices[i] - leastSoFar;
            dpLeft[i] = Math.max(dpLeft[i - 1], currProfit);
        }
        
        int[] dpRight = new int[prices.length];
        int largestAfterCurrent = prices[prices.length - 1];
        
        for(int i = prices.length - 2; i >= 0; i--) {
            largestAfterCurrent = Math.max(largestAfterCurrent, prices[i]);
            int currProfit = largestAfterCurrent - prices[i];
            dpRight[i] = Math.max(dpRight[i + 1], currProfit);
        }
        
        int answer = dpLeft[0] + dpRight[0];
        for(int i = 0; i < prices.length; i++) {
            answer = Math.max(answer, dpLeft[i] + dpRight[i]);
        }
        
        return answer;
    }
}