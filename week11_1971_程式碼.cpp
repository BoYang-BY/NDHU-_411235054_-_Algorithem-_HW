class Solution {
public:
    vector<vector<int>> graph;
    vector<bool> visited;

    bool dfs(int node, int destination) {

        if(node == destination)
            return true;

        visited[node] = true;

        for(int neighbor : graph[node]) {

            if(!visited[neighbor]) {

                if(dfs(neighbor, destination))
                    return true;
            }
        }

        return false;
    }

    bool validPath(int n, vector<vector<int>>& edges,
                   int source, int destination) {

        graph.resize(n);
        visited.resize(n, false);

        for(auto edge : edges) {
            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        return dfs(source, destination);
    }
};