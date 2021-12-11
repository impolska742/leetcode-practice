class Solution {
public:
    static bool sortByFirst(const pair<int, int> &p1, const pair<int, int> &p2) {
        return p1.first < p2.first;
    }
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        vector<pair<int, int>> vpi;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            vpi.push_back({nums[i], i});
        }
        sort(vpi.begin(), vpi.end(), sortByFirst);
        vector<int> ans;
        int count = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(count == k) {
                break;
            }
            ans.push_back(vpi[i].second);
            count++;
        }
        sort(ans.begin(), ans.end());
        vector<int> res;
        for(auto it : ans) {
            res.push_back(nums[it]);
        }
        
        return res;
    }
};