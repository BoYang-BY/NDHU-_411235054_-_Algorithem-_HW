class Solution {
public:

    bool dfs(int node,
             int c,
             vector<vector<int>>& graph,
             vector<int>& color){

        color[node] = c;

        for(int neighbor : graph[node]){

            if(color[neighbor] == c)
                return false;

            if(color[neighbor] == 0){

                if(!dfs(neighbor, -c, graph, color))
                    return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {

        vector<vector<int>> graph(n + 1);

        for(auto &d : dislikes){
            int a = d[0];
            int b = d[1];

            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        vector<int> color(n + 1, 0);

        for(int i = 1; i <= n; i++){

            if(color[i] == 0){

                if(!dfs(i, 1, graph, color))
                    return false;
            }
        }

        return true;
    }
};