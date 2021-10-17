class Solution {
    public boolean canPartition(int[] nums) {
        int sum = 0;
        for(int i = 0; i < nums.length; i++) {
            sum += nums[i];
        }
        
        if(sum % 2 != 0) return false;
        
        sum /= 2;
        boolean[][] dp = new boolean[nums.length + 1][sum + 1];
        
        for(int i = 0; i < nums.length + 1; i++) {
            for(int j = 0; j < sum + 1; j++) {
                if(i == 0 && j == 0) dp[i][j] = false;
                else if(i == 0) dp[i][j] = false;
                else if(j == 0) dp[i][j] = true;
                else {
                    dp[i][j] = dp[i - 1][j];
                    if(nums[i - 1] <= j) {
                        dp[i][j] = dp[i][j] || dp[i - 1][j - nums[i - 1]];
                    }
                }
            }
        }
        
        return dp[nums.length][sum];
    }
}