class Solution {
public:
    int sum = 0;
    
    void solve(vector<int> &arr, int idx, int temp_sum) {
        if(idx == arr.size()) {
            sum += temp_sum;
            return;
        }  
        
        solve(arr, idx + 1, temp_sum);
        temp_sum = temp_sum ^ arr[idx];
        solve(arr, idx + 1, temp_sum);
    }
    
    int subsetXORSum(vector<int>& arr) {
        solve(arr, 0, 0);
        return sum;
    }
};