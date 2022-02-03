class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if(n == 0 or n == 1) return n;
        map<char, int> freq;
        int l = 0, r = 0;
        int ans = 1;
        for(l = 0; l < n; l++) {
            if(freq[s[l]] != 0) {
                r = max(r, freq[s[l]]);
            }
            freq[s[l]] = l + 1;
            ans = max(ans, l - r + 1);
        }
        return ans;
    }
};