class Solution {
   public:
    vector<bool> visited;
    bool dfs(int node, int par, vector<vector<int>>& adj) {
        visited[node] = true;
        for (auto& neigh : adj[node]) {
            if (neigh == par) continue;
            if (visited[neigh]) return false;
            if (!dfs(neigh, node, adj)) return false;
        }
        return true;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        visited.resize(n, false);
        vector<vector<int>> adj(n);
        for (auto& e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        bool bl=dfs(0,0,adj);
        for(int i=0;i<n;i++){
            if(!visited[i]) return false;
        }

        return bl;
    }
};
