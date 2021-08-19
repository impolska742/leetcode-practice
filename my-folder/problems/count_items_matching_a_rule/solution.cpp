class Solution {
public:
    int countMatches(vector<vector<string>>& items, string ruleKey, string ruleValue) {
        int cnt = 0;
        
        int item_key = 0;
        if(ruleKey == "color") item_key = 1;
        else if(ruleKey == "name") item_key = 2;
        
        for(auto item : items) {
            if(item[item_key] == ruleValue) cnt++;
        }
        
        return cnt;
    }
};