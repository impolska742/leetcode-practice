class Solution {
public:
    char findTheDifference(string s, string t) {
        unordered_map<char, int> s1;
        for(auto ch : s) {
            s1[ch]++;
        }
        unordered_map<char, int> s2;
        for(auto ch : t) {
            s2[ch]++;
        }
        
        for(auto it : s2) {
            if(s1[it.first] != it.second) return it.first;
        }
        
        return 'a';
    }
};