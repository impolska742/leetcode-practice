class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        stack<int> s;
        s.push(0);
        int res = 0;
        for(int i = 1; i < arr.size(); i++) {
            while(!s.empty()) {
                if(arr[i] <= arr[s.top()]) {
                    int tp = s.top();
                    s.pop();
                    int curr = arr[tp] * (s.empty() ? i : (i - s.top() -1));
                    res = max(curr, res);
                } else break;
            }
            s.push(i);
        }
                                      
        while(!s.empty()) {
            int tp = s.top();
            s.pop();
            int curr = arr[tp] * (s.empty() ? arr.size() : (arr.size() - s.top() - 1));
            res = max(curr, res);
        }
        return res;
    }
};