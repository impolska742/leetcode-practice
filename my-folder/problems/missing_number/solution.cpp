class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int res = 0;
        int n = nums.size();
        res = n*(n+1)/2;
        for(auto it : nums) res -= it;
        return res;
    }
};