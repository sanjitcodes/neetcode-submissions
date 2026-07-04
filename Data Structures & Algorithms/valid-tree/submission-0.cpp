class Solution {
public:
    bool dfs(vector<int> adj[], vector<bool>&vis, int cur, int par){
        if(vis[cur]) return 1;
        vis[cur] = 1;
        for(auto nbr: adj[cur]){
            if(!vis[nbr]){
                if(dfs(adj, vis, nbr, cur))
                    return 1;
            }
            else if(nbr != par){
                return 1;
            }
        }
        return 0;
    }
    bool validTree(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &v: edges){
            adj[v[0]].push_back(v[1]);
            adj[v[1]].push_back(v[0]);
        }
        vector<bool> vis(n, 0);
        bool cycle = dfs(adj, vis, 0, -1);
        int visitedNodes = 0;
        for(int i=0; i<n; i++){
            if(vis[i]) ++visitedNodes;
        }
        return (!cycle && visitedNodes == n);
    }
};
