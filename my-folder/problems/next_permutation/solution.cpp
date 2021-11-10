class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return;
        int index1 = -1;
        for(int i = n - 2; i >= 0; i--) {
            if(nums[i] < nums[i+1]) {
                index1 = i;
                break;
            }
        }
        
        if(index1 < 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        
        int index2 = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(nums[i] > nums[index1]) {
                index2 = i;
                break;
            }
        }
        
        swap(nums[index1], nums[index2]);
        
        int lo = index1 + 1;
        int hi = n - 1;
        while(lo <= hi) {
            swap(nums[lo], nums[hi]);
            lo++;
            hi--;
        }
    }
};