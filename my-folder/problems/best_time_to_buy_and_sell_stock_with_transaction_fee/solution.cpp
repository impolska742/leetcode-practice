class Solution {
public:
    int maxProfit(vector<int>& arr, int fees) {
        int bsp = -arr[0], ssp = 0;
        for (int i = 1; i < arr.size(); i++) {
            int nbsp = max(bsp, ssp - arr[i]);
            int nssp = max(ssp, bsp + arr[i] - fees);
            bsp = nbsp;
            ssp = nssp;
        }

        return ssp;
    }
};