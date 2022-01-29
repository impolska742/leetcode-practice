class Solution {
public:
    void help(int idx, vector<int> &temp, vector<int> &candidates, 
             vector<vector<int>> &ans, int target) {
        int n = candidates.size();
        if(idx == n) return;
        if(target == 0) {
            ans.push_back(temp);
            return;
        }
        
        for(int i = idx; i < n and target >= candidates[i]; i++) {
            temp.push_back(candidates[i]);
            help(i, temp, candidates, ans, target - candidates[i]);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sort(candidates.begin(), candidates.end());
        help(0, temp, candidates, ans, target);
        return ans;
    }
};