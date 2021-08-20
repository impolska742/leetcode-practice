class Solution {
public:
    int search(vector<int>& arr, int target) {
        int start = 0;
        int end = arr.size() - 1;
        
        while(start <= end) {
            int mid = start + (end - start) / 2;
            if(arr[mid] == target) return mid;
            
            // left part is sorted
            else if(arr[mid] > arr[end]) {
                if(arr[start] <= target and target < arr[mid]) {
                    end = mid - 1;
                }
                
                else {
                    start = mid + 1;
                }
            }
            
            // right part is sorted
            else {
                if(arr[mid] < target and target <= arr[end]) {
                    start = mid + 1;
                }
                
                else {
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};