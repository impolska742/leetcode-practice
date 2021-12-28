class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int maxProfit = 0;
        for (int i = 0; i < arr.size() - 1; i++) {
            if (arr[i] < arr[i + 1])
                maxProfit += arr[i + 1] - arr[i];
        }
        return maxProfit;
    }
};