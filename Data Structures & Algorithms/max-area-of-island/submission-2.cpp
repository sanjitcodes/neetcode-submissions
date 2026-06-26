class Solution {
public:
    int dfs(vector<vector<int>>&grid, int n, int m, int i, int j, int size){
        if(i < 0 || i>=n || j < 0 || j>=m) return 0;
        if(grid[i][j] == 0) return 0;
        grid[i][j] = 0;

        vector<int> dx {-1, 0, 1, 0};
        vector<int> dy {0, -1, 0, 1};

        for(int k=0; k<4; k++){
            size += dfs(grid, n, m, i+dx[k], j+dy[k], 1);
        }
        return size;
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int ans = 0;
        int cur = 0;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(grid[i][j] == 1){
                    cur = dfs(grid, n, m, i, j, 1);
                    ans = max(ans, cur);
                }
            }
        }
        return ans;
    }
};
