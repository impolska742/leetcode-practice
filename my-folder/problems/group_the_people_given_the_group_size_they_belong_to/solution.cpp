class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
        vector<vector<int>> ans;
        unordered_map<int, vector<int>> umap;
        int n = groupSizes.size();
        for(int i = 0; i < n; i++) {
            umap[groupSizes[i]].push_back(i);
        }
        for(auto it : umap) {
            vector<int> temp;
            int curr = 0;
            for(int i = 0; i < it.second.size(); i++) {
                if(curr < it.first) {
                    temp.push_back(it.second[i]);
                    curr++;
                } else {
                    ans.push_back(temp);
                    temp.clear();
                    curr = 1;
                    temp.push_back(it.second[i]);
                }
            }
            if(temp.size() > 0) ans.push_back(temp);
        }
        return ans;
    }
};