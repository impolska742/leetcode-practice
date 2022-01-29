class Solution {
public:
    void help(vector<int>& nums, int idx, map<int, int> &mapp, vector<vector<int>> &ans, vector<int> &temp) {
        int n = nums.size();
        if(idx == n) {
            if(temp.size() == n) {
                ans.push_back(temp);
            }
            return;
        }
        
        for(auto &it : mapp) {
            if(it.second > 0) {
                it.second--;
                temp.push_back(it.first);
                help(nums, idx + 1, mapp, ans, temp);
                temp.pop_back();
                it.second++;
            }    
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        map<int, int> mapp;
        for(auto item : nums)
            mapp[item]++;
        vector<int> temp;
        help(nums, 0, mapp, ans, temp);
        return ans;
    }
};