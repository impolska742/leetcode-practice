class Solution {
public:
    void sortColors(vector<int>& nums) {
        int arr[3] = {0,0,0};
        for(int i = 0 ; i < nums.size() ; i++) {
            arr[nums[i]]++;
        }
        int j = 0;
        for(int i = 0 ; i < 3; i++) {
            while(arr[i] > 0) {
                nums[j] = i;
                arr[i]--;
                j++;
            }
        }
    }
};