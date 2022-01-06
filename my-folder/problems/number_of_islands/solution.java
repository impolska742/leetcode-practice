class Solution {
    public void dfs(int i, int j, char[][] arr,boolean[][] visited) {
        if (i < 0 || j < 0
                || i == arr.length
                || j == arr[0].length
                || visited[i][j] == true
                || arr[i][j] == '0')
            return;

        visited[i][j] = true;
        dfs(i + 1, j, arr, visited);
        dfs(i, j + 1, arr, visited);
        dfs(i - 1, j, arr, visited);
        dfs(i, j - 1, arr, visited);
    }
    public int numIslands(char[][] arr) {
        int res = 0;
        boolean[][] visited = new boolean[arr.length][arr[0].length];
        for (int i = 0; i < arr.length; i++) {
            for (int j = 0; j < arr[0].length; j++) {
                if (!visited[i][j] && arr[i][j] == '1') {
                    res++;
                    dfs(i, j, arr, visited);
                }
            }
        }
        return res;
    }
}