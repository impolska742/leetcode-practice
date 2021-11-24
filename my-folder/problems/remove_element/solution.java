class Solution {
    public int removeElement(int[] nums, int val) {
        int x = 0, y = 0;
        while(y <= nums.length - 1) {
            if(nums[y] != val) {
                int temp = nums[x];
                nums[x] = nums[y];
                nums[y] = temp;
                x++;
            }
            y++;
        }
        
        return x;
    }
}