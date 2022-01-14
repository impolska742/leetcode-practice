class Solution {
private:
    bool checkBipartite(vector<vector<int>>& graph, vector<int> &visited, int src) {
        if(visited[src] == -1)
            visited[src] = 1;
            
        for(auto edge : graph[src]) {
            if(visited[edge] == -1) {
                visited[edge] = 1 - visited[src];
                if(!checkBipartite(graph, visited, edge))
                    return false;
            } else if (visited[edge] == visited[src])
                return false;
        }
        
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited(graph.size(), -1);
        for(int i = 0; i < graph.size(); i++) {
            if(visited[i] == -1 && !checkBipartite(graph, visited, i)) 
                return false;
        }
        return true;
    }
};