class Solution {
    public int rob(int[] nums) {
        if(nums.length == 0) return 0;
        if(nums.length == 1) return nums[0];
        if(nums.length == 2) return Math.max(nums[0], nums[1]);
        int[] dp = new int[nums.length + 1];
        dp[0] = 0;
        dp[1] = nums[0];
        
        for(int i = 1; i < nums.length; i++) {
            int val = nums[i];
            dp[i + 1] = Math.max(dp[i - 1] + val, dp[i]);
        }
        
        return dp[nums.length];
    }
};