class Solution {
public:
    bool containsDuplicate(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> set;
        
        for(int i = 0; i < n; i++) {
            if(set.count(arr[i])) return true;
            set.insert(arr[i]);
        }
        return false;
    }
};