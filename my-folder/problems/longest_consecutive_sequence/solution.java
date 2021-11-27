class Solution {
    public int longestConsecutive(int[] nums) {
        if(nums.length <= 1) return nums.length;
        Arrays.sort(nums);
        int answer = 1;
        int cnt = 1;
        for(int i = 1; i < nums.length; i++) {
            if(nums[i] == nums[i - 1]) continue;
            if(nums[i] == nums[i - 1] + 1) {
                cnt++;
                answer = Math.max(answer, cnt);
            } else {
                cnt = 1;
            }
        }
        
        return answer;
    }
}