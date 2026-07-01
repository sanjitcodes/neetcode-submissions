class Solution {
    vector<int> dx{-1, 0, 1, 0};
    vector<int> dy{0, -1, 0, 1};
public:
    void dfs(vector<vector<int> >&heights, vector<vector<bool> >&vis, int n, int m, int i, int j){
        vis[i][j] = 1;
        for(int k=0; k<4; k++){
            int ni = i+dx[k];
            int nj = j+dy[k];
            if(ni >= 0 && ni < n && nj >= 0 && nj < m && !vis[ni][nj] && heights[ni][nj] >= heights[i][j])
                dfs(heights, vis, n, m, ni, nj);
        }
        return;
    }
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        
        vector<vector<bool> > pac(n, vector<bool>(m, 0));
        vector<vector<bool> > atl(n, vector<bool>(m, 0));
                
        for(int i=0; i<n; i++){
            dfs(heights, pac, n, m, i, 0);
            dfs(heights, atl, n, m, i, m-1);
        }
        for(int j=0; j<m; j++){
            dfs(heights, pac, n, m, 0, j);
            dfs(heights, atl, n, m, n-1, j);
        }
        vector<vector<int> > res;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(pac[i][j] && atl[i][j]){
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }
};
