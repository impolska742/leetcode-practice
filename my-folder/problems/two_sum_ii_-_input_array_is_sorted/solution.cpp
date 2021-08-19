class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        int low = 0, high = n - 1;
        while(arr[low] + arr[high] != target) {
            if(arr[low] + arr[high] < target) low++;
            else high--;
        }
        
        return {low + 1, high + 1};
    }
};