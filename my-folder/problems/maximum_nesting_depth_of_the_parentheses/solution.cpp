class Solution {
public:
    int maxDepth(string str) {
        int mx = 0;
        stack<char> s;
        for(auto ch : str) {
            if(ch == '(') s.push(ch);
            else if(ch == ')') s.pop();
            
            if(s.size() > mx) mx = s.size();
        }
        
        return mx;
    }
};