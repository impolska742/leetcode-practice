class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        vector<int> ans;
        int i, n;
        i = 0;
        n = nums.size();
        while(i < n) {
            int correct = nums[i] - 1;
            if(nums[i] != nums[correct]) swap(nums[i], nums[correct]);
            else i++;
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] - 1 != i) {
                ans.push_back(nums[i]);
                ans.push_back(i + 1);
                break;
            }
        }
        
        return ans;
    }
};