class Solution {
    public int numberOfArithmeticSlices(int[] nums) {
        int n = nums.length;
        int dp = 0;
        int res = 0;
        
        for(int i = 1; i < n - 1; i++) {
            int prev = nums[i - 1];
            int curr = nums[i];
            int next = nums[i + 1];
            
            if(curr - prev == next - curr) {
                dp += 1;
                res += dp;
            } else {
                dp = 0;
            }
        }
        
        return res;
    }
}