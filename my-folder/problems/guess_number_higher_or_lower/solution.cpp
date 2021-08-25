/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is lower than the guess number
 *			      1 if num is higher than the guess number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution {
public:
    int guessNumber(int n) {
        int ans = 0;
        int start = 1, end = n;
        while(start <= end) {
            int mid = start + (end - start)/2;
            int val = guess(mid);
            if(val == 0) {
                ans = mid;
                break;
            }
            else if(val == 1) start = mid + 1;
            else end = mid - 1;
        }
        return ans;
    }
};