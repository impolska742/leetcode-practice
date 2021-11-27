class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n <= 1) return n;
        int res = 0;
        unordered_set<int> s;
        for(int i = 0; i < n; i++) {
            s.insert(nums[i]);
        }
        for(int i = 0; i < n; i++) {
            if(s.find(nums[i] - 1) == s.end()) {
                int curr = 1;
                while(s.find(nums[i] + curr) != s.end()) curr++;
                res = max(res, curr);
            }
        }
        
        return res;
    }
};