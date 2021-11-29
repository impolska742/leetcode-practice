class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        vector<int> ans;
        int n = nums.size();
        if(nums.size() % 2 == 0) {
            if(k > (n / 2) - 1) {
                for(int i = 0; i < nums.size(); i++) 
                    ans.push_back(-1);
                return ans;
            }
        } else {
            if(k > (n/2)) {
                for(int i = 0; i < nums.size(); i++) 
                    ans.push_back(-1);
                return ans;
            }
        }
        for(int i = 0; i < k; i++) ans.push_back(-1);
        long long int sum = 0;
        for(int i = 0; i < 2*k + 1; i++) {
            sum += nums[i];
        }
        ans.push_back(sum / ((2 * k) + 1));
        for(int i = k + 1; i < nums.size(); i++) {
            int lo = i - k;
            int hi = i + k;
            if(lo >= 0 and hi <= nums.size() - 1) {
                sum -= nums[lo - 1];
                sum += nums[hi];
                ans.push_back(sum / ((2 * k) + 1));
            } else ans.push_back(-1);
        }
        
        return ans;
    }
};