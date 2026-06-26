class Solution {
public:
    void dfs(vector<vector<char>>&grid, vector<vector<bool>>&vis, int n, int m, int i, int j){
        if(i < 0 || i>=n || j < 0 || j>=m) return;
        if(vis[i][j]) return;
        if(grid[i][j] == '0') return;
        vis[i][j] = 1;

        vector<int> dx {-1, 0, 1, 0};
        vector<int> dy {0, -1, 0, 1};

        for(int k=0; k<4; k++){
            dfs(grid, vis, n, m, i+dx[k], j+dy[k]);
        }
        return;
    }
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool> > vis(n, vector<bool>(m, 0));
        int ans = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!vis[i][j] && grid[i][j] == '1'){
                    dfs(grid, vis, n, m, i, j);
                    ++ans;
                }
            }
        }
        return ans;
    }
};
