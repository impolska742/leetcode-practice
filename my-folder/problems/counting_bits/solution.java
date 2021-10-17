class Solution {
    public boolean isPowerOfTwo(int n) {
        if(n == 0) return false;
        return (int)(Math.ceil((Math.log(n) / Math.log(2)))) == 
       (int)(Math.floor(((Math.log(n) / Math.log(2)))));
    }
    
    public int[] countBits(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 0;
        
        if(n == 1) dp[1] = 1;
        if(n > 1) dp[1] = dp[2] = 1;
        
        for(int i = 3; i <= n; i++) {
            if(i % 2 != 0) {
                dp[i] = dp[i - 1] + 1;
            } else {
                dp[i] = dp[i / 2];
            }
        }
        
        return dp;
    }
}