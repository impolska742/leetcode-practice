class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return 1;
        int mn = *min_element(nums.begin(), nums.end());
        int mx = *max_element(nums.begin(), nums.end());
        int minFromFront = 0, maxFromFront = 0;
        int minFromBack = 0, maxFromBack = 0;
        for(int i = 0; i < n; i++) {
            if(nums[i] != mx) maxFromFront++;
            if(nums[i] == mx) {
                maxFromFront++; 
                break;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(nums[i] != mn) minFromFront++;
            if(nums[i] == mn) {
                minFromFront++; 
                break;
            }
        }
        
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] != mn) minFromBack++;
            if(nums[i] == mn) {
                minFromBack++;
                break;
            }
        }
        
        for(int i = n-1; i >= 0; i--) {
            if(nums[i] != mx) maxFromBack++;
            if(nums[i] == mx) {
                maxFromBack++;
                break;
            }
        }
        
        int ans = min(minFromFront + maxFromBack, maxFromFront + minFromBack);
        ans = min(ans, max(minFromFront, maxFromFront));
        ans = min(ans, max(minFromBack, maxFromBack));
        
        return ans;
    }
};