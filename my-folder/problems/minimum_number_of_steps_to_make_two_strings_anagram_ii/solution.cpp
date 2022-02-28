class Solution {
public:
    void debug(map<char, int> mp) {
        for(auto it : mp)
            cout <<it.first << ' ' << it.second << '\n';
        cout << '\n';
    }
    
    int minSteps(string s, string t) {
        int cnt = 0;
        map<char, int> mp;
        
        for(auto ch : s)
            mp[ch]++;
        
        // debug(mp);
        
        map<char, int> mp2;

        for(auto ch : t) {
            if(mp[ch] > 0)
                mp[ch]--;
            else
                mp2[ch]++;
        }
        
        // debug(mp2);
        
        for(auto it : mp)
            cnt += it.second;
        
        for(auto it : mp2)
            cnt += it.second;
        
        return cnt;
    }
};