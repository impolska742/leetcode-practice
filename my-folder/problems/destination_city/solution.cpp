class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        unordered_set<string> sure;
        unordered_set<string> all;
        for(auto path : paths) {
            all.insert(path[0]);
            all.insert(path[1]);
            sure.insert(path[0]);
        }
        
        for(auto city : all) {
            if(sure.find(city) == sure.end()) return city; 
        }
        return "";
    }
};