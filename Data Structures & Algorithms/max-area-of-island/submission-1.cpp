class Solution {
public:
    int dfs(vector<vector<int>>&grid, vector<vector<bool>>&vis, int n, int m, int i, int j, int size){
        if(i < 0 || i>=n || j < 0 || j>=m) return 0;
        if(vis[i][j]) return 0;
        if(grid[i][j] == 0) return 0;
        vis[i][j] = 1;

        vector<int> dx {-1, 0, 1, 0};
        vector<int> dy {0, -1, 0, 1};

        for(int k=0; k<4; k++){
            size += dfs(grid, vis, n, m, i+dx[k], j+dy[k], 1);
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool> > vis(n, vector<bool>(m, 0));
        int ans = 0;
        int cur = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == 1){
                    cur = dfs(grid, vis, n, m, i, j, 1);
                    cout << cur << "\n";
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};
