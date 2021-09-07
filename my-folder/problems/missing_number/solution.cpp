class Solution {
public:
    int missingNumber(vector<int>& arr) {
        int n = arr.size();
        int i = 0;
        while(i < n) {
            if(arr[i] < n and arr[i] != arr[arr[i]]) {
                swap(arr[i], arr[arr[i]]);
            } else {
                i++;
            }
        }
        
        for(int i = 0; i < n; i++) {
            if(arr[i] != i) return i;
        }
        
        return n;
    }
};