class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        stack<char> st;
        for(auto ch : s) {
            if(st.empty()) st.push(ch);
            else if(ch != st.top()) st.push(ch);
            else st.pop();
        }
        
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        
        reverse(res.begin(), res.end());
        return res;
    }
};