class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        int count = 0;
        unordered_set<char> allow;
        for(auto ch : allowed) {
            allow.insert(ch);
        }
        
        for(auto word : words) {
            bool flag = true;
            for(char ch : word) {
                if(allow.find(ch) == allow.end()) {
                    flag = false;
                    break;
                }
            }
            if(flag) count++;
        }
        
        return count;
    }
};