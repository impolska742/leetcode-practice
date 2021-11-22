class Solution {
public:
    int removeDuplicates(vector<int>& v) {
        int cnt = 0; 
        for(int i = 0; i < v.size(); i++) {
            while(i < v.size() - 1 and v[i] == v[i + 1]) {
                i++;
            }
            swap(v[cnt], v[i]);
            cnt++;
        }
        
        return cnt;
    }
};