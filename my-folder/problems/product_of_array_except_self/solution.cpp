#define dbv(v) for(int i = 0; i < v.size(); i++) cout << v[i] << " "; cout << endl;

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        
        vector<int> result(n, 1);
        int from_begin = 1, from_end = 1;
        
        for(int i = 0; i < n; i++) {
            result[i] *= from_begin;
            from_begin *= nums[i];
        }
        
        for(int i = n - 1; i >= 0; i--) {
            result[i] *= from_end;
            from_end *= nums[i];
        }
        
        return result;
    }
};