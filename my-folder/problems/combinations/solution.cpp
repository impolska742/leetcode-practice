class Solution {
public:
    vector<vector<int>> ans;
    void solve(int start, vector<int> arr, int k, int items, vector<int> temp) {
        if(items == k) {
            ans.push_back(temp);
            return;
        }            
        
        for(int i = start + 1; i < arr.size(); i++) {
            temp.push_back(arr[i]);
            solve(i, arr, k, items + 1, temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        for(int i = 1; i <= n; i++)
            arr.push_back(i);
        vector<int> temp;
        solve(-1, arr, k, 0, temp);
        return ans;
    }
};