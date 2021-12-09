class Solution {
private:
    int stringToNum(string &str) {
        bool negative = false;
        if(str[0] == '-') negative = true;
        int ans = 0, start = 0;
        if(negative) start = 1;    
        for(int i = start; i < str.length(); i++) {
            ans = (ans * 10) + (str[i] - '0');
        }
        
        if(negative) ans = ans * (-1);
        cout << ans << " " << str << "\n";
        return ans;
    }
public:
    int calPoints(vector<string>& ops) {
        stack<int> st;
        
        for(auto it : ops) {
            if(it != "C" and it != "D" and it != "+") {
                st.push(stringToNum(it));
            } else {
                if(it == "C") {
                    st.pop();
                } else if(it == "D") {
                    st.push(st.top() * 2);
                } else {
                    int x = st.top();
                    st.pop();
                    int y = st.top();
                    st.push(x);
                    st.push(x + y);
                }
            }
        }
        
        int sum = 0;
        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }
        
        return sum;
    }
};