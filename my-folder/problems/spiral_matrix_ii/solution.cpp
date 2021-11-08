class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> matrix(n, vector<int>(n));
        int num = 1;
        int mr = matrix.size() - 1;
        int mc = matrix[0].size() - 1;
        vector<int> ans;
        for(int sr = 0, sc = 0; sr <= mr and sc <= mc; sr++, mr--, sc++, mc--) {
            if(sr == mr) {
                for(int j = sc; j <= mc; j++) {
                    matrix[sr][j] = num;
                    num++;
                }
            } 
            else if(sc == mc) {
                for(int i = sr; i <= mr; i++) {
                    matrix[i][sc] = num;
                    num++;
                }
            }
            else {
                for(int j = sc; j <= mc; j++){
                    matrix[sr][j] = num;
                    num++;
                }
                for(int i = sr+1; i <= mr; i++){
                    matrix[i][mc] = num;
                    num++;
                }
                for(int j = mc - 1; j >= sc; j--){
                    matrix[mr][j] = num;
                    num++;
                }
                for(int i = mr - 1; i >= sr + 1; i--){
                    matrix[i][sc] = num;
                    num++;
                }
            }
        }
        return matrix;
    }
};