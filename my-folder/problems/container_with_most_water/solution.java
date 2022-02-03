class Solution {
    public int maxArea(int[] height) {
        int res = Math.min(height[0], height[1]);
        int n = height.length;
        int l = 0, r = n - 1;
        
        while(l < r) {
            int len = (r - l);
            int curr_area = Math.min(height[l], height[r]) * len;
            res = Math.max(curr_area, res);
            
            if(height[l] < height[r]) l++;
            else if(height[l] > height[r]) r--;
            else {
                l++; r--;
            }
        }
        
        return res;
    }
}