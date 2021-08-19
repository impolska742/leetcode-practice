class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        // Naive Solution
        int m = matrix.size();
        int n = matrix[0].size();
        vector<int> ans;

        for(int i = 0; i < m ; i++) {
            for(int j = 0; j < n; j++) {
                int num = matrix[i][j];
                bool flag = true;
                // Check for cols
                for(int k = 0; k < n; k++) {
                    if(matrix[i][k] < num) {
                        flag = false;
                        break;
                    }
                }
                // Check for rows
                if(flag) {
                    for(int k = 0; k < m; k++) {
                        if(matrix[k][j] > num) {
                            flag = false;
                            break;
                        }
                    }
                }
                
                if(flag) ans.push_back(num);
            }
        }
        
        return ans;
    }
};