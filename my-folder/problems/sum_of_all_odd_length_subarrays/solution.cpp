class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int ans = 0;
        for(int s = 0; s < n; s++) {
            for(int e = s; e < n; e++) {
                if((e - s) % 2 == 0) {
                    for(int i = s; i <= e; i++) ans += arr[i];
                }
            }
        }
        
        return ans;
    }
};