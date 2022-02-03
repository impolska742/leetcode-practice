class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        set<int> dist;
        int n = s.size();
        vector<int> res(n, 0);
        
        for(int i = 0; i < n; i++) {
            if(s[i] == c) {
                dist.insert(i);
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(s[i] != c) {
                int min_dist = INT_MAX;
                for(auto index : dist) {
                    int dis = abs(i - index);
                    min_dist = min(min_dist, dis);
                }
                res[i] = min_dist;
            }
        }
        
        return res;
    }
};