class Solution {
public:
    vector<string> res;
    void solve(int idx, int k, string s, string asf) {
        int n = s.size();
        if(k > 4) return;
        
        if(idx == n) {
            if(k == 4 and asf.size() == n + 4) {
                asf.pop_back();
                res.push_back(asf);
            }
            return;
        }
        
        // no
        solve(idx + 1, k, s, asf);
        
        //yes - 1 digit
        solve(idx + 1, k + 1, s, asf + s[idx] + ".");
        
        //yes - 2 digit
        if(idx + 1 < n) {
            int num = (s[idx] - '0') * 10 + (s[idx + 1] - '0');
            string temp = asf + s[idx] + s[idx + 1] + ".";
            if(10 <= num && num <= 99) {
                solve(idx + 2, k + 1, s, temp);
            }
        }
        
        //yes - 3 digit {
        if(idx + 2 < n) {
            int num = (s[idx] - '0') * 100 + (s[idx + 1] - '0') * 10 + (s[idx + 2] - '0');
            string temp = asf + s[idx] + s[idx + 1] + s[idx + 2] + ".";
            if(100 <= num && num <= 255) {
                solve(idx + 3, k + 1, s, temp);
            }
        }
    }        
    vector<string> restoreIpAddresses(string s) {
        solve(0, 0, s, "");
        return res;
    }
};