class Solution {
public:
    void help(int idx, vector<int> &temp, vector<int> &nums,
             vector<vector<int>> &ans) {
        int n = nums.size();
        ans.push_back(temp);
        
        for(int i = idx; i < n; i++) {
                temp.push_back(nums[i]);
                help(i + 1, temp, nums, ans);
                temp.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> temp;
        vector<vector<int>> ans;
        help(0, temp, nums, ans);
        return ans;
    }
};