class Solution {
public:
    vector<vector<int>> paths;
    
    void getAllPaths(vector<bool> &visited, vector<vector<int>> &graph,
                     int curr, vector<int> path, int dest) {
        if(curr == dest) {
            path.push_back(dest);
            paths.push_back(path);
            return;
        }
        
        visited[curr] = true;
        path.push_back(curr);
        
        for(auto edge : graph[curr]) {
            if(visited[edge] == false) {
                getAllPaths(visited, graph, edge, path, dest);
            }
        }
        
        visited[curr] = false;
    }
    
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<bool> visited(graph.size(), false);
        int dest = graph.size() - 1;
        vector<int> path;
        getAllPaths(visited, graph, 0, path, dest);
        return paths;
    }
};