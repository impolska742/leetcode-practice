class Solution {
public:
    bool matching(char a, char b) {
        cout << a <<" " << b;
        return ((a == '{' and b == '}') or (a == '[' and b == ']') or (a == '(' and b == ')'));
    }
    
    bool isValid(string str) {
        stack<char> s;
        
        for(int i = 0; i < str.length(); i++) {
            if(str[i] == '(' or str[i] == '{' or str[i] == '[') 
                s.push(str[i]);
            else {
                if(s.empty() == true) return false;
                else if(matching(s.top(), str[i]) == false) return false;
                else s.pop();
            }
        }
        
        if(s.empty() == false) return false;
        return true;
    }
};