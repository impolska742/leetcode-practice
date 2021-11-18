class Solution {
    public int smallestDivisor(int[] nums, int threshold) {
        long low = 1;
        long high = 0;
        for(int num : nums) high += num;
        int ans = -1;
        
        while(low <= high) {
            long mid = low + (high - low)/2;
            long tempSum = 0;
            
            for(int num : nums) {
                tempSum += (num + mid - 1) / mid;
            }
            
            if(tempSum <= threshold) {
                ans = (int) mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        
        return ans;
    }
}