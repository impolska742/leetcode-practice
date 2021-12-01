class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_map<int, int> table;
        for(auto num : nums) {
            table[num]++;
        }
        for(auto it : table) {
            if(it.second == nums.size() / 2) return it.first;
        }
        return 0;
    }
};