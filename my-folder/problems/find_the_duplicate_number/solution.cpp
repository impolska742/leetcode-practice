class Solution {
public:
    int findDuplicate(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i < n) {
            int correct = arr[i] - 1;
            if(arr[i] != arr[correct]) {
                swap(arr[i], arr[correct]);
            } else {
                i++;
            }
        }
        
        return arr[n - 1];
    }
};