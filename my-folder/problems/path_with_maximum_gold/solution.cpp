static int dx[] = {0, 1, 0, -1};
static int dy[] = { -1, 0, 1, 0};
class Solution {
public:
    
    int dfs(vector<vector<int>> &grid, vector<vector<bool>> &visited, int row, int col) {
        int N = grid.size();
        int M = grid[0].size();
        
        if (row < 0
                or row >= N
                or col < 0
                or col >= M
                or visited[row][col] == true
                or grid[row][col] == 0) {
            return INT_MIN;
        }

        int maxGold = 0;
        visited[row][col] = true;

        for (int i = 0; i < 4; i++)
            maxGold = max(maxGold, dfs(grid, visited, row + dy[i], col + dx[i]));

        visited[row][col] = false;
        return maxGold + grid[row][col];
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int N = grid.size();
        int M = grid[0].size();
	    vector<vector<bool>> visited(N, vector<bool> (M, false));
        int maxGold = 0;

        for (int row = 0; row < N; row++) {
            for (int col = 0; col < M; col++) {
                if (!visited[row][col] and grid[row][col] != 0) {
                    maxGold = max(maxGold, dfs(grid, visited, row, col));
                }
            }
        }
        
        return maxGold;
    }
};