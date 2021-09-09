class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_map<int, int> umap;
        for(auto it : nums) {
            umap[it]++;
            
            if(umap[it] > 1) return true;
        }
        
        return false;
    }
};