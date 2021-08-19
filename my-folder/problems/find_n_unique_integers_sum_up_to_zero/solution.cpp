class Solution {
public:
    vector<int> sumZero(int n) {
        vector<int> ans;
        int i;
        if(n == 1) return {0};
        for(i = 1; i <= n/2; i++) {
            ans.push_back(i);
            ans.push_back(-1 * i);
        }
        
        if(n % 2 != 0) {
            ans.push_back(i);
            ans[n - 2] += (-1 * i);
        }
        
        return ans;
    }
};