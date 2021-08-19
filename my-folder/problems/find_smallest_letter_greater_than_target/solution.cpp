class Solution {
public:
    char nextGreatestLetter(vector<char>& arr, char target) {
        int n = arr.size();
        int lo = 0, hi = n - 1;
        char ans = 'X';
        while(lo <= hi) {
            int mid = (lo + hi)/2;
            if(arr[mid] > target) {
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }

        return arr[lo % n];
    }
};