/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int binarySearch(MountainArray &mountainArr, int target, int peak, int n) {
        int low = 0,high = peak - 1;
        // Array Order :: Increasing
        while (low <= high) {
            int mid = (low + high) / 2;
            int curr = mountainArr.get(mid);
            if (curr == target) return mid;
            else if (curr > target) high = mid - 1;
            else low = mid + 1;
        }

        low = peak +1, high = n - 1;
        // Array order :: decreasing
        while (low <= high) {
            int mid = (low + high) / 2;
            int curr = mountainArr.get(mid);
            if (curr == target) return mid;
            else if (curr > target) low = mid + 1;
            else high = mid - 1;
        }

        return -1;
    }
    
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int start = 1;
        int end = n - 2;
        
        int peak = 1;
        
        while(start <= end) {
            int mid = start + (end - start)/2;
            int curr = mountainArr.get(mid);
            int prev = mountainArr.get(mid - 1);
            int next = mountainArr.get(mid + 1);
            if(curr > prev and curr > next) {
                if(curr == target) return mid;
                peak = mid;
                break;
            }
            else if(next > curr) start = mid + 1;
            else end = mid - 1;
        }
        
        return binarySearch(mountainArr, target, peak, n);
    }
};