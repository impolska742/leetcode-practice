class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int cnt = 0;
        
        for(int i = 0; i < m; i++) {
            int start = 0;
            int end = n - 1;
            int ans = -1;
            while(start <= end) {
                int mid = start + (end - start)/2;
                if(grid[i][mid] >= 0) {
                    start = mid + 1;
                } else {
                    ans = mid;
                    end = mid - 1;
                }
            }
            if(ans >= 0) cnt += (n - ans); 
        }
        
        return cnt;
    }
};