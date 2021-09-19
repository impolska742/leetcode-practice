class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // unordered_map<int, int> umap;
        vector<int> answer;
//         for(auto it : nums1) {
//             umap[it]++;
//         }
        
        unordered_map<int, int> umap2;
        for(auto it : nums2) {
            umap2[it]++;
        }
        
        for(auto it : nums1) {
            if(umap2[it]) {
                umap2[it]--;
                answer.push_back(it);
            }
        }
        
        return answer;
    }
};