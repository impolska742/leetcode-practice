class Solution {
    public int[] shuffle(int[] nums, int n) {
        int[] arr = new int[2*n];
        for(int i = 0, x = 0, y = n; i < 2 * n ; i++) {
            if(i % 2 == 0) {
                arr[i] = nums[x];
                x++;
            }
            else {
                arr[i] = nums[y];
                y++;
            }
        }
        
        return arr;
    }
}