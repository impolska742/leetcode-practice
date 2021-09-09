class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> umap;
        set<int> answer;
        vector<int> answer1;
        
        for(auto it : nums1) {
            umap[it]++;
        }
        
        for(auto it : nums2) {
            if(umap[it] > 0) answer.insert(it);    
        }   
        
        for(auto it : answer) {
            answer1.push_back(it);
        }
        
        return answer1;
    }
};