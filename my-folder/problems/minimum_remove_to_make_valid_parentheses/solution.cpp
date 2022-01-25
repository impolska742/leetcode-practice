class Solution {
public:
    string minRemoveToMakeValid(string s) {
        string ans = "";
        stack<pair<char, int>> st;
        for(int i = 0; i < s.size(); i++) {
            char ch = s[i];
            if(ch == '(') st.push({ch, i});
            if(ch == ')') {
                if(st.empty() or st.top().first == ')') st.push({ch, i});
                else if(st.top().first == '(') st.pop();
            }
        }        
        unordered_set<int> indexes;
        while(!st.empty()) indexes.insert(st.top().second), st.pop();
        for(int i = 0; i < s.size(); i++) {
            if(indexes.find(i) == indexes.end()) {
                ans += s[i];
            }
        }
        return ans;
    }
};