class Solution {
public:
    int numDecodings(string s) {
        int dp[s.length()];
        memset(dp, 0, sizeof(dp));
        if (s[0] != '0') dp[0] = 1;

        for (int i = 1; i < s.length(); i++) {
            // Zero - Zero
            if (s[i - 1] == '0' && s[i] == '0')
                dp[i] = 0;

            // Zero - NonZero
            else if (s[i - 1] == '0' && s[i] != '0')
                dp[i] = dp[i - 1];

            // NonZero - Zero
            else if (s[i - 1] != '0' && s[i] == '0') {
                if (s[i - 1] == '1' or s[i - 1] == '2') {
                    if (i - 2 >= 0) dp[i] = dp[i - 2];
                    else dp[i] += 1;
                }
            }

            // NonZero - NonZero
            else {
                dp[i] = dp[i - 1];
                int temp = (s[i - 1] - '0') * 10 + s[i] - '0';
                if (temp <= 26) {
                    if (i - 2 >= 0)
                        dp[i] += dp[i - 2];
                    else
                        dp[i]++;
                }
            }
        }

        return dp[s.length() - 1];
    }
};