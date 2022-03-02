class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for(int i = 2; i <= numRows; i++) {
            vector<int> temp(i);
            temp[0] = 1, temp[i - 1] = 1;
            int k = 0;
        
            for(int j = 1; j < i - 1 and k < i - 1; j++, k++) {
                temp[j] = res.back()[k] + res.back()[k + 1];
            }
            
            res.push_back(temp);
        }
        
        return res;
    }
};