class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int n = nums.size();
        int cnt = 0;
        int hashmap[101] = {0};
        
        for(int i = 0; i < n; i++) {
            hashmap[nums[i]]++;
        }
        
        for(int i = 0; i < 101; i++) {
            cnt += (hashmap[i] * (hashmap[i] - 1)) / 2;
        }
        
        return cnt;
    }
};