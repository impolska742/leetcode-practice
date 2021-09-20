class Solution {
public:
    int singleNonDuplicate(vector<int>& arr) {
        int start, end, ans;
        int n = arr.size();
        start = ans = 0;
        end = n - 1;
        
        // Corner Cases
        if(arr.size() == 1) return arr[0];
        if(arr[start] != arr[start + 1]) return arr[start];
        if(arr[end] != arr[end - 1]) return arr[end];
        
        while(start < end) {
            int mid = start + (end - start)/2;
            if(mid%2 == 1) mid--;
            
            if(arr[mid] != arr[mid + 1]) end = mid;
            else start = mid + 2;
        }
        
        return arr[start];
    }
};