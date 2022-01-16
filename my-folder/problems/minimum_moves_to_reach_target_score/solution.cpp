class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int ans = 0;
        // cout << target << " : " << ans << endl;
        while(target > 1 and maxDoubles >= 1) {
            if(target % 2 != 0) {
                target--;
                target /= 2;
                ans += 2;
                maxDoubles--;
            }
            
            else {
                target /= 2;
                ans++;
                maxDoubles--;
            }
            // cout << target << " : " << ans << endl;
        }
        
        if(target != 1) {
            ans += target - 1;
            target = 1;
        }
        // cout << target << " : " << ans << endl;
        // cout << endl;
        return ans;
    }
};