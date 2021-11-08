class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int mr = matrix.size() - 1;
        int mc = matrix[0].size() - 1;
        vector<int> ans;
        for(int sr = 0, sc = 0; sr <= mr and sc <= mc; sr++, mr--, sc++, mc--) {
            if(sr == mr) {
                for(int j = sc; j <= mc; j++) 
                    ans.push_back(matrix[sr][j]);
            } 
            else if(sc == mc) {
                for(int i = sr; i <= mr; i++) 
                    ans.push_back(matrix[i][sc]);
            }
            else {
                for(int j = sc; j <= mc; j++)
                    ans.push_back(matrix[sr][j]);
                for(int i = sr+1; i <= mr; i++)
                    ans.push_back(matrix[i][mc]);
                for(int j = mc - 1; j >= sc; j--)
                    ans.push_back(matrix[mr][j]);
                for(int i = mr - 1; i >= sr + 1; i--)
                    ans.push_back(matrix[i][sc]);
            }
        }
        
        return ans;
    }
};