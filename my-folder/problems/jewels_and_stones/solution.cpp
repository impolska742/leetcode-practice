class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> s;
        for(auto ch : jewels) {
            s.insert(ch);
        }
        int ans = 0;
        for(auto ch : stones) {
            if(s.find(ch) != s.end()) ans++;
        }
        return ans;
    }
};