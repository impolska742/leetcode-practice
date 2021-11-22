class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()) return false;
        map<char, int> mp1;
        map<char, int> mp2;
        for(auto ch : s) {
            mp1[ch]++;
        }
        
        for(auto ch : t) {
            mp2[ch]++;
        }
        
        for(auto it : mp1) {
            if(mp1[it.first] != mp2[it.first]) {
                return false;
            }
        }
        return true;
    }
};