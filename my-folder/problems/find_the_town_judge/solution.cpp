class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trusts) {
        if(n == 1) return 1;
        unordered_map<int, int> mp;
        unordered_set<int> sure;
        for(auto trust : trusts) {
            mp[trust[1]]++;
            sure.insert(trust[0]);
        }
        
        for(auto it : mp) {
            if(it.second == n - 1 and sure.find(it.first) == sure.end()) {
                return it.first;
            }
        }
        return -1;
    }
};