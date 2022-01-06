class Solution {
private:
    void dfs(int i, int j, vector<vector<char>> &arr, vector<vector<bool>> &visited) {
        if (i < 0 or j < 0
                or i == arr.size()
                or j == arr[0].size()
                or visited[i][j] == true
                or arr[i][j] == '0')
            return;

        visited[i][j] = true;
        dfs(i + 1, j, arr, visited);
        dfs(i, j + 1, arr, visited);
        dfs(i - 1, j, arr, visited);
        dfs(i, j - 1, arr, visited);
    }
public:
    int numIslands(vector<vector<char>>& arr) {
        int res = 0;
        vector<vector<bool>> visited(arr.size(), vector<bool>(arr[0].size(), false));
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[0].size(); j++) {
                if (!visited[i][j] and arr[i][j] == '1') {
                    res++;
                    dfs(i, j, arr, visited);
                }
            }
        }
        return res;
    }
};