class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        vector<int> ans;
        while(i < n) {
            int correct = arr[i] - 1;
            if(arr[i] != arr[correct]) {
                swap(arr[i], arr[correct]);
            } else i++;
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] - 1 != i) ans.push_back(i+1);
        }
        
        return ans;
    }
};