class Solution {
public:
    int maxArr(vector<int> &nums) {
        int mx = nums[0];
        for (auto it : nums) mx = max(mx, it);
        return mx;
    }
    int splitArray(vector<int>& nums, int m) {
        // Find Max and Minimum Sum
        // 1. Min Sum = max element in the array
        int minSum = maxArr(nums);
        // 2. Max Sum = total sum of the array
        int maxSum = 0;
        for (auto it : nums) maxSum += it;

        // The sum will lie in this range.
        int start = minSum, end = maxSum;
        // The answer we will get will be minimum of minSum
        int answer = minSum;

        while (start <= end) {
            int mid = start + (end - start) / 2;
            int tempSum = 0;
            int pieces = 1;

            // For every MID we need to check the number of pieces we cut the array into
            // And update the sum if the array can be split or not.
            for (int i = 0; i < nums.size(); i++) {
                if (tempSum + nums[i] <= mid) tempSum += nums[i];

                else {
                    tempSum = nums[i];
                    pieces++;
                }
            }

            // If pieces are less than the required pieces, i.e. m
            // That means the sum is too large.
            // Thus we need to lessen the mid, by putting end = mid;
            // Still the we were able to split the entire array in 'm' or less pieces
            // Thus we will store this answer.
            if (pieces <= m) {
                answer = mid;
                end = mid - 1;
            }

            // If the pieces are larger than 'm'
            // That means the sum is too small
            else start = mid + 1;
        }
        return answer;
    }
};