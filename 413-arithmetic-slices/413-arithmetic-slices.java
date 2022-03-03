class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int[] dp = new int[n];
        int res = 0;
        
        for(int i = 1; i < n - 1; i++) {
            int prev = nums[i - 1];
            int curr = nums[i];
            int next = nums[i + 1];
            
            if(curr - prev == next - curr) {
                dp[i] = dp[i - 1] + 1;
                res += dp[i];
            }
        }
        
        return res;
    }
}