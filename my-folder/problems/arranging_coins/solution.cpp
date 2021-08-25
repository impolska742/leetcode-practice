class Solution {
public:
    int arrangeCoins(int n) {
        int start, end, ans;
        start = ans = 1;
        end = n;
        
        while(start <= end) {
            long long int mid = start + (end - start)/2;
            long long int temp = (mid)*(mid + 1)/2;
            if(temp <= n) {
                ans = mid;
                start = mid + 1;
            }
            else end = mid - 1;
        }
        
        return ans;
    }
};