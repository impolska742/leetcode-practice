class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {
        int cnt = 0;
        for(auto word : words) {
            int idx = word.find(pref);
            if(idx == 0)
                cnt++;
        }
        return cnt;
    }
};