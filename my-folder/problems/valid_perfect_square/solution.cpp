class Solution {
public:
    bool isPerfectSquare(int num) {
        int start = 0;
        int end = num;
        bool ans = false;
        while(start <= end) {
            long long int mid = start + (end - start)/2;
            if(mid * mid == num) {
                ans = true;
                break;
            }
            else if(mid * mid > num) end = mid - 1;
            else start = mid + 1;
        }
        
        return ans;
    }
};