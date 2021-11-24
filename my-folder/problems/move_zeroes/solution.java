class Solution {
    public void moveZeroes(int[] nums) {
        int cnt = 0;
        for(int i = 0; i < nums.length; i++) {
            if(nums[i] != 0) {
                int temp = nums[cnt];
                nums[cnt] = nums[i];
                nums[i] = temp;
                cnt++;
            } 
        }
    }
}