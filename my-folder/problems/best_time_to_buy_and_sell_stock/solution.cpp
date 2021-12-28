class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int leastSoFar = INT_MAX;
        int maxProfit = INT_MIN;
        for (int i = 0; i < arr.size(); i++) {
            leastSoFar = min(leastSoFar, arr[i]);
            int todayProfit = arr[i] - leastSoFar;
            maxProfit = max(todayProfit, maxProfit);
        }
        return maxProfit;
    }
};