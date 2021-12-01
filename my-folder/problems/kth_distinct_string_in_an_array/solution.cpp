class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        unordered_map<string, int> mp;
        int count = 0;
        for(auto string : arr) {
            mp[string]++;
        }
        
        vector<string> yes;
        for(auto string : arr) {
            if(mp[string] == 1) {
                yes.push_back(string);
            }
        }
        
        if(yes.size() < k) return "";
        else return yes[k - 1];
    }
};