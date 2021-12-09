class Solution {
public:
    string removeOuterParentheses(string s) {
        string result;
        stack<char> st;
        
        for(auto ch : s) {
            if(st.empty()) st.push(ch);
            else if(st.top() == ch and st.top() == '(') {
                result += ch;
                st.push(ch);
            }
            
            else if(ch == ')') {
                if(st.size() > 1) result += ch;
                st.pop();
            }
        }
        
        return result;
    }
};