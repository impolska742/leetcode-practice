class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int dp = 0;
        int res = 0;
        
        for(int i = 1; i < nums.length - 1; i++) {
            if(nums[i] -  nums[i - 1] == nums[i + 1] - nums[i]) {
                dp += 1;
                res += dp;
            } else {
                dp = 0;
            }
        }
        
        return res;
    }
}