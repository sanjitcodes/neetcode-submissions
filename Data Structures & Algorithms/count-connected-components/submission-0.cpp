class Solution {
public:
    void dfs(vector<int> adj[], vector<bool> &vis, int cur, int par){
        if(vis[cur]) return;
        vis[cur] = 1;
        for(auto nbr: adj[cur]){
            if(!vis[nbr]){
                dfs(adj, vis, nbr, cur);
            }
        }
        return;
    }
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<int> adj[n];
        for(auto &v: edges){
            adj[v[1]].push_back(v[0]);
            adj[v[0]].push_back(v[1]);
        }
        vector<bool> vis(n, 0);
        int ans = 0;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(adj, vis, i, -1);
                ++ans;
            }
        }
        return ans;
    }
};
