class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int res = 0, curr = 0;
        int n = (int) nums.size();
        for(int i = 1; i < n - 1; i++) {
            if(nums[i] - nums[i - 1] == nums[i + 1] - nums[i]) {
                curr++;
                res += curr;
            } else {
                curr = 0;
            }
        }
        
        return res;
    }
};