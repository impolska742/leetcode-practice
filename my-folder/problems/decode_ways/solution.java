class Solution {
    public int numDecodings(String s) {
        int[] dp = new int[s.length()];
        int n = s.length();
        if(s.charAt(0) - '0' > 0 && s.charAt(0) - '0' <= 9) dp[0] = 1;
        
        for(int i = 1; i < n; i++) {
            if(s.charAt(i - 1) == '0' && s.charAt(i) == '0')
                dp[i] = 0;
            else if(s.charAt(i - 1) == '0' && s.charAt(i) != '0')
                dp[i] = dp[i - 1];
            else if(s.charAt(i - 1) != '0' && s.charAt(i) == '0') {
                if(s.charAt(i - 1) == '1' || s.charAt(i - 1) == '2') {
                    if(i - 2 >= 0) dp[i] = dp[i - 2];
                    else dp[i] += 1;
                }
            }
            else {
                dp[i] = dp[i - 1];
                if(Integer.parseInt(s.substring(i - 1, i + 1)) <= 26) {
                    if(i - 2 >= 0) dp[i] += dp[i - 2];
                    else dp[i]++;
                }
            }
        }
        
        return dp[s.length() - 1];
    }
}