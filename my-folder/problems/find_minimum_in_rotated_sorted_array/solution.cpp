class Solution {
public:
    int findMin(vector<int>& arr) {
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        // sorted array
        if(arr[start] <=arr[end]) return arr[0];
        while(start < end) {
            int mid = start + (end - start)/2;
            
            if(arr[mid] > arr[mid + 1]) return arr[mid + 1];
            if(arr[mid] < arr[mid - 1] and mid >= 0) return arr[mid];

            if(arr[start] <= arr[mid]) start = mid + 1;
            else end = mid - 1;
        }
        
        
        return -1;
    }
};