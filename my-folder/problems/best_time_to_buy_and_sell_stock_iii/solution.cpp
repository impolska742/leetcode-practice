class Solution {
public:
    int maxProfit(vector<int>& arr) {
        // Calculating Left DP
        vector<int> dpLeft(arr.size(), 0);
        int leastSoFar = arr.front();
        for (int i = 1; i < arr.size(); i++) {
            leastSoFar = min(leastSoFar, arr[i]);
            int currProfit = arr[i] - leastSoFar;
            dpLeft[i] = max(dpLeft[i - 1], currProfit);
        }

        // Calculating Right DP
        vector<int> dpRight(arr.size(), 0);
        int mostAfterToday = arr.back();
        for (int i = arr.size() - 2; i >= 0; i--) {
            mostAfterToday = max(mostAfterToday, arr[i]);
            int currProfit = mostAfterToday - arr[i];
            dpRight[i] = max(dpRight[i + 1], currProfit);
        }

        int result = dpLeft.front() + dpRight.front();
        for (int i = 1; i < arr.size(); i++) {
            result = max(result, dpLeft[i] + dpRight[i]);
        }

        return result;
    }
};