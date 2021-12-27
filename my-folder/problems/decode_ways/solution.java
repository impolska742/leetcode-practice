class Solution {
    int[] dp = new int[1000];
    public int count(String str, int idx) {
        if (str.length() == 0) {
            return 1;
        }
        
        // memoized
        if(dp[idx] != 0) return dp[idx];
        
        
        int l = 0, r = 0;

        // case :: 1
        char fc = str.charAt(0);
        String ros = str.substring(1);
        if (fc != '0')
            l = count(ros, idx + 1);
        else
            return 0;

        // case :: 2
        if (str.length() > 1) {
            int temp = Integer.parseInt(str.substring(0, 2));
            if (temp >= 1 && temp <= 26) {
                String ros1 = str.substring(2);
                r = count(ros1, idx + 2);
            }
        }

        return dp[idx] = l + r;
    }
    
    public int numDecodings(String s) {
        return count(s, 0);
    }
}