class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int start = 1;
        int end = n - 2;
        int ans = -1;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            if(arr[mid] > arr[mid + 1] and arr[mid] > arr[mid - 1]) {
                ans = mid;
                break;
            }
                
            else if(arr[mid] < arr[mid + 1]) start = mid + 1;
            else end = mid - 1;
        }
        
        return ans;
    }
};