class Solution {
public:
    vector<int> searchRange(vector<int>& arr, int target) {
        int first = -1, last = -1;
        int n = arr.size();
        int lo = 0, hi = n - 1;
        
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] == target) {
                first = mid;
                hi = mid - 1;
            } 
            else if(arr[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        
        lo = 0, hi = n - 1;
        while(lo <= hi) {
            int mid = lo + (hi - lo)/2;
            if(arr[mid] == target) {
                last = mid;
                lo = mid + 1;
            } 
            else if(arr[mid] > target) hi = mid - 1;
            else lo = mid + 1;
        }
        
        return {first, last};
    }
};