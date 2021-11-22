class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        set<int> s;
        for(auto &it : nums) {
            if(s.count(it) == 1) {
                return true;
            }
            
            s.insert(it);
        }
        
        return false;
    }
};