class Solution {
public:
    bool isPalindrome(string s) {
        int lo = 0, hi = s.length() - 1;
        while (lo <= hi) {
            if (s[lo] != s[hi]) return false;
            lo++, hi--;
        }

        return true;
    }
    void help(string s, vector<vector<string>> &ans, vector<string> &asf) {
        if(s.size() == 0) {
            ans.push_back(asf);
            return;
        }
        
        for(int i = 0; i < s.size(); i++) {
            if(isPalindrome(s.substr(0, i + 1))) {
                asf.push_back(s.substr(0, i + 1));
                help(s.substr(i + 1), ans, asf);
                asf.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) {
        vector<vector<string>> ans;
        vector<string> asf;
        help(s, ans, asf);
        return ans;
    }
};