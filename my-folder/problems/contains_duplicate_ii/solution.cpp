class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            mp[nums[i]].push_back(i);
        }
        
        for(auto it : mp) {
            cout << it.first << " :: ";
            for(auto index : it.second) {
                cout << index << " ";
            }
            cout << endl;
        }
        for(auto it : mp) {
            if(it.second.size() > 1) {
                for(int i = 0; i < it.second.size(); i++) {
                    for(int j = i + 1; j < it.second.size(); j++) {
                        if(abs(it.second[i] - it.second[j]) <= k)
                            return true;
                    }
                }
            }    
        }
        
        return false; 
    }
};