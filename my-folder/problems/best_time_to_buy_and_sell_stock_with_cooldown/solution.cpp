class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxProfit = 0;
        int bsp = -arr[0], ssp = 0, csp = 0;

        for (int i = 1; i < arr.size(); i++) {
            int nbsp = max(bsp, csp - arr[i]);
            int nssp = max(ssp, bsp + arr[i]);
            int ncsp = max(csp, ssp);

            bsp = nbsp;
            ssp = nssp;
            csp = ncsp;
        }

        csp = max(csp, ssp);

        return csp;
    }
};