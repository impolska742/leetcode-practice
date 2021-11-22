class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        if(digits[n - 1] < 9) {
            digits[n - 1]++;
            return digits;
        }
        
        int i = n - 1;
        while(i >= 0 and digits[i] + 1 > 9) {
            digits[i] = 0;
            i--;
        }
        
        // cout << i << endl;
        if(i < 0) {
            vector<int> ans(n + 1);
            ans[0] = 1;
            for(int x = 1; x < n + 1; x++) {
                ans[x] = digits[x - 1];
            }
            return ans;
        }
        
        digits[i]++;
        return digits;
    }
};