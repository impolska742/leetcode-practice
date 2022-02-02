class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, int> freq, first;
        int min_len = 1, degree = 1;
        
        for(int i = 0; i < nums.size(); i++) {
            int curr = nums[i];
            
            // not visited till now
            if(first.count(curr) == 0) {
                first[curr] = i;
            }
            
            freq[curr]++;
            if(freq[curr] > degree) {
                degree = freq[curr];
                min_len = i - first[curr] + 1;
            } 
            
            else if(freq[curr] == degree) {
                min_len = min(min_len, i - first[curr] + 1);    
            }
        }
        
        return min_len;
    }
};