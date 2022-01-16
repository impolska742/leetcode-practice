class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> ans;
        int n = s.length();
        int i;
        for(i = 0; i + k < n; i += k) {
            ans.push_back(s.substr(i, k));
        }
        string last = "";
        for (int count = 0; count < k; count++) {
            if (i + count < n)
                last += s[i + count];
            else
                last += fill;
        }
        ans.push_back(last);
        return ans;
    }
};