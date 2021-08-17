class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& arr) {
        int n = arr.size();
        vector<int> ans, hashmap(101, 0);
        int mx = INT_MIN;

        for (int i = 0; i < n; i++) mx = max(arr[i], mx);

        for (int i = 0; i < n; i++) hashmap[arr[i]]++;

        for (int i = 1; i < 101; i++) {
            hashmap[i] = hashmap[i - 1] + hashmap[i];
        }

        for (int i = 0; i < n; i++) {
            int X;
            if (arr[i] - 1 >= 0) X = hashmap[arr[i] - 1];
            else X = 0;
            ans.push_back(X);
        }

        return ans;
    }
};