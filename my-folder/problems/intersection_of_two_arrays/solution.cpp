class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        vector<int> answer;
        set<int> ans;
        int i = 0, j = 0;
        
        while(i <= nums1.size() - 1 and j <= nums2.size() - 1) {
            if(nums1[i] == nums2[j]) {
                ans.insert(nums1[i]);
                i++, j++;
            } 
            else if(nums1[i] < nums2[j]) i++;
            else j++;
        }
        
        for(auto it : ans) {
            answer.push_back(it);
        }
        
        return answer;
    }
};