class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int cnt = 0;
        for(auto num : nums) {
            int numOfDigits = floor(log10(num)) + 1;
            if(numOfDigits % 2 == 0) cnt++;
        }
        
        return cnt;
    }
};