class Solution {
    public int maximumWealth(int[][] accounts) {
        int maxWealth = Integer.MIN_VALUE;
        for(int[] customer : accounts) {
            int wealth = 0;
            for(int num : customer) {
                wealth = wealth + num;
            }
            maxWealth = Math.max(maxWealth, wealth);
        }
        
        return maxWealth;
    }
}