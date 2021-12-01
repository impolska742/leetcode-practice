class Solution {
public:
    string tictactoe(vector<vector<int>>& moves) {
        vector<vector<string>> matrix(3, vector<string>(3, "-"));
        for(int i = 0; i < moves.size(); i++) {
            int xx = moves[i][0];
            int yy = moves[i][1];
            
            if(i % 2 == 0) matrix[xx][yy] = "A";
            else matrix[xx][yy] = "B";
        }
        
        int n = 3;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < n; j++) {
                cout << matrix[i][j];
            }
            cout << endl;
        }
        
        //Check Rows and Cols
        for(int i = 0; i < 3; i++) {
            if(matrix[i][0] == matrix[i][1] and matrix[i][1] == matrix[i][2])
                if(matrix[i][0] != "-")
                    return matrix[i][1];
            
            if(matrix[0][i] == matrix[1][i] and matrix[1][i] == matrix[2][i])
                if(matrix[0][i] != "-")
                    return matrix[1][i];
        }
        
        // Check Diagonals 
        if(matrix[0][0] == matrix[1][1] and matrix[1][1] == matrix[2][2]) 
            if(matrix[0][0] != "-")
                return matrix[0][0];
        if(matrix[0][2] == matrix[1][1] and matrix[1][1] == matrix[2][0]) 
            if(matrix[0][2] != "-")
                return matrix[0][2];
        
        if(moves.size() == 9) return "Draw";
        else return "Pending";
    }
};